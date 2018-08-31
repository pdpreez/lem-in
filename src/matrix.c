/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:27:13 by ppreez            #+#    #+#             */
/*   Updated: 2018/08/23 14:27:27 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		count_rooms(t_lemin *data)
{
	int i;
	t_list *start;

	i = 0;
	start = data->rooms;
	while (data->rooms)
	{
		i++;
		data->rooms = data->rooms->next;
	}
	data->rooms = start;
	return (i);
}

void	create_table(t_lemin *data)
{
	int i;
	t_list *start;

	start = data->rooms;
	data->room_count = count_rooms(data);
	i = data->room_count;
	data->tab = (char **)ft_memalloc(sizeof(char *) * i + 1);
	data->tab[0] = ft_strdup(data->start);
	dprintf(2, RED"data->start: %s\n"RESET, data->start);
	dprintf(2, "data->tab[0] = %s\n", data->tab[0]);
	i = 0;
	while (data->rooms)
	{
		data->tab[i] = ft_strdup(ROOM->name);
		dprintf(2, YELLOW"data->tab[i]: %s\n"RESET, ROOM->name);
		i++;
		data->rooms = data->rooms->next;
	}
	dprintf(2, RED"data->end: %s\n"RESET, data->end);
	//data->tab[i] = ft_strdup(data->end);
	dprintf(2, "value of i: %d\n", i);
	//i++;
	//data->tab[i] = ft_strnew(0);
	data->rooms = start;
	/****/
	i = 0;
	while (i < data->room_count)
	{
		dprintf(2, GREEN"data->tab[i]: %s\n"RESET, data->tab[i]);
		i++;
	}
}

void	create_matrix(t_lemin *data)
{
	create_table(data);
	init_matrix(data);
}