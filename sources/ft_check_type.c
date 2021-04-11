/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:37:18 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/12 02:46:14 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_check_type(va_list ap, char *format, int *i, t_conversions *conv)
{
	if ((format[*i] == 'c') ? (*i)++, (conv->type = c) : 0)
		return ;
	if ((format[*i] == 's') ? (*i)++, (conv->type = s) : 0)
		return ;
	if ((format[*i] == 'p') ? (*i)++, (conv->type = p) : 0)
		return ;
	if ((format[*i] == 'd') ? (*i)++, (conv->type = d) : 0)
		return ;
	if ((format[*i] == 'i') ? (*i)++, (conv->type = i) : 0)
		return ;
	if ((format[*i] == 'u') ? (*i)++, (conv->type = u) : 0)
		return ;
	if ((format[*i] == 'x') ? (*i)++, (conv->type = x) : 0)
		return ;
	if ((format[*i] == 'X') ? (*i)++, (conv->type = X) : 0)
		return ;
}
