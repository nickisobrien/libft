/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:11:21 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:53:36 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		parse_wildcards_width(char *str, t_arg *args, va_list ap)
{
	int i;

	i = 0;
	if (str[i] == '*' && str[i + 1] && !ft_isdigit(str[i + 1]))
	{
		args->min_width = va_arg(ap, int);
		if (args->min_width < 0)
			args->has_minus = 1;
		args->min_width = ft_abs(args->min_width);
	}
	else if (str[i] == '*')
		va_arg(ap, int);
	return (0);
}

static int		parse_wildcards_precision(char *str, t_arg *args, va_list ap)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.' && !(args->precision = atoi_edit(&(str[i + 1]))))
		args->precision = -1;
	i++;
	if (str[i] == '*')
	{
		args->precision = va_arg(ap, int);
		if (args->precision == 0)
			args->precision = -1;
		else if (args->precision < 0)
			args->precision = 0;
	}
	return (i - 1);
}

int				parse_args(char *str, t_arg *args, va_list ap)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]) && str[i] != '0')
		i++;
	while (str[i] == '+' || str[i] == '-' || str[i] == '#' ||
		str[i] == ' ' || str[i] == '0' || str[i] == '*')
	{
		if (str[i] == '+')
			args->has_plus = 1;
		else if (str[i] == '-')
			args->has_minus = 1;
		else if (str[i] == ' ')
			args->has_space = 1;
		else if (str[i] == '0' && !ft_isdigit(str[i - 1]))
			args->has_zero = 1;
		else if (str[i] == '#')
			args->has_pound = 1;
		else if (str[i] == '*')
			parse_wildcards_width(str + i, args, ap);
		i++;
	}
	return (i);
}

int				parse_flags(char *str, t_arg *args, va_list ap)
{
	int i;

	i = parse_wildcards_precision(str, args, ap);
	while (str[i] == '.' || ft_isdigit(str[i]))
		i++;
	while (str[i] == 'h' || str[i] == 'l' || str[i] == 'j'
		|| str[i] == 'z' || str[i] == 't' || str[i] == '*')
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
			args->hh = 1 + (i++ * 0);
		else if (str[i] == 'l' && str[i + 1] == 'l')
			args->ll = 1 + (i++ * 0);
		else if (str[i] == 'h')
			args->h = 1;
		else if (str[i] == 'l')
			args->l = 1;
		else if (str[i] == 'j')
			args->j = 1;
		else if (str[i] == 'z')
			args->z = 1;
		else if (str[i] == 't')
			args->t = 1;
		i++;
	}
	return (i);
}
