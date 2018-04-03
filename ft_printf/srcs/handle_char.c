/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:14:54 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/29 19:04:08 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_char(int c, t_arg *args)
{
	char *str;
	char filler;

	if (c == 0)
	{
		filler = args->has_zero ? '0' : ' ';
		if (!args->has_minus)
			while (args->min_width-- > 1)
				add_char(filler, args);
		add_char(0, args);
		if (args->has_minus)
			while (args->min_width-- > 1)
				add_char(filler, args);
	}
	else
	{
		str = ft_strnew(1);
		str[0] = c;
		handle_string(str, args);
		free(str);
	}
}
