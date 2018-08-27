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
# define CURR_PATH ((t_room *)(data->curr_path->content))
# define SHORT_PATH ((t_room *)(data->short_path->content))

typedef struct		s_room
{
	char			*name;
	int				number;
	int				visited_flag;
	t_list			*connections;
}					t_room;

typedef struct		s_lemin
{
	int				ants;
	int				room_count;
	int				**matrix;
	int				shortest_len;
	char			*start;
	char			*end;
	char			**tab;
	t_list			*short_path;
	t_list			*curr_path;
	t_list			*rooms;
	t_list			*args;
}					t_lemin;

int					ant_check(t_lemin *data);
int					error_handler(t_lemin *data);
int					is_room(char *str);
int					start_or_end(t_lemin *data);
int					find_matrix_len(char **str);
int					find_room_flag(t_lemin *data, int index);
char				*save_room_name(t_lemin *data);
char				*room_check(t_lemin *data);
char				**is_connection(t_lemin *data);
void				del_room(t_lemin *data);
void				free_list(t_list *path);
void				is_shortest_path(t_lemin *data);
void				path_finder(t_lemin *data);
void				reset_flags(t_lemin *data);
void				save_room_list(t_lemin *data);
void				init_struct(t_lemin *data);
void				is_comment(t_lemin *data);
void				assign_room_num(t_lemin *data);
void				create_matrix(t_lemin *data);
void				connection_check(t_lemin *data);
void				init_matrix(t_lemin *data);
void				print_matrix(t_lemin *data);
void				save_path(t_lemin *data, char *room_name);

#endif