/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:32:01 by ppreez            #+#    #+#             */
/*   Updated: 2018/08/22 09:57:39 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		is_ant_nbr(t_lemin *data)
{
	int	i;
	int	len;
	char *str;

	i = 0;
	str = (char *)data->args->content;
	len = ft_strlen((char *)data->args->content);
	while (ft_isdigit(str[i]))
		i++;
	return (i == len);
}

int		ant_check(t_lemin *data)
{
	long temp;

	if (is_ant_nbr(data))
	{
		temp = ft_atol((char *)data->args->content);
		if (temp > MAXINT || temp < MININT)
			return (0);
		data->ants = temp;
	}
	else
	{
		ft_debug(1, "Error: Invalid amount of ants", 'R');
		return (0);
	}
	return (1);
}

int		is_room(char *str)
{
	int i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	return (str[i] == ' ');
}

char	*save_room_name(t_lemin *data)
{
	int		i;
	char	*str;
	char	*new;

	i = 0;
	str = (char *)data->args->content;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	new = ft_strsub(str, 0, i);
	return (new);
}

char	*room_check(t_lemin *data)
{
	int i;
	char *str;

	i = 0;
	str = (char *)data->args->content;
	start_or_end(data);
	if (is_room(str))
		save_room_list(data);
	return (str);
}