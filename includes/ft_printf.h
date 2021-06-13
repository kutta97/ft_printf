/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:08:43 by hyyang            #+#    #+#             */
/*   Updated: 2021/06/13 20:59:24 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define TYPE "cspdiuxX%"

typedef	struct	s_flags
{
	int			minus;
	int			zero;
}				t_flags;

typedef struct	s_convs
{
	t_flags		flags;
	int			width;
	int			precision;
	int			wildcard;
	char		type;
}				t_convs;

int				ft_printf(const char *format, ...);
int				ft_putchar(int c);
void			ft_init_conversions(t_convs *conv);
void			ft_set_base_and_sign(int type, int *sign, int *base,
											unsigned long long *nbr);
void			ft_check_flags(char *format, int *i, t_convs *conv);
void			ft_check_width(va_list ap, char *format, int *i,
													t_convs *conv);
void			ft_check_precision(va_list ap, char *format, int *i,
													t_convs *conv);
void			ft_check_type(char *format, int *i, t_convs *conv);
int				ft_print_chr(int c, t_convs *conv);
int				ft_print_str(char *str, t_convs *conv);
int				ft_print_nbr(unsigned long long nbr, t_convs *conv);
int				ft_print_buf(char *buf);

#endif
