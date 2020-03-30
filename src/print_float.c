/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 10:48:03 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/30 15:53:05 by piaandersin      ###   ########.fr       */
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

char *add_decimal(char *nb)
{
	char *postfix;
	char *added;

	if(!(postfix = ft_strset(1, '.')))
		ft_error("creating new string returned a null pointer.");
	if(!(added = ft_strjoin(nb, postfix)))
		ft_error("joining strings returned a null pointer.");
	ft_strdel(&postfix);
	ft_strdel(&nb);
	return (added);
}

char *add_prefix(char *nb, unsigned int len, char *str)
{
	char *prefix;
	char *added;

	if (nb[0] == '-')
		return (nb);
	else
	{
		if (len == 1)
			prefix = ft_strset(len, str[0]);
		else
			prefix = ft_strdup(str);
		if (!prefix)
			ft_error("creating new string returned a null pointer.");
		if (ft_strlen(nb) == 0)
			added = ft_strdup(prefix);
		else
			added = ft_strjoin(prefix, nb);
		if (!added)
			ft_error("joining strings returned a null pointer.");
		ft_strdel(&prefix);
		if (nb && *nb)
			ft_strdel(&nb);
		return (added);
	}
}

char *add_margin(char *str, unsigned int width, unsigned int left_align)
{
	size_t len;
	unsigned int diff;
	char *margin;
	char *new_str;

	len = ft_strlen(str);
	diff = 0;
	if (width > len)
	{
		diff = width - len;
		if(!(margin = ft_strset(diff, ' ')))
			ft_error("creating new string returned a null pointer.");
		if (left_align == 1)
			new_str = ft_strjoin(str, margin);
		else
			new_str = ft_strjoin(margin, str);
		if (!new_str)
			ft_error("string join returned a null pointer.");
		ft_strdel(&margin);
		if(len > 0)
			ft_strdel(&str);
		return (new_str);
	}
	else
		return (str);	
}

char *alter_by_flags(char *nb, t_tag **format)
{	
	unsigned int size;

	size = 0;
	if ((*format)->plus == 1)
		nb = add_prefix(nb, 1, "+");
	else if ((*format)->space == 1)
		nb = add_prefix(nb, 1, " ");
	if ((*format)->hash == 1 && (*format)->has_value[PRECISION_ON] == '1'
	&& (*format)->precision == 0)
		nb = add_decimal(nb);
	if ((*format)->zero == 1 && (*format)->has_value[WIDTH_ON] == '1')
	{
		size = ((*format)->width) - (ft_strlen(nb));
		nb = add_padding(nb, size);
	}
	return (nb);
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
	int left;
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
	if ((*format)->has_value[FLAG_ON] == '1')
		print_float = alter_by_flags(print_float, format);
	if ((*format)->has_value[WIDTH_ON] == '1')
	{
		left = ((*format)->dash == 1) ? 1 : 0;
		print_float = add_margin(print_float, (*format)->width, left);
	}
	ft_putstr(print_float);
	len = ft_strlen(print_float);
	return (len);
}
