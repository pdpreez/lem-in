/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 09:34:07 by ppreez            #+#    #+#             */
/*   Updated: 2018/08/17 09:34:33 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/lem-in.h"

int main(void)
{
	t_lemin data;

	init_struct(&data);
	error_handler(&data);
	create_matrix(&data);
	while (data.args)
	{
		//dprintf(1, RESET"%s\n", (char *)data.args->content);
		connection_check(&data);
		data.args = data.args->next;
	}
	reset_flags(&data);
	//print_matrix(&data);
	path_finder(&data);
	ft_putendl("");
	return (1);
}