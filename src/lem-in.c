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
	while (!data.args)
	{
		dprintf(2, MAGENTA"%s\n"RESET, (char *)data.args->content);
		data.args = data.args->next;
	}
	ft_putendl("");
	return (1);
}