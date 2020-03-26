/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 10:48:03 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/26 10:51:52 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long double bankers_rounder(long double nb, unsigned int precision)
{
	long double rounder;
	long double d;
	long long j;
	unsigned int i;

	rounder = 0.5;
	if (nb < 0)
		rounder *= -1;
	i = precision;
	while (i-- > 0)
		rounder /= 10;
	d = nb;
	while (precision-- > 0)
		d *= 10;
	j = (long long)d;
	d -=j;
	if (d == 0.5 && (j % 2 == 0))
		return (0);
	else
		return(rounder);
}

static char *write_float(unsigned int precision, va_list args)
{
	double		nb;
	long double	rounder;
	char		*nb_str;

	nb = va_arg(args, double); 
	rounder = bankers_rounder((long double)nb, precision);
	nb += (double)rounder;
	nb_str = ft_float_to_a((double)nb, precision);
	return (nb_str);
}

static char *write_long_double(unsigned int precision, va_list args)
{
	long double		nb;
	long double	rounder;
	char		*nb_str;

	nb = va_arg(args, long double); 
	rounder = bankers_rounder(nb, precision);
	nb += rounder;
	nb_str = ft_float_to_a(nb, precision);
	return (nb_str);
}

int	print_float(t_tag **format, va_list args)
{
	unsigned int precision;
	size_t len;
	char *print_float;

	len = 0;
	if ((*format)->has_value[PRECISION_ON] == '1')
		precision = (*format)->precision;
	else
		precision = 6;
	if ((*format)->has_value[LENGTH_ON] == '1' && (ft_strequ((*format)->length, "0L")))
		print_float = write_long_double(precision, args);
	else
		print_float = write_float(precision, args);
	ft_putstr(print_float);
	len = ft_strlen(print_float);
	return (len);
}
