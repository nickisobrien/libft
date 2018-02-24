/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:49:48 by nobrien           #+#    #+#             */
/*   Updated: 2018/02/22 15:42:36 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *ptr;
	char *mark;

	mark = NULL;
	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == (char)c)
			mark = ptr;
		ptr++;
	}
	if (*ptr == (char)c)
		mark = ptr;
	return (mark);
}
