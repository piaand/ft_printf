/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 11:41:39 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/23 11:52:09 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns a string representing a number given in variable i converted to base. 
*/

#include "includes/libft.h"

static char get_char(unsigned int mod)
{
	char base_char[] = "0123456789ABCDEF";
	char c;

	c = base_char[mod];
	return (c);
}

char	*ft_write_base(unsigned int i, unsigned int len, int base, char *ascii)
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
	return(ascii);
}