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

void	reset_flags(t_lemin *data)
{
	t_list *start;

	start = data->rooms;
	while (data->rooms)
	{
		ROOM->visited_flag = 0;
		data->rooms = data->rooms->next;
	}
	data->rooms = start;
}

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
	printf(YELLOW"\nroom_count: %d\n\n"RESET, data->room_count);
	while (x < data->room_count)
	{
		y = 0;
		dprintf(2, RED"%d  "RESET, x);
		while (y < data->room_count)
		{
			if (data->matrix[x][y] == 0)
				dprintf(2, RED"%d"RESET, data->matrix[x][y]);
			else
				dprintf(2, RESET"%d"RESET, data->matrix[x][y]);
			y++;
		}
		ft_putendl_fd("", 2);
		x++;
	}
}

void	free_list(t_list *path)
{
	t_list	*head;
	t_list	*temp;

	if (path)
	{
		head = path;
		while (path)
		{
			temp = path->next;
			free(path);
			head = temp;
		}
		path = NULL;
	}
}