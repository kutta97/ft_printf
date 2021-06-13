/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 03:17:39 by hyyang            #+#    #+#             */
/*   Updated: 2021/06/13 18:30:04 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_base_set(char type)
{
	if (type == 'd' || type == 'i' || type == 'u')
		return ("0123456789");
	if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

char	*ft_nbrbase_to_buf(unsigned long long nbr, int base, int len,
																t_convs *conv)
{
	char	*buf;

	if (!(buf = malloc((len + 1) * sizeof(char))))
		return (0);
	buf[len] = '\0';
	while (len > 0)
	{
		len--;
		buf[len] = ft_base_set(conv->type)[nbr % base];
		nbr /= base;
	}
	return (buf);
}

int		ft_nbr_len(unsigned long long nbr, int sign, int base, t_convs *conv)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len++;
	while (nbr > 0)
	{
		len++;
		nbr /= base;
	}
	if (len < conv->precision)
		len = conv->precision;
	if (sign < 0)
		len++;
	if ((conv->flags.zero && !conv->flags.minus) && conv->width > 0 
			&& conv->precision < 0 && len < conv->width)
		len = conv->width;
	if (conv->type == 'p')
		len += 2;
	return (len);
}

char	*ft_set_nbrbuf(unsigned long long nbr, t_convs *conv)
{
	int		sign;
	int		base;
	int		len;
	char	*buf;

	sign = 1;
	base = 10;
	if ((conv->type == 'd' || conv->type == 'i') && (int)nbr < 0)
	{
		sign = -1;
		nbr = -nbr;
	}
	if (conv->type == 'x' || conv->type == 'X' || conv->type == 'p')
		base = 16;
	if (conv->wildcard && conv->precision == 0 && nbr == 0)
		return (ft_strdup(""));
	if (!conv->wildcard && conv->precision == 0 && nbr == 0)
	{
		if (conv->type == 'p')
			return (ft_strdup("0x"));
		return (ft_strdup(""));
	}
	len = ft_nbr_len(nbr, sign, base, conv);
	buf = ft_nbrbase_to_buf(nbr, base, len, conv);
	if (sign < 0)
		buf[0] = '-';
	if (conv->type == 'p')
		ft_memcpy(buf, "0x", 2);
	return (buf);
}

int		ft_print_nbr(unsigned long long nbr, t_convs *conv)
{
	int		ncp;
	int		space;
	char	*buf;

	ncp = 0;
	buf = 0;
	space = (conv->flags.zero && !conv->flags.minus) ? '0' : ' ';
	if (conv->flags.zero && conv->precision > -1
								&& conv->precision < conv->width)
		space = ' ';
	if (!(buf = ft_set_nbrbuf(nbr, conv)))
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
