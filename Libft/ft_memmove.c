/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 01:56:10 by hyyang            #+#    #+#             */
/*   Updated: 2021/01/29 17:55:39 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == src || len == 0)
		return (dst);
	d = (unsigned char *)dst + ((dst < src) ? 0 : (len - 1));
	s = (unsigned char *)src + ((dst < src) ? 0 : (len - 1));
	if (dst < src)
	{
		while (len--)
			ft_memcpy(d++, s++, 1);
	}
	else
	{
		while (len--)
			ft_memcpy(d--, s--, 1);
	}
	return (dst);
}
