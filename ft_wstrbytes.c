/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrbytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:15:46 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/29 19:05:35 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrbytes(wchar_t *str)
{
	int i;
	int len;

	len = 0;
	i = 0;
	while (str[i])
	{
		len += ft_wcharbytes(str[i]);
		i++;
	}
	return (len);
}
