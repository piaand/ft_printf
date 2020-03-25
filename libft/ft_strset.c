/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 16:33:58 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/25 16:41:33 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Creates a new string with '\0' ending char and sets all the rest char
** with the given char c.
*/

#include "includes/libft.h"

char	*ft_strset(size_t len, char c)
{
	char	*str;

	if (!(str = ft_strnew(len)))
		return (NULL);
	ft_memset(str, c, (len * sizeof(char)));
	return (str);
}
