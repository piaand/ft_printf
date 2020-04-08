/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 11:41:39 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/08 17:32:42 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** Returns string representing a number given in variable i converted to base.
*/

static char	get_char(unsigned int mod)
{
	char *base_char[1];
	char c;

	base_char[0] = "0123456789ABCDEF";
	c = base_char[0][mod];
	return (c);
}

char		*ft_write_base(size_t i, size_t len, int base, char *ascii)
{
	unsigned int	mod;
	char			c;

	while (i > 0)
	{
		mod = i % base;
		c = get_char(mod);
		ascii[--len] = c;
		i /= base;
	}
	return (ascii);
}
