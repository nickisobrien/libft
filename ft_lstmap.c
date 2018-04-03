/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:21:15 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/29 19:04:44 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*trav;
	t_list	*nl;

	if (!lst)
		return (NULL);
	trav = f(lst);
	nl = trav;
	while (lst->next)
	{
		lst = lst->next;
		if (!(trav->next = f(lst)))
		{
			free(trav->next);
			return (NULL);
		}
		trav = trav->next;
	}
	return (nl);
}
