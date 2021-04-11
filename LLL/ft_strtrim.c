/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:13:32 by hyyang            #+#    #+#             */
/*   Updated: 2021/01/30 15:46:41 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1 + start);
	if (end)
	{
		while (ft_strchr(set, s1[start + end - 1]))
			end--;
	}
	if (!(str = (char *)malloc((end + 1) * sizeof(char))))
		return (0);
	ft_strlcpy(str, s1 + start, end + 1);
	return (str);
}
