/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:08:22 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:53:11 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_ptr(va_list ap, t_arg *args)
{
	void	*ptr;
	char	*str;
	int		i;

	i = 0;
	ptr = va_arg(ap, void *);
	if (ptr == 0 && args->precision != -1)
		str = ft_strdup("0");
	else
		str = ft_utoa_base((uintmax_t)ptr, 16);
	str = hex_precision(str, args);
	ptr = str;
	str = ft_strjoin("0x", str);
	free(ptr);
	str = handle_width(str, args);
	while (str[i])
		add_char(str[i++], args);
	free(str);
}
