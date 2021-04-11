/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:08:43 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/12 03:29:10 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define TYPE "csdiupxX%"

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
	char		type;
}				t_conversions;

int				ft_printf(const char *format, ...);
int				ft_putchar(int c);
void			ft_init_conversions(t_conversions *conv);
void			ft_check_flags(va_list ap, char *format, int *i,
													t_conversions *conv);
void			ft_check_width(va_list ap, char *format, int *i,
													t_conversions *conv);
void			ft_check_precision(va_list ap, char *format, int *i,
													t_conversions *conv);
void			ft_check_type(va_list ap, char *format, int *i,
													t_conversions *conv);
int				ft_print_char(int c, t_conversions *conv);
int				ft_print_string(char *str, t_conversions *conv);
int				ft_print_nbr(unsigned long long nbr, t_conversions *conv);

#endif
