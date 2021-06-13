/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:14:58 by hyyang            #+#    #+#             */
/*   Updated: 2021/06/13 20:57:40 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_print_conversions(va_list ap, t_convs *conv)
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
	return (0);
}

int		ft_analyze_conversions(va_list ap, char *format, int i, t_convs *conv)
{
	int format_start;

	format_start = i++;
	ft_check_flags(format, &i, conv);
	ft_check_width(ap, format, &i, conv);
	ft_check_precision(ap, format, &i, conv);
	ft_check_type(format, &i, conv);
	if (conv->type == 0)
		return (format_start);   
	return (i);
}

int		ft_parse_format(va_list ap, char *format, t_convs *conv)
{
	int				i;
	int				tmp;
	int				num;

	i = 0;
	num = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			tmp = i;
			ft_init_conversions(conv);
			i = ft_analyze_conversions(ap, format, i, conv);
			if (i > tmp)
			{
				num += ft_print_conversions(ap, conv);
				continue ;
			}
		}
		num += ft_putchar(format[i++]);
	}
	return (num);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_convs	*conv;
	int		num;

	if (!(conv = malloc(sizeof(t_convs))))
		return (-1);
	va_start(ap, format);
	num = ft_parse_format(ap, (char *)format, conv);
	va_end(ap);
	free(conv);
	return (num);
}
