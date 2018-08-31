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

	i = 2;
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
	i = count_rooms(data);
	data->room_count = i;
	data->tab = (char **)ft_memalloc(sizeof(char *) * i + 1);
	data->tab[i] = ft_strnew(0);
	data->tab[0] = ft_strdup(data->start);
	i = 0;
	while (data->rooms)
	{
		data->tab[i] = ft_strdup(ROOM->name);
		i++;
		data->rooms = data->rooms->next;
	}
	data->tab[i] = ft_strdup(data->end);
	data->rooms = start;
}

void	create_matrix(t_lemin *data)
{
	create_table(data);
	init_matrix(data);
}