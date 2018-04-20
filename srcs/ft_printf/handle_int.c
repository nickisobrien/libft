/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:12:13 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:53:02 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*handle_precision(char *numstr, t_arg *args)
{
	char *precision;
	char *ptr;

	if (ft_countdigits(numstr) < args->precision)
	{
		precision = ft_strnew(args->precision - ft_countdigits(numstr));
		ft_memset(precision, '0', args->precision - ft_countdigits(numstr));
		ptr = numstr;
		numstr = ft_strjoin(precision, numstr);
		ft_strdel(&ptr);
		ft_strdel(&precision);
	}
	return (numstr);
}

void		handle_int(intmax_t num, t_arg *args, int ct)
{
	char *numstr;

	if (num || args->precision != -1)
		numstr = ft_itoa_edit(num);
	else
		numstr = ft_strnew(0);
	handle_int_string(num, args, ct, numstr);
}

void		handle_int_string(intmax_t num, t_arg *args, int ct, char *numstr)
{
	char *ptr;

	numstr = handle_precision(numstr, args);
	numstr = add_prefix(numstr, args, num, ct);
	numstr = handle_width(numstr, args);
	if (args->has_zero && !args->has_minus && !args->precision)
		replace_zeros(numstr, args->has_space);
	else
		fix_signs(numstr);
	ptr = numstr;
	while (*numstr)
		add_char(*numstr++, args);
	ft_strdel(&ptr);
}
