/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:08:43 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/12 01:29:49 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef enum	e_type
{
	c,
	s,
	p,
	d,
	i,
	u,
	x,
	X
}				t_type;

typedef	struct	s_flags
{
	int			minus;
	int			zero;
}				t_flags;

typedef struct	s_conversions
{
	t_flags		flags;
	int			width;
	int			precision;
	t_type		type;
}				t_conversions;

int				ft_printf(const char *format, ...);
int				ft_putchar(int c);
void			ft_init_conversions(t_conversions *conv);

#endif
