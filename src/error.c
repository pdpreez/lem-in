/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:48:53 by ppreez            #+#    #+#             */
/*   Updated: 2018/08/17 13:13:49 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		data_capture(t_lemin *data)
{
	t_list	*start;

	start = data->args;
	//while (data->args)
	//{
		//dprintf(2, MAGENTA"args: %s\n"RESET, data->args->content);
		if (ant_check(data))
		{
			data->args = data->args->next;
		}
		while (data->args)
		{
			start_or_end(data);
		//if (is_room((char *)data->args->content))
		//{
		//	dprintf(2, YELLOW"args: %s\n"RESET, data->args->content);
			//data->start = room_check(data);
			//data->args = data->args->next;
		//}
		data->args = data->args->next;
		}
	dprintf(2, CYAN"START: %s\n"RESET, data->start);
	dprintf(2, YELLOW"END: %s\n"RESET, data->end);
	dprintf(2, GREEN"ANTS: %d\n"RESET, data->ants);
	data->args = start;
	return (1);
}

void	save_command(t_lemin *data, char *line)
{
	t_list *temp;
	t_list *start;

	start = data->args;
	temp = ft_lstnew(line, sizeof(char) * ft_strlen(line) + 1);
	if (!data->args)
	{
		data->args = temp;
		start = temp;	
	}
	else
	{
		while (data->args->next)
			data->args = data->args->next;
		ft_lstaddend(&data->args, temp);
		data->args = data->args->next;
	}
	data->args = start;
}

int		error_handler(t_lemin *data)
{
	char *line;

	while (get_next_line(0, &line))
	{
		save_command(data, line);
		free(line);
	}
	if (!data_capture(data))
		return (0);
	return (1);
}
