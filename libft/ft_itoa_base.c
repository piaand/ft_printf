/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 09:47:11 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/20 12:10:34 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** Returns a character string that represents a conversion of int to base.
** The base is expressed as an integer, from 2 to 16.
** If base is anything else, return null.
** If base is 10 and value is negative, the resulting string is preceded with a
** minus sign (-). With any other base, value is always considered unsigned.
*/

unsigned int	ft_count_digits(unsigned n, int base)
{
	unsigned int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= base;
	}
	return (len);
}

char get_char(unsigned int mod)
{
	char base_char[] = "0123456789ABCDEF";
	char c;

	c = base_char[mod];
	return (c);
}

char	*write_base(unsigned int i, unsigned int len, int base, char *ascii)
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

char	*ft_itoa_base(int value, int base)
{
	char			*ascii;
	long			i;
	int				sign;
	unsigned int	len;
	unsigned int	u;

	if (base < 2 || base > 16)
		return (NULL);
	i = value;
	sign = 0;
	if (i < 0 && base == 10)
	{
		sign = 1;
		i *= -1;
	}
	u = i;
	len = ft_count_digits(u, base);
	len += sign;
	if (!(ascii = ft_strnew(len)))
		return (NULL);
	if (sign == 1)
		ascii[0] = '-';
	else if (u == 0)
		ascii[0] = '0';
	ascii = write_base(u, len, base, ascii);
	return (ascii);
}
