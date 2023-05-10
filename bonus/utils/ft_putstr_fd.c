/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:21:57 by leborges          #+#    #+#             */
/*   Updated: 2023/04/07 15:55:01 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(1, "STEPS: ", 7);
	write(fd, s, ft_strlenn(s));
	write(fd, "\n", 1);
}
