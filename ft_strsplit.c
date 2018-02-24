/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:04:36 by nobrien           #+#    #+#             */
/*   Updated: 2018/02/23 09:24:37 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		wc;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	wc = ft_get_word_count(s, c);
	if (!(arr = (char **)malloc(sizeof(*arr) * (wc + 1))))
		return (NULL);
	while (wc--)
	{
		while (*s == c && *s != '\0')
			s++;
		arr[i] = ft_strsub(s, 0, ft_word_len(s, c));
		if (arr[i] == NULL)
			return (NULL);
		s = s + ft_word_len(s, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
