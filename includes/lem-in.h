/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:03:07 by ppreez            #+#    #+#             */
/*   Updated: 2018/08/17 10:03:52 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

#include <stdio.h> //REMOVE
#include "../libft/libft.h"

typedef struct		s_lemin
{
	int				ants;
	char			*start;
	char			*end;
	t_list			*rooms;
	t_list			*args;
}					t_lemin;

int					ant_check(t_lemin *data);
int					error_handler(t_lemin *data);
int					is_room(char *str);
int					start_or_end(t_lemin *data);
char				*save_room_name(t_lemin *data);
char				*room_check(t_lemin *data);
void				init_struct(t_lemin *data);

#endif