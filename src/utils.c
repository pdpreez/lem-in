/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:09:22 by ppreez            #+#    #+#             */
/*   Updated: 2018/08/20 14:09:37 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		find_matrix_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_matrix(t_lemin *data)
{
	int x;
	int y;
	
	x = 0;
	printf(YELLOW"room_count: %d\n\n"RESET, data->room_count);
	while (x < data->room_count)
	{
		y = 0;
		while (y < data->room_count)
		{
			dprintf(2, YELLOW"%d"RESET, data->matrix[x][y]);
			y++;
		}
		ft_putendl_fd("", 2);
		x++;
	}
}