/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:33:33 by piaandersin       #+#    #+#             */
/*   Updated: 2019/11/11 15:28:40 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function returns the amount of list elements that are chained starting from
** pointer address **alst.
*/

#include "includes/libft.h"

size_t	ft_lstlen(t_list **alst)
{
	size_t	i;
	t_list	*temp;

	if (!alst || !(*alst))
		return (0);
	else
	{
		temp = *alst;
		i = 0;
		while (temp)
		{
			i++;
			temp = temp->next;
		}
		return (i);
	}
}
