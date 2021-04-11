/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:14:58 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/11 22:04:11 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_parse_format(va_list ap, char *format)
{
	int	i;
	int ncp;

	i = 0;
	ncp = 0;
	while (format[i])
	{
		ncp += ft_putchar(format[i++]);
		if (i < 0)
		{
			va_arg(ap, char*);
		}
	}
	return ncp;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		num_of_chrs_printed;

	va_start(ap, format);
	num_of_chrs_printed = ft_parse_format(ap, (char *)format);
	va_end(ap);
	return (num_of_chrs_printed);
}
