/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 07:57:46 by hyyang            #+#    #+#             */
/*   Updated: 2021/01/29 18:59:39 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	if (!dst && !src)
		return (0);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (--dstsize && *src)
		*dst++ = *src++;
	if (dst != 0)
		*dst = '\0';
	return (src_len);
}
