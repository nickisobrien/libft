/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:06:31 by nobrien           #+#    #+#             */
/*   Updated: 2018/02/22 15:39:43 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *new_str;
	char *iter;

	if (!(new_str = ft_strnew(sizeof(char) * (ft_strlen(s1)))))
		return (NULL);
	iter = new_str;
	while (*s1)
	{
		*iter = *s1;
		s1++;
		iter++;
	}
	*iter = '\0';
	return (new_str);
}
