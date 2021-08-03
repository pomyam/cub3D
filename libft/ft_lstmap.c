/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:11:55 by pyamcha           #+#    #+#             */
/*   Updated: 2020/11/26 19:52:26 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*p;

	if (!lst || !f)
		return (NULL);
	p = ft_lstnew(f(lst->content));
	if (!p)
		return (NULL);
	lst = lst->next;
	tmp = p;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst->content));
		if (!tmp->next)
		{
			ft_lstclear(&p, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (p);
}
