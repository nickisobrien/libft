/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:06:11 by nobrien           #+#    #+#             */
/*   Updated: 2018/02/22 15:36:51 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*f;

	f = (unsigned char *)from;
	t = (unsigned char *)to;
	i = 0;
	if (from > to)
		while (i < n)
		{
			t[i] = f[i];
			i++;
		}
	else
		while (n--)
			t[n] = f[n];
	return (to);
}
