/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:37:07 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/13 01:07:15 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_check_precision(va_list ap, char *format, int *i, t_convs *conv)
{
	if (format[*i] != '.')
		return ;
	(*i)++;
	if (ft_isdigit(format[*i]))
	{
		int width;

		width = 0;
		while (ft_isdigit(format[*i]))
			width = (width * 10) + format[(*i)++] - '0';
		conv->precision = width;
		return ;
	}
	if (format[*i] == '*')
	{
		conv->precision = va_arg(ap, int);
		(*i)++;
		return ;
	}
}
