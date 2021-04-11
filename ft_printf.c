/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:14:58 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/12 03:05:49 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_print_conversions(va_list ap, t_conversions *conv)
{
	int	ncp;
}

void	ft_analyze_conversions(va_list ap, char *format, int *i, t_conversions *conv)
{
	ft_check_flags(ap, format, i, conv);
	ft_check_width(ap, format, i, conv);
	ft_check_precision(ap, format, i, conv);
	ft_check_type(ap, format, i, conv);
}

int		ft_parse_format(va_list ap, char *format)
{
	int				i;
	int				ncp;
	t_conversions	*conv;

	i = 0;
	ncp = 0;
	if (!(conv = malloc(sizeof(t_conversions))))
		return (-1);
	while (format[i])
	{
		if (format[i++] == '%')
		{
			ft_init_conversions(conv);
			ft_analyze_conversions(ap, format, &i, conv);
			ncp += ft_print_conversions(ap, conv);
		}
		ncp += ft_putchar(format[i++]);
	}
	free(conv);
	return (ncp);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		num_of_chrs_printed;

	va_start(ap, format);
	num_of_chrs_printed = ft_parse_format(ap, (char *)format);
	va_end(ap);
	return (num_of_chrs_printed);
}
