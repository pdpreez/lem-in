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

int		save_start(t_lemin *data)
{
	if (!data->args->next)
	{
		ft_debug(2, "Error: Invalid start room", 'R');
		return (0);
	}
	data->args = data->args->next;
	data->start = save_room_name(data);
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
	return (1);
}

int		start_or_end(t_lemin *data)
{
	char *str;

	str = (char *)data->args->content;
	if (!ft_strcmp("##start", str))
		return (save_start(data));
	else if (!ft_strcmp("##end", str))
		return (save_end(data));
	else if (str[0] == '#' && data->args->next)
		data->args = data->args->next;
	return (0);
}