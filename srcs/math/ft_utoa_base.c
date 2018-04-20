/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:24:14 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/29 19:05:32 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(uintmax_t n, int base)
{
	char		*str;
	uintmax_t	temp;
	int			len;

	len = 1;
	temp = n;
	while (temp /= base)
		len++;
	str = ft_strnew(len);
	len--;
	while (n != 0)
	{
		temp = n % base;
		if (temp < 10)
			str[len] = temp + '0';
		else
			str[len] = temp + 'a' - 10;
		n /= base;
		len--;
	}
	return (str);
}
