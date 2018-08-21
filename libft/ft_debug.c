/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 16:03:37 by ppreez            #+#    #+#             */
/*   Updated: 2018/07/02 17:09:43 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_debug(int fd, char *str, char c)
{
	c = ft_toupper(c);
	if (c == 'M')
		ft_putstr_fd(MAGENTA, fd);
	else if (c == 'C')
		ft_putstr_fd(CYAN, fd);
	else if (c == 'G')
		ft_putstr_fd(GREEN, fd);
	else if (c == 'Y')
		ft_putstr_fd(YELLOW, fd);
	else if (c == 'R')
		ft_putstr_fd(RED, fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(RESET, fd);
}
