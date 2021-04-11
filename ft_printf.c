/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:14:58 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/11 21:46:39 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inlcudes/ft_printf.h"

int	ft_parse_format(va_list ap, char *format)
{
	int	i;
	int ncp;
}

int	ft_printf(const char *format)
{
	va_list	ap;
	int		ncp;

	va_start(ap, format);
	ncp = ft_parse_format(ap, (char *)format);
	va_end(ap);
	return (ncp)
}
