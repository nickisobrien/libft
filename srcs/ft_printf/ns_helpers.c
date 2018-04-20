/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ns_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:08:22 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:53:33 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	atoi_edit(const char *str)
{
	intmax_t	atoi;

	atoi = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\r' || *str == '\f' || *str == '\v' ||
			*str == '-' || *str == '+' || *str == ' ' ||
			*str == '0' || *str == '#' || *str == '*')
		str++;
	while ((*str != '\0') && (*str >= '0') && (*str <= '9'))
	{
		atoi *= 10;
		atoi += *str - '0';
		str++;
	}
	return (atoi);
}

static void	neg(intmax_t *n, int *negative)
{
	if (*n < 0)
		*negative = 1;
}

char		*ft_itoa_edit(intmax_t n)
{
	int			i;
	char		*str;
	intmax_t	tmp;
	int			negative;

	i = 1;
	negative = 0;
	tmp = n;
	neg(&n, &negative);
	while (tmp /= 10)
		i++;
	i += negative;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		str[i] = (char)ft_abs((n % 10)) + '0';
		n /= 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

char		*ft_utoa_edit(uintmax_t n)
{
	int			i;
	char		*str;
	uintmax_t	tmp;

	i = 2;
	tmp = n;
	while (tmp /= 10)
		i++;
	if (!(str = malloc(i)))
		return (NULL);
	str[--i] = '\0';
	while (i--)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
