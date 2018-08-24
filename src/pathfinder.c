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
		return (1);
	while (data->rooms && ft_strcmp(ROOM->name, name))
		data->rooms = data->rooms->next;
	flag = ROOM->visited_flag;
	data->rooms = start;
	return (flag);
}

void	backtracker(int start, t_lemin *data)
{
	int y;

	y = data->room_count;
	printf("room: %s\n", data->tab[start]);
	while (y > 0)
	{
		if (!ft_strcmp(data->end, data->tab[start]))
		{
			printf("found end\n");
			exit(1) ;
		}
		if (data->matrix[start][y] == 1 && !find_room_flag(data, y))
		{	
			set_room_flag(data, y, 1);
			backtracker(y, data);
			// set_room_flag(data, y, 0);
		}
		y--;
	}
}


void	path_finder(t_lemin *data)
{
	backtracker(0, data);
}