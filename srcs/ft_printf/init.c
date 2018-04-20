/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:10:42 by nobrien           #+#    #+#             */
/*   Updated: 2018/04/19 22:53:26 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_arg(t_arg *arg)
{
	arg->has_zero = 0;
	arg->has_minus = 0;
	arg->has_space = 0;
	arg->min_width = 0;
	arg->has_plus = 0;
	arg->has_pound = 0;
	arg->precision = 0;
	arg->hh = 0;
	arg->ll = 0;
	arg->h = 0;
	arg->l = 0;
	arg->j = 0;
	arg->z = 0;
	arg->t = 0;
	arg->call = 0;
}

void	init_arg_world(t_arg *args)
{
	args->types = "dDifFoOuUxXsSpCc%%";
	args->printed_chars = 0;
	args->index = 0;
}
