/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 04:06:43 by hyyang            #+#    #+#             */
/*   Updated: 2021/01/31 18:15:22 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putdigit(unsigned int n, int fd)
{
	char	c;

	c = (n % 10) + '0';
	if (n >= 10)
		ft_putdigit(n / 10, fd);
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
		ft_putchar_fd('-', fd);
	(n < 0) ? ft_putdigit(-n, fd) : ft_putdigit(n, fd);
}
