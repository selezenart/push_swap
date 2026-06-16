/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baserbet <baserbet@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:27:29 by baserbet          #+#    #+#             */
/*   Updated: 2026/04/26 17:14:55 by baserbet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*copy_lst;
	t_list	*next_lst;

	if (!lst || !del)
		return ;
	copy_lst = *lst;
	while (copy_lst != NULL)
	{
		next_lst = copy_lst->next;
		ft_lstdelone(copy_lst, del);
		copy_lst = next_lst;
	}
	*lst = NULL;
}
