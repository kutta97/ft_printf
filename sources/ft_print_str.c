/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 03:17:24 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/16 19:32:06 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strcpy_to_buf(char *str, int len)
{
	char	*buf;

	if (!(buf = malloc((len + 1) * sizeof(char))))
		return (0);
	if (str == 0)
		ft_memcpy(buf, "(null)", len);
	else
		ft_memcpy(buf, str, len);
	buf[len] = '\0';
	return (buf);
}

char	*ft_set_strbuf(char *str, t_convs *conv)
{
	int		len;
	char	*buf;

	len = (str != 0) ? ft_strlen(str) : ft_strlen("(null)");
	if (conv->precision > 0 && conv->precision < len)
		buf = ft_strcpy_to_buf(str, conv->precision);
	else
		buf = ft_strcpy_to_buf(str, len);
	if (conv->precision == 0)
		ft_bzero(buf, ft_strlen(buf));
	return (buf);
}

int		ft_print_str(char *str, t_convs *conv)
{
	int		ncp;
	int		space;
	char	*buf;

	ncp = 0;
	buf = 0;
	space = (conv->flags.zero && !conv->flags.minus) ? '0' : ' ';
	if (!(buf = ft_set_strbuf(str, conv)))
		return (0);
	if (conv->flags.minus)
		ncp += ft_print_buf(buf);
	conv->width -= ft_strlen(buf);
	while (conv->width-- > 0)
	{
		ft_putchar(space);
		ncp++;
	}
	if (!conv->flags.minus)
		ncp += ft_print_buf(buf);
	free(buf);
	return (ncp);
}
