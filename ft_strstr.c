/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:05:33 by nobrien           #+#    #+#             */
/*   Updated: 2018/02/22 15:42:57 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *sub;
	char *hsub;

	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		sub = (char *)needle;
		hsub = (char *)haystack;
		while (*sub == *hsub)
		{
			sub++;
			hsub++;
			if (*sub == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
