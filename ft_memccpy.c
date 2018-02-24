/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:07:45 by nobrien           #+#    #+#             */
/*   Updated: 2018/02/22 15:36:01 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict str1,
		const void *restrict str2, int c, size_t n)
{
	unsigned char	*citer;
	unsigned char	*iter;
	size_t			i;

	i = 0;
	iter = (unsigned char *)str1;
	citer = (unsigned char *)str2;
	while (i < n)
	{
		iter[i] = citer[i];
		if (citer[i] == (unsigned char)c)
			return (str1 + i + 1);
		i++;
	}
	return (NULL);
}
