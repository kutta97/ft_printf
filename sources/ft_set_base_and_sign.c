/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_base_and_sign.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 20:27:45 by hyyang            #+#    #+#             */
/*   Updated: 2021/06/13 20:44:39 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_set_base_and_sign(int type, int *sign, int *base,
													unsigned long long *nbr)
{
	if ((type == 'd' || type == 'i') && (int)*nbr < 0)
	{
		*sign = -1;
		*nbr = -(*nbr);
	}
	if (type == 'x' || type == 'X' || type == 'p')
		*base = 16;
}
