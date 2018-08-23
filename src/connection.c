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

void	connetion_check(t_lemin *data)
{
	
}