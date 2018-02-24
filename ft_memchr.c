/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:09:11 by nobrien           #+#    #+#             */
/*   Updated: 2018/02/22 15:36:10 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*iter;
	int				i;

	i = 0;
	iter = (unsigned char *)str;
	while (n > 0)
	{
		if (*iter == (unsigned char)c)
			return (iter);
		iter++;
		n--;
	}
	return (NULL);
}
