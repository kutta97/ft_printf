/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 03:17:24 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/15 21:56:26 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_set_buf(char *str, t_convs *conv)
{
	int		len;
	char	*buf;
	
	len = ft_strlen(str);
	
	if (conv->precision > 0 && conv->precision < len)
	{
		if (!(buf = malloc((conv->precision + 1) * sizeof(char))))
			return (0);
		ft_memcpy(buf, str, conv->precision);
	}
	else
	{
		if (!(buf = malloc((len + 1) * sizeof(char))))
			return (0);
		ft_memcpy(buf, str, len);
	}
	buf[len] = '\0';
	return (buf);
}

int		ft_print_buf(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
		ft_putchar(buf[i++]);
	return (i);
}

int		ft_print_str(char *str, t_convs *conv)
{
	int		ncp;
	int		space;
	char	*buf;
	
	ncp = 0;
	space = (conv->flags.zero && !conv->flags.minus) ? '0' : ' ';
	if (!(buf = ft_set_buf(str, conv)))
		return (0);
	if (conv->flags.minus)
		ncp += ft_print_buf(buf);
	while (conv->width-- > 1)
	{
		ft_putchar(space);
		ncp++;
	}
	if (!conv->flags.minus)
		ncp += ft_print_buf(buf);
	free(buf);
	return (ncp);
}