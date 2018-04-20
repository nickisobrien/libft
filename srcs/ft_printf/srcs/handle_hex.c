/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 21:11:58 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:52:58 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hex_precision(char *numstr, t_arg *args)
{
	char *precision;
	char *ptr;

	if ((int)ft_strlen(numstr) < args->precision)
	{
		precision = ft_strnew(args->precision - (int)ft_strlen(numstr));
		ft_memset(precision, '0', args->precision - (int)ft_strlen(numstr));
		ptr = numstr;
		numstr = ft_strjoin(precision, numstr);
		ft_strdel(&ptr);
		ft_strdel(&precision);
	}
	return (numstr);
}

void	handle_hex(uintmax_t n, t_arg *args)
{
	char *str;
	char *ptr;

	if (args->precision == -1 && !args->min_width)
		return ;
	if (!n && args->precision != -1)
		str = ft_memset(ft_strnew(1), '0', 1);
	else
		str = ft_utoa_base(n, 16);
	str = hex_precision(str, args);
	if (args->has_pound && n)
	{
		ptr = str;
		str = ft_strjoin("0x", str);
		free(ptr);
	}
	if (ft_upper(args->call))
		ft_strupper(str);
	handle_string(str, args);
	free(str);
}
