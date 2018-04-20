/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 20:26:36 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:53:08 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_octal(uintmax_t num, t_arg *args)
{
	char	*str;

	str = ft_utoa_base(num, 8);
	str = add_prefix(str, args, 1, 0);
	str = handle_precision(str, args);
	str = handle_width(str, args);
	if (str[0])
	{
		handle_string(str, args);
		free(str);
	}
	else if (args->precision != -1)
		add_char('0', args);
}
