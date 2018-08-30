/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:33:57 by ppreez            #+#    #+#             */
/*   Updated: 2018/08/21 10:34:13 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	assign_room_num(t_lemin *data)
{
	int	i;
	t_list *start;

	i = 1;
	start = data->rooms;
	while (data->rooms)
	{
		ROOM->number = i;
		ROOM->visited_flag = 0;
		data->rooms = data->rooms->next;
		i++;
	}
	data->rooms = start;
}

void	is_comment(t_lemin *data)
{
	char *str;

	
	if (data && data->args && data->args->content)
	{
		str = (char *)data->args->content;
		if (str[0] == '#'
			&& (ft_strequ(str, "##start") || ft_strequ(str, "##end")))
			data->args = data->args->next;
	}
}

int		save_start(t_lemin *data)
{
	if (!data->args->next)
	{
		ft_debug(2, "Error: Invalid start room", 'R');
		return (0);
	}
	data->args = data->args->next;
	data->start = save_room_name(data);
	//data->args = data->args->next;
	return (1);
}

int		save_end(t_lemin *data)
{
	if (!data->args->next)
	{
		ft_debug(2, "Error: Invalid end room", 'R');
		return (0);
	}
	data->args = data->args->next;
	data->end = save_room_name(data);
	//data->args = data->args->next;
	return (1);
}

int		start_or_end(t_lemin *data)
{
	char *str;

	if (data && data->args && data->args->content)
	{
		str = (char *)data->args->content;
		if (!ft_strequ("##start", str))
			return (save_start(data));
		else if (!ft_strequ("##end", str))
			return (save_end(data));
		else if (str[0] == '#' && data->args->next)
			data->args = data->args->next;
	}
	return (0);
}