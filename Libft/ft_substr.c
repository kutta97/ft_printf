/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:55:01 by hyyang            #+#    #+#             */
/*   Updated: 2021/02/03 22:00:28 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s || !(sub = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	if (start < ft_strlen(s))
		ft_strlcpy(sub, (char *)s + start, len + 1);
	else
		sub[0] = 0;
	return (sub);
}
