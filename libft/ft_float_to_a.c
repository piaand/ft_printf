/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 09:59:12 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/07 10:35:32 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns a float cut from the point of precision in decimals. Precision of 0
** means that ft_float_to_a returns all the integers. Does not round the number.
*/

#include "includes/libft.h"

static long double	substract_nb(long double nb)
{
	long long	i;

	i = nb;
	if (nb < 0)
	{
		nb *= -1;
		i *= -1;
	}
	nb -= i;
	return (nb);
}

static unsigned int	write_decimal_part(char **decimal, long double nb,
unsigned int precision)
{
	char					*decimal_nb;
	unsigned long long int	i;
	unsigned int			zero_count_on;
	unsigned int			count;
	unsigned long long int	d;

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
		ft_strdel(&(*decimal));
	else
		ft_strcpy(*decimal, decimal_nb);
	ft_strdel(&decimal_nb);
	return (count);
}

static char			*write_integer_part(long double nb)
{
	char		*integer_part;
	long long	i;

	if (nb < 0 && nb > -1)
	{
		if (!(integer_part = ft_strset(2, '0')))
			return (NULL);
		else
			integer_part[0] = '-';
	}
	else
	{
		i = nb;
		if (!(integer_part = ft_itoa_base(i, 10)))
			return (NULL);
	}
	return (integer_part);
}

static char			*join_parts(char *integer, char *middle, char *decimal)
{
	char	*full_float;
	char	*tmp;

	tmp = NULL;
	full_float = NULL;
	if (integer && middle)
		tmp = ft_strjoin(integer, middle);
	ft_strdel(&middle);
	ft_strdel(&integer);
	if (decimal && decimal[0] != '0' && tmp)
	{
		full_float = ft_strjoin(tmp, decimal);
		ft_strdel(&tmp);
	}
	else if (decimal && tmp)
		full_float = tmp;
	else
		ft_strdel(&tmp);
	ft_strdel(&decimal);
	return (full_float);
}

char				*ft_float_to_a(long double nb, unsigned int precision)
{
	char			*integer_nb;
	char			*decimal_nb;
	char			*middle_part;
	char			*full_float;
	unsigned int	zero_amount;

	if (!(integer_nb = write_integer_part(nb)))
		return (NULL);
	nb = substract_nb(nb);
	if (precision != 0)
	{
		if (!(decimal_nb = ft_strnew(precision)))
		{
			ft_strdel(&integer_nb);
			return (NULL);
		}
		zero_amount = write_decimal_part(&decimal_nb, nb, precision);
		if ((middle_part = ft_strset((zero_amount + 1), '0')))
			middle_part[0] = '.';
		full_float = join_parts(integer_nb, middle_part, decimal_nb);
		return (full_float);
	}
	else
		return (integer_nb);
}
