/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:16:07 by piaandersin       #+#    #+#             */
/*   Updated: 2019/11/11 15:28:13 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds an element *new at the very end of the list, which address to pointer is
** given in **alst.
*/

#include "includes/libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	else if (!*alst)
	{
		*alst = new;
		return ;
	}
	temp = *alst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
