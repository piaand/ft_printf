/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:28:11 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:29:11 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned char		*s;
	unsigned char		cc;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (s[i] != cc)
		{
			d[i] = s[i];
			i++;
		}
		else
		{
			d[i] = s[i];
			i++;
			return (&d[i]);
		}
	}
	return (NULL);
}
