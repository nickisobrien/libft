/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 20:44:48 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/14 20:51:06 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printbits(unsigned char octet)
{
	int z;
	int oct;

	oct = octet;
	z = 128;
	while (z > 0)
	{
		if (oct & z)
			ft_putnbr(1);
		else
			ft_putnbr(0);
		z >>= 1;
	}
}
