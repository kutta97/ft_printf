/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:14:58 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/12 03:46:29 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_print_conversions(va_list ap, t_conversions *conv)
{
	if (conv->type == '%')
		return (ft_print_chr('%', conv));
	if (conv->type == 'c')
		return (ft_print_chr(va_arg(ap, int), conv));
	if (conv->type == 's')
		return (ft_print_str(va_arg(ap, char *), conv));
	if (conv->type == 'd' || conv->type == 'i')
		return (ft_print_nbr(va_arg(ap, int), conv));
	if (conv->type == 'x' || conv->type == 'X' || conv->type == 'u')
		return (ft_print_nbr(va_arg(ap, unsigned int), conv));
	if (conv->type == 'p')
		return (ft_print_nbr(va_arg(ap, unsigned long long), conv));
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
