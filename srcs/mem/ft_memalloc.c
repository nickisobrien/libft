/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:05:59 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/29 19:04:46 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;
	char *iter;

	if (!(ptr = malloc(size)))
		return (NULL);
	iter = ptr;
	while (size > 0)
	{
		*iter = 0;
		iter++;
		size--;
	}
	return (ptr);
}
