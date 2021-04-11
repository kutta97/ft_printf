/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:54:34 by hyyang            #+#    #+#             */
/*   Updated: 2021/01/31 14:45:07 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_strnumlen(int n)
{
	int len;

	len = (n < 0) ? 2 : 1;
	while ((n /= 10) != 0)
		len++;
	return (len);
}

static unsigned int	ft_abs(int n)
{
	return ((n < 0) ? -n : n);
}

char				*ft_itoa(int n)
{
	int		len;
	char	*result;

	len = ft_strnumlen(n);
	if (!(result = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	if (n == 0)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	result[len--] = '\0';
	while (n != 0)
	{
		result[len--] = (ft_abs(n) % 10) + '0';
		n /= 10;
	}
	if (len > 0)
		result[len] = 1 + '0';
	return (result);
}
