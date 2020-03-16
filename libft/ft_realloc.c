/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:56:30 by piaandersin       #+#    #+#             */
/*   Updated: 2019/11/11 15:33:37 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is not an exact realloc - it takes the old length of the ptr as res
** and uses this information when copying the old values to new memory area.
** Shrinking of size doesn't happen - ptr is returned as it is.
*/

#include "includes/libft.h"

void	*ft_realloc(void *ptr, size_t res, size_t size)
{
	void	*new;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
		return (ft_memalloc(size));
	else if (size <= res)
		return (ptr);
	else
	{
		if (!(new = ft_memalloc(size)))
			return (NULL);
		else
		{
			ft_memcpy(new, ptr, res);
			free(ptr);
		}
		return (new);
	}
}
