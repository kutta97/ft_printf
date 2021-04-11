/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:37:18 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/12 02:56:26 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_check_type(va_list ap, char *format, int *i, t_conversions *conv)
{
	if (ft_strchr(TYPE, format[*i]))
		conv->type = format[(*i)++];
}
