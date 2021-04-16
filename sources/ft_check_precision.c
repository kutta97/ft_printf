/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:37:07 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/16 14:55:04 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_digits(char *format, int *i)
{
	int nbr;

	nbr = 0;
	while (ft_isdigit(format[*i]))
		nbr = (nbr * 10) + format[(*i)++] - '0';
	return (nbr);
}

void	ft_check_precision(va_list ap, char *format, int *i, t_convs *conv)
{
	if (format[*i] != '.')
		return ;
	(*i)++;
	conv->precision = 0;
	if (format[*i] == '-')
	{
		conv->flags.minus = 1;
		while (format[*i] == '-')
			(*i)++;
		if (ft_isdigit(format[*i]))
		{
			conv->width = ft_check_digits(format, i);
			return ;
		}
	}
	if (ft_isdigit(format[*i]))
	{
		conv->precision = ft_check_digits(format, i);
		return ;
	}
	if (format[*i] == '*')
	{
		conv->precision = va_arg(ap, int);
		(*i)++;
		return ;
	}
}
