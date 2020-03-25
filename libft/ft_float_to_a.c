/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 09:59:12 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/25 14:44:36 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns a float cut from the point of precision in decimals. Precision of 0
** means that ft_float_to_a returns all the integers. Does not round the number.
*/

#include "includes/libft.h"
#include <stdio.h>

static char *write_middle_part(unsigned int zeros)
{
	char *middle;
	size_t len;

	len = 1 + zeros;
	if (!(middle = ft_strnew(len)))
		return (NULL);
	ft_memset(middle, '0', (len * sizeof(char)));
	middle[0] = '.';
	return (middle);
}

static unsigned int write_decimal_part(char **decimal, long double nb, unsigned int precision)
{
	char *decimal_nb;
	unsigned long long int i;
	unsigned int zero_count_on;
	unsigned int count;
	unsigned long long int d;

	zero_count_on = 1;
	count = 0;
	while (precision-- > 0)
	{
		nb *= 10.0;
		d = nb;
		if (d == 0 && zero_count_on == 1)
			count++;
		else
			zero_count_on = 0;
	}
	i = nb;
	if (!(decimal_nb = ft_itoa_base_unsigned(i, 10)))
		*decimal = NULL;
	else
		ft_strcpy(*decimal, decimal_nb);
	ft_strdel(&decimal_nb);
	return(count);
}

static long double	write_integer_part(char **integer, long double nb)
{
	char *integer_part;
	long long i;
	
	i = nb;
	if (!(integer_part = ft_itoa_base(i, 10)))
		*integer = NULL;
	else
		ft_strcpy(*integer, integer_part);
	ft_strdel(&integer_part);
	if (nb < 0)
	{
		nb *= -1;
		i *= -1;
	}
	nb -= i;
	return (nb);
}

static char *join_parts(char *integer, char *middle, char *decimal)
{
	char *tmp;
	char *full_float;

	if ((!integer) || (!middle) || (!decimal))
		return (NULL);
	if (!(tmp = ft_strjoin(integer, middle)))
		return (NULL);
	ft_strdel(&integer);
	ft_strdel(&middle);
	if (!(full_float = ft_strjoin(tmp, decimal)))
		return (NULL);
	ft_strdel(&tmp);
	ft_strdel(&decimal);
	return (full_float);
}

char *ft_float_to_a(long double nb, unsigned int precision)
{
	char			*integer_nb;
	char			*decimal_nb;
	char			*middle_part;
	char			*full_float;
	unsigned int	zero_amount;

	if (!(integer_nb = ft_strnew(ft_count_nbr_length((long long)nb))))
		return (NULL);
	nb = write_integer_part(&integer_nb, nb);
	if (precision != 0)
	{
		if (!(decimal_nb = ft_strnew(precision)))
			return (NULL);
		zero_amount = write_decimal_part(&decimal_nb, nb, precision);
		if (!(middle_part = write_middle_part(zero_amount)))
			return (NULL);
		full_float = join_parts(integer_nb, middle_part, decimal_nb);
		return (full_float);
	}
	else
		return (integer_nb);
}