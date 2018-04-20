/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_word_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 09:01:28 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:50:38 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_word_count(char const *s, char c)
{
	int num;

	num = 0;
	while (*s)
	{
		if (*s != c)
		{
			num++;
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (num);
}
