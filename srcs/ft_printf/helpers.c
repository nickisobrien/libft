/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:08:22 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:53:24 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

void	replace_zeros(char *str, int has_space)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && (i || !has_space))
			str[i] = '0';
		i++;
	}
	fix_signs(str);
}

void	fix_signs(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = -1;
	while (str[++i])
		if (str[i] == '+' || str[i] == '-' || str[i] == 'x')
		{
			j = 0;
			while (str[j])
			{
				if (ft_isdigit(str[j]))
				{
					if (str[i] == 'x')
						j++;
					tmp = str[i];
					str[i] = str[j];
					str[j] = tmp;
					break ;
				}
				j++;
			}
		}
}

char	*add_prefix(char *numstr, t_arg *args, int num, int ct)
{
	char *ptr;

	ptr = numstr;
	if (args->has_pound && ft_tolower(args->call) == 'o')
		numstr = ft_strjoin("0", numstr);
	else if (args->has_plus && num >= 0 && ct != 1)
		numstr = ft_strjoin("+", numstr);
	else if (args->has_space && num >= 0 && ct != 1)
		numstr = ft_strjoin(" ", numstr);
	else
		numstr = ft_strdup(numstr);
	ft_strdel(&ptr);
	return (numstr);
}
