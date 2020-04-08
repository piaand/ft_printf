/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 09:47:11 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/08 17:33:26 by piaandersin      ###   ########.fr       */
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

static size_t	itoa_convert(long long int value, int base, int *sign)
{
	unsigned int	llmin;
	size_t			u;

	llmin = 0;
	if (value == LLONG_MIN)
	{
		llmin = 1;
		value += llmin;
	}
	if (value < 0 && base == 10)
	{
		*sign = 1;
		value *= -1;
	}
	u = value;
	u += llmin;
	return (u);
}

char			*ft_itoa_base(long long int value, int base)
{
	char	*ascii;
	int		sign;
	size_t	len;
	size_t	u;

	if (base < 2 || base > 16)
		return (NULL);
	sign = 0;
	u = itoa_convert(value, base, &sign);
	len = ft_count_digits(u, base) + sign;
	if (!(ascii = ft_strnew(len)))
		return (NULL);
	if (sign == 1)
		ascii[0] = '-';
	else if (u == 0)
		ascii[0] = '0';
	ascii = ft_write_base(u, len, base, ascii);
	return (ascii);
}
