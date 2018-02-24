/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:02:46 by nobrien           #+#    #+#             */
/*   Updated: 2018/02/22 15:36:30 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict str1, const void *restrict str2, size_t n)
{
	char *iter;
	char *citer;

	iter = str1;
	citer = (char *)str2;
	while (n > 0)
	{
		*iter = *citer;
		iter++;
		citer++;
		n--;
	}
	return (str1);
}
