/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:56:49 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:40:36 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t i;
	size_t k;
	size_t len;

	len = ft_strlen(dst);
	if (dstsize == 0 || (!dst))
		return (dstsize + ft_strlen(src));
	else
	{
		i = 0;
		while (dst[i] != '\0' && i < (dstsize - 1))
			i++;
		if (dst[i] == '\0' && i < dstsize)
		{
			k = 0;
			while (src[k] != '\0' && i < (dstsize - 1))
				dst[i++] = src[k++];
			dst[i] = '\0';
			return (len + ft_strlen(src));
		}
		else
			return (dstsize + ft_strlen(src));
	}
}
