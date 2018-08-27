/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 11:06:25 by ppreez            #+#    #+#             */
/*   Updated: 2018/08/27 11:06:39 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	save_path(t_lemin *data, char *room_name)
{
	t_list	*start;
	t_list	*temp;
	t_room	*path;

	start = data->curr_path;
	path = (t_room *)ft_memalloc(sizeof(t_room));
	temp = ft_lstnew(path, sizeof(t_room));
	if (!data->curr_path)
	{
		data->curr_path = temp;
		start = data->curr_path;
	}
	else
	{
		while (data->curr_path->next)
			data->curr_path = data->curr_path->next;
		ft_lstaddend(&data->curr_path, temp);
		data->curr_path = data->curr_path->next;
	}
	CURR_PATH->name = ft_strdup(room_name);
	data->curr_path = start;
}

void	save_shortest(t_lemin *data)
{
	t_list	*start;
	t_list	*temp;
	t_room	*path;

	start = data->short_path;
	free_path(data);
	path = (t_room *)ft_memalloc(sizeof(t_room));
	temp = ft_lstnew(path, sizeof(t_room));
	if (!data->short_path)
	{
		data->short_path = temp;
		start = data->short_path;
	}
	else
	{
		while (data->short_path->next)
			data->short_path = data->short_path->next;
		ft_lstaddend(&data->short_path, temp);
		data->short_path = data->short_path->next;
	}
	SHORT_PATH->name = ft_strdup(CURR_PATH->name);
	data->short_path = start;
}

void	is_shortest_path(t_lemin *data)
{
	int		len;
	t_list	*start;

	len = 0;
	start = data->curr_path;
	while (data->curr_path)
	{
		data->curr_path = data->curr_path->next;
		len++;	
	}
	if (len < data->shortest_len)
	{
		save_shortest(data);
		data->shortest_len = len;
	}
}