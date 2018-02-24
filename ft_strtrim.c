/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:05:11 by nobrien           #+#    #+#             */
/*   Updated: 2018/02/23 16:30:05 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t	beg;
	size_t	end;
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (*s == '\0')
		return ((char *)s);
	beg = ft_getfirst(s);
	end = ft_getlast(s);
	if (beg > end)
	{
		if (!(str = (ft_strnew(0))))
			return (NULL);
		return (str);
	}
	if (!(str = (ft_strnew(end - beg + 1))))
		return (NULL);
	i = -1;
	while (beg + ++i <= end)
		str[i] = s[beg + i];
	str[i] = '\0';
	return (str);
}
