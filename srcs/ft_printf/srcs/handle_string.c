/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:55:05 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:53:14 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_width(char *str, t_arg *args)
{
	int		dif;
	char	*spaces;
	char	*ptr;

	dif = args->min_width - ft_strlen(str);
	if (dif > 0)
	{
		ptr = str;
		spaces = ft_strnew(dif);
		ft_memset(spaces, ' ', dif);
		if (args->has_minus)
			str = ft_strjoin(str, spaces);
		else
			str = ft_strjoin(spaces, str);
		ft_strdel(&spaces);
		ft_strdel(&ptr);
	}
	return (str);
}

void	handle_string(char *str, t_arg *args)
{
	char	*newstr;
	int		i;

	i = 0;
	if (!str)
		str = "(null)";
	else if (!str)
		str = "";
	str = ft_strdup(str);
	if ((int)ft_strlen(str) > args->precision &&
		args->precision != 0 && args->call == 's')
	{
		if (args->precision == -1)
			args->precision = 0;
		newstr = ft_strnew(args->precision);
		ft_strncpy(newstr, str, args->precision);
		str = newstr;
	}
	str = handle_width(str, args);
	if (args->has_zero && !args->has_minus)
		replace_zeros(str, args->has_space);
	while (str[i])
		add_char(str[i++], args);
	ft_strdel(&str);
}
