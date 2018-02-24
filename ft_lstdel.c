/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:19:19 by nobrien           #+#    #+#             */
/*   Updated: 2018/02/22 15:35:01 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *trav;
	t_list *tmp;

	trav = *alst;
	while (trav)
	{
		tmp = trav->next;
		(*del)(trav->content, trav->content_size);
		free(trav);
		trav = tmp;
	}
	*alst = NULL;
}
