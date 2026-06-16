/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:34:45 by baserbet          #+#    #+#             */
/*   Updated: 2026/04/27 14:16:39 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newcontent;
	void	*content;

	if (lst == NULL)
		return (0);
	newlst = 0;
	while (lst != NULL)
	{
		content = (*f)(lst->content);
		newcontent = ft_lstnew(content);
		if (newcontent == NULL)
		{
			del(content);
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, newcontent);
		lst = lst->next;
	}
	return (newlst);
}
