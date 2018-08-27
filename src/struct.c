/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:43:42 by ppreez            #+#    #+#             */
/*   Updated: 2018/08/20 13:43:55 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	init_struct(t_lemin *data)
{
	data->ants = 0;
	data->room_count = 0;
	data->rooms = NULL;
	data->args = NULL;
	data->tab = NULL;
	data->matrix = NULL;
	data->curr_path = NULL;
	data->short_path = NULL;
}

void	init_matrix(t_lemin *data)
{
	int	x;

	x = 0;
	data->matrix = (int **)ft_memalloc(sizeof(int *) * data->room_count);
	while (x < data->room_count)
	{
		data->matrix[x] = (int *)ft_memalloc(sizeof(int) * data->room_count);
		x++;
	}
}