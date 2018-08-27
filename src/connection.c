/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:59:45 by ppreez            #+#    #+#             */
/*   Updated: 2018/08/23 16:59:58 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

char	**is_connection(t_lemin *data)
{
	char *str;
	char **new;

	str = (char *)data->args->content;
	new = ft_strsplit(str, '-');
	if (find_matrix_len(new) <= 1)
		return (NULL);
	return (new);
}

void	clear_start(t_lemin *data)
{
	int x;

	x = 0;
	while (x < data->room_count)
	{
		data->matrix[x][0] = 0;
		x++;
	}
}

void	save_connection(t_lemin *data, char **new)
{
	int x;
	int	y;
	
	x = 0;
	y = 0;
	while (x < data->room_count && ft_strcmp(data->tab[x], new[0]))
		x++;
	while (y < data->room_count && ft_strcmp(data->tab[y], new[1]))
		y++;
	data->matrix[x][y] = 1;
	data->matrix[y][x] = 1;
	clear_start(data);
}

void	connection_check(t_lemin *data)
{
	int x;
	int y;
	char 	**new;

	x = 0;
	y = 0;
 	if ((new = is_connection(data)))
		save_connection(data, new);
}