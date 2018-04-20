/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 12:35:39 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:54:36 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <wchar.h>
# include "libft.h"

# define BUFF_SIZE 124

typedef struct	s_arg
{
	char		buf[BUFF_SIZE];
	int			index;
	char		*types;
	char		call;
	int			has_space;
	int			has_zero;
	int			has_minus;
	int			has_plus;
	int			min_width;
	int			has_pound;
	int			printed_chars;
	int			precision;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			t;
}				t_arg;

void			handle_char(int c, t_arg *args);
void			handle_string(char *str, t_arg *args);
void			handle_int(intmax_t num, t_arg *args, int ct);
void			handle_int_string(intmax_t num, t_arg *args,
	int ct, char *numstr);
void			handle_double(double num);
void			handle_octal(uintmax_t octal, t_arg *args);
void			handle_hex(uintmax_t n, t_arg *args);
void			handle_unsigned_int(intmax_t num, t_arg *args, int ct);
void			handle_wchar(int c, t_arg *args);
void			handle_wstring(wchar_t *str, t_arg *args);
void			handle_ptr(va_list ap, t_arg *args);
void			handle_float(double num, t_arg *args);
void			handle_invalid_converter(t_arg *args);

void			init_arg(t_arg *arg);
void			init_arg_world(t_arg *arg);

void			num_handler(va_list ap, t_arg *args);
void			unum_handler(va_list ap, t_arg *args);
void			str_handler(va_list ap, t_arg *args);
void			char_handler(va_list ap, t_arg *args);

int				ft_printf(char *str, ...);
void			add_char(char c, t_arg *args);

int				parse_args(char *str, t_arg *args, va_list ap);
int				parse_flags(char *str, t_arg *args, va_list ap);

char			*handle_precision(char *numstr, t_arg *args);
char			*handle_width(char *str, t_arg *args);
intmax_t		atoi_edit(const char *str);
int				strchr_edit(const char *str, int c);
char			*ft_itoa_edit(intmax_t n);
void			replace_zeros(char *str, int has_space);
char			*ft_utoa_edit(uintmax_t n);
int				int_strchr(const char *str, int c);
int				ft_countdigits(char *str);
char			*add_prefix(char *numstr, t_arg *args, int num, int ct);
void			fix_signs(char *str);
char			*hex_precision(char *numstr, t_arg *args);

#endif
