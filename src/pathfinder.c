/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:33:46 by ppreez            #+#    #+#             */
/*   Updated: 2018/08/24 11:33:58 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_list	*find_name(t_lemin *data, int index)
{
	t_list	*start;
	char	*name;

	start = data->rooms;
	name = data->tab[index];
	while (ft_strcmp(ROOM->name, name))
		data->rooms = data->rooms->next;
	return (data->rooms);
}

void	set_room_flag(t_lemin *data, int index, int flag)
{
	t_list	*start;
	char	*name;

	start = data->rooms;
	name = data->tab[index];
	if (!ft_strcmp(name, data->end))
		return ;
	while (data->rooms && ft_strcmp(ROOM->name, name))
		data->rooms = data->rooms->next;
	ROOM->visited_flag = flag;
	data->rooms = start;
}

int		find_room_flag(t_lemin *data, int index)
{
	t_list	*start;
	int		flag;
	char	*name;

	flag = 0;
	start = data->rooms;
	name = data->tab[index];
	if (!ft_strcmp(name, data->end))
		return (0);
	while (data->rooms && ft_strcmp(ROOM->name, name))
		data->rooms = data->rooms->next;
	flag = ROOM->visited_flag;
	data->rooms = start;
	return (flag);
}

void	backtracker(int room, t_lemin *data)
{
	int conn;

	conn = data->room_count;
	dprintf(2, CYAN"room: %s\n"RESET, data->tab[room]);
	fflush(stdout);
	while (conn > 0)
	{
		if (!ft_strcmp(data->end, data->tab[room]))
		{
			printf(YELLOW"found end\n"RESET);
			is_shortest_path(data);
			return ;
		}
		else if (data->matrix[room][conn] == 1 && !find_room_flag(data, conn))
		{	
			set_room_flag(data, conn, 1);
			save_path(data, data->tab[conn]);
			backtracker(conn, data);
			set_room_flag(data, conn, 0);
		}
		conn--;
	}
}


void	path_finder(t_lemin *data)
{
	t_list	*start;

	start = data->curr_path;
	backtracker(0, data);
	printf("breaks\n");
	while (data->short_path)
	{
		printf("shortest: %s", SHORT_PATH->name);
		data->short_path = data->short_path->next;
	}
}