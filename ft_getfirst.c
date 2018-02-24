/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:24:47 by nobrien           #+#    #+#             */
/*   Updated: 2018/02/23 16:29:24 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_getfirst(char const *s)
{
	size_t beg;

	beg = 0;
	while ((s[beg] == ' ' || s[beg] == '\n' || s[beg] == '\t') && s[beg])
		beg++;
	return (beg);
}
