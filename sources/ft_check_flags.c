/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:36:13 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/13 01:52:34 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_check_flags(va_list ap, char *format, int *i, t_convs *conv)
{
	while (format[*i] == '-' || format[*i] == '0')
	{
		if (format[*i] == '-')
			conv->flags.minus = 1;
		if (format[*i] == '0')
			conv->flags.zero = 1;
		(*i)++;
	}
}
