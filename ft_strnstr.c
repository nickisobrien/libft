/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:10:02 by nobrien           #+#    #+#             */
/*   Updated: 2018/02/22 15:42:25 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*sub;
	char	*hsub;
	int		plus;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		sub = (char *)needle;
		hsub = (char *)haystack;
		plus = 0;
		while (*sub == *hsub && len - plus > 0)
		{
			plus++;
			sub++;
			hsub++;
			if (*sub == '\0')
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
