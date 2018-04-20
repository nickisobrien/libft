/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:55:05 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:53:21 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		add_to_buf(wchar_t *str, t_arg *args)
{
	int		i;
	int		len;
	char	fill;

	len = args->has_minus ? ft_wstrbytes(str) - args->min_width
	: args->min_width - ft_wstrbytes(str);
	fill = args->has_zero ? '0' : ' ';
	i = 0;
	if (!args->has_minus)
		while (len-- > 0)
			args->buf[args->index++] = fill;
	while (str[i])
		handle_wchar(str[i++], args);
	if (args->has_minus)
		while (len++ < 0)
			args->buf[args->index++] = fill;
}

void			handle_wstring(wchar_t *str, t_arg *args)
{
	wchar_t	*newstr;

	if (!str)
		str = L"(null)";
	else if (ft_wstrlen(str) > args->precision && args->precision != 0)
	{
		if (args->precision == -1)
			args->precision = 0;
		newstr = (wchar_t *)ft_strnew(args->precision);
		ft_strncpy((char *)newstr, (char *)str, args->precision);
		str = newstr;
	}
	add_to_buf(str, args);
}
