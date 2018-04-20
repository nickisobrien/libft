/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_invalid_converter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:18:05 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:53:06 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_invalid_converter(t_arg *args)
{
	char filler;

	filler = args->has_zero ? '0' : ' ';
	if (args->has_minus)
		add_char(args->call, args);
	while (args->min_width-- > 1)
		add_char(filler, args);
	if (!args->has_minus)
		add_char(args->call, args);
}
