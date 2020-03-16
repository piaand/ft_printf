/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:10:16 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:30:48 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** ft_memcpy copies information from one memory address (src) to another (dst)
** the amount of bytes it is given (n).
**
** Restrict keyword lets the compiler know that the pointer passed in there
** isn't pointing to the same place as any other pointers in the arguments.
** If you give this hint to the compiler,
** it can do some more aggressive optimizations without breaking code.
*/

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t		i;
	char		*d;
	char		*s;

	if (!n || dst == src)
		return (dst);
	i = 0;
	d = (char*)dst;
	s = (char*)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
