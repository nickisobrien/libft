/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 11:37:02 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:52:55 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_float(double num, t_arg *args)
{
	int i;
	int prec;

	if (num < 0)
	{
		add_char('-', args);
		num = -num;
	}
	handle_int((intmax_t)num, args, 0);
	num -= (intmax_t)num - 1;
	add_char('.', args);
	i = 0;
	prec = (args->precision && args->precision != -1) ? args->precision : 6;
	while (i < prec)
	{
		num *= 10;
		add_char(((intmax_t)num % 10) + '0', args);
		i++;
	}
}
