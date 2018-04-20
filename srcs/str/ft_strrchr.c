/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:49:48 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/29 19:05:23 by nobrien          ###   ########.fr       */
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
