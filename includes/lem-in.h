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

# include <stdio.h> //REMOVE
# include "../libft/libft.h"
# define ROOM ((t_room *)(data->rooms->content))

typedef struct		s_room
{
	char			*name;
	int				number;
	int				visited_flag;
}					t_room;

typedef struct		s_lemin
{
	int				ants;
	char			*start;
	char			*end;
	char			**tab;
	t_list			*rooms;
	t_list			*args;
}					t_lemin;

int					ant_check(t_lemin *data);
int					error_handler(t_lemin *data);
int					is_room(char *str);
int					start_or_end(t_lemin *data);
int					find_matrix_len(char **str);
char				*save_room_name(t_lemin *data);
char				*room_check(t_lemin *data);
char				**is_connection(t_lemin *data);
void				save_room_list(t_lemin *data);
void				init_struct(t_lemin *data);
void				is_comment(t_lemin *data);
void				assign_room_num(t_lemin *data);
void				create_matrix(t_lemin *data);
void				connetion_check(t_lemin *data);

#endif