/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:48:05 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:53:18 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_wchar(wchar_t w, t_arg *args)
{
	if (w <= 0x7F)
		add_char(w, args);
	else if (w <= 0x7FF)
	{
		add_char((w >> 6) + 0xC0, args);
		add_char((w & 0x3F) + 0x80, args);
	}
	else if (w <= 0xFFFF)
	{
		add_char((w >> 12) + 0xE0, args);
		add_char(((w >> 6) & 0x3F) + 0x80, args);
		add_char((w & 0x3F) + 0x80, args);
	}
	else if (w <= 0x10FFFF)
	{
		add_char((w >> 18) + 0xF0, args);
		add_char(((w >> 12) & 0x3F) + 0x80, args);
		add_char(((w >> 6) & 0x3F) + 0x80, args);
		add_char((w & 0x3F) + 0x80, args);
	}
}
