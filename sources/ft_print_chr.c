/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 03:17:10 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/15 21:39:05 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_chr(int c, t_convs *conv)
{
	int	ncp;
	int	space;

	ncp = 0;
	space = (conv->flags.zero && !conv->flags.minus) ? '0' : ' ';
	if (conv->flags.minus)
		ft_putchar(c);
	while (conv->width-- > 1)
	{
		ft_putchar(space);
		ncp++;
	}
	if (!conv->flags.minus)
		ft_putchar(c);
	return (ncp + 1);
}
