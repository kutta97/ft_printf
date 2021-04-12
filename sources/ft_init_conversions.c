/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_conversions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 01:20:11 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/13 01:07:13 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init_conversions(t_convs *conv)
{
	conv->flags.minus = 0;
	conv->flags.zero = 0;
	conv->precision = -1;
	conv->width = 0;
	conv->type = 0;
}
