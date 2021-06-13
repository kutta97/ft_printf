/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:36:21 by hyyang            #+#    #+#             */
/*   Updated: 2021/06/13 15:07:01 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

va_list	*ft_check_width(va_list *ap, char *format, int *i, t_convs *conv)
{
	int	width;

	if (ft_isdigit(format[*i]))
	{
		width = 0;
		while (ft_isdigit(format[*i]))
			width = (width * 10) + format[(*i)++] - '0';
		conv->width = width;
		return (ap);
	}
	if (format[*i] == '*')
	{
		conv->width = va_arg(*ap, int);
		(*i)++;
		return (ap);
	}
	return (ap);
}
