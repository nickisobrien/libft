/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 16:21:23 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:54:05 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flush(t_arg *args)
{
	write(1, args->buf, args->index);
	args->printed_chars += args->index;
	args->index = 0;
}

static int	get_handler(va_list ap, char *str, t_arg *args)
{
	int index;

	if (!*str)
		return (0);
	if ((index = int_strchr(args->types, *str)) != -1)
	{
		args->call = *str;
		if (index <= 4)
			num_handler(ap, args);
		else if (index <= 10)
			unum_handler(ap, args);
		else if (index >= 14)
			char_handler(ap, args);
		else if (args->call == 'p')
			handle_ptr(ap, args);
		else if (index >= 11 && index <= 12)
			str_handler(ap, args);
	}
	else
	{
		args->call = *str;
		handle_invalid_converter(args);
	}
	return (1);
}

void		add_char(char c, t_arg *args)
{
	if (args->index + sizeof(c) == BUFF_SIZE)
		flush(args);
	args->buf[args->index] = c;
	args->index += sizeof(c);
}

int			ft_printf(char *str, ...)
{
	va_list	ap;
	t_arg	args;

	va_start(ap, str);
	init_arg_world(&args);
	while (*str)
	{
		if (*str != '%')
		{
			add_char(*str++, &args);
			continue;
		}
		init_arg(&args);
		args.min_width = atoi_edit(++str);
		if (!*str)
			break ;
		str += parse_args(str, &args, ap);
		str += parse_flags(str, &args, ap);
		str += get_handler(ap, str, &args);
	}
	flush(&args);
	va_end(ap);
	return (args.printed_chars);
}
