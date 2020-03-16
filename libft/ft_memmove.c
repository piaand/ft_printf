/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:29:49 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:30:56 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;
	char	*s;
	char	*d;
	size_t	i;

	if (src == dst)
		return (dst);
	s = (char*)src;
	d = (char*)dst;
	i = 0;
	if (!(temp = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		temp[i] = s[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		d[i] = temp[i];
		i++;
	}
	ft_strdel(&temp);
	return (d);
}
