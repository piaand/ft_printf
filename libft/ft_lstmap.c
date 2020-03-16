/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:13:04 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:28:49 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*ptr;
	t_list	*head;

	if (lst == NULL || f == NULL)
		return (NULL);
	ptr = f(lst);
	if (!(new = ft_lstnew(ptr->content, ptr->content_size)))
		return (NULL);
	lst = lst->next;
	head = new;
	while (lst)
	{
		ptr = f(lst);
		if (!(new->next = ft_lstnew(ptr->content, ptr->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
