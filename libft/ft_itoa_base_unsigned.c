/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 11:31:28 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/08 17:27:23 by piaandersin      ###   ########.fr       */
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

char	*ft_itoa_base_unsigned(size_t value, int base)
{
	char	*ascii;
	size_t	len;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_count_digits(value, base);
	if (!(ascii = ft_strnew(len)))
		return (NULL);
	else if (value == 0)
		ascii[0] = '0';
	ascii = ft_write_base(value, len, base, ascii);
	return (ascii);
}
