/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:35:12 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:41:26 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	if (len == 0)
		return (dst);
	else
	{
		i = 0;
		while (i < len && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		while (i < len && dst[i] != '\0')
		{
			dst[i] = '\0';
			i++;
		}
		return (dst);
	}
}
