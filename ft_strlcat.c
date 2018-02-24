/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:09:46 by nobrien           #+#    #+#             */
/*   Updated: 2018/02/22 15:40:38 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dest, const char *restrict src, size_t size)
{
	int		destlen;
	int		n;
	char	*d;
	char	*s;

	d = dest;
	s = (char *)src;
	n = size;
	while (n-- != 0 && *d != '\0')
		d++;
	destlen = d - dest;
	n = size - destlen;
	if (n == 0)
		return (destlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (destlen + (s - src));
}
