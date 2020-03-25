/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_next_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 13:49:20 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/25 16:43:08 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int find_specifier(t_tag **format)
{
	char s;
	int index;

	s = (*format)->specifier;
	index = 0;
	while (SPECIFIERS[index] != s)
		index++;
	return (index);
}

static char	*convert_number(int nb, int base) 
{
	char *print_int;

	if(!(print_int = ft_itoa_base(nb, base)))
		ft_error("itoa returned a NULL pointer.");
	return (print_int);
}

long double bankers_rounder(long double nb, unsigned int precision)
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


int	print_float(t_tag **format, va_list args)
{
	double f;
	long double rounder;
	unsigned int precision;
	size_t len;
	char *print_float;

	len = 0;
	f = va_arg(args, double);
	if ((*format)->has_value[PRECISION_ON] == '1')
		precision = (*format)->precision;
	else
		precision = 6; 
	rounder = bankers_rounder(f, precision);
	f += rounder;
	print_float = ft_float_to_a((float)f, precision);
	if ((*format)->has_value[FLAG_ON] == '1')
		len = 0;
	ft_putstr(print_float);
	len = ft_strlen(print_float);
	return (len);
}

int	print_string(t_tag **format, va_list args)
{
	char *str;
	size_t len;

	len = 0;
	str = va_arg(args, char*);
	ft_putstr(str);
	len = ft_strlen(str);
	if ((*format)->has_value[FLAG_ON] == '1')
		str = NULL;
	return (len);
}

int	print_char(t_tag **format, va_list args)
{
	char c;
	size_t len;

	len = 0;
	c = va_arg(args, int);
	ft_putchar(c);
	if ((*format)->has_value[FLAG_ON] == '1')
		c = 'a';
	len = 1;
	return (len);
}

int	print_octal(t_tag **format, va_list args)
{
	int i;
	size_t len;
	char *print_int;

	len = 0;
	i = va_arg(args, int);
	print_int = convert_number(i, 8);
	if ((*format)->has_value[FLAG_ON] == '1')
		i = 1;
	len = ft_strlen(print_int);
	ft_putstr(print_int);
	return (len);
}

int	print_integer(t_tag **format, va_list args)
{
	int i;
	size_t len;
	char *print_int;

	len = 0;
	i = va_arg(args, int);
	print_int = convert_number(i, 10);
	if ((*format)->has_value[FLAG_ON] == '1')
		i = 1;
	len = ft_strlen(print_int);
	ft_putstr(print_int);
	return (len);
}

int	print_next_var(t_tag **format, va_list args)
{
	int		len;
	int		index;
	int		(*prints[10])(t_tag**, va_list);
	
	prints[0] = print_integer;
	prints[1] = print_integer;
	prints[2] = print_octal;
	prints[3] = print_unsigned;
	prints[4] = print_hexa;
	prints[5] = print_hexa;
	prints[6] = print_char;
	prints[7] = print_string;
	prints[8] = print_pointer;
	prints[9] = print_float;
	index = find_specifier(format);
	len = prints[index](format, args);
	return (len);
}

/*unit tests*/
/*
int main(int argc, char **argv)
{
	//2147483647
	//-2147483648
	char *str;
	char *str2;
	float f;
	double dd;
	long double rounder;
	int i;
	i = -1;
	f = 0.00995;
	dd = 2147483647.5; 
	(void)argv;
	if (argc == 2)
	{
		str = ft_itoa_base(i, 10);
		ft_putendl(str);
		rounder = bankers_rounder((float)f, 2);
		f += rounder;
		str2 = ft_float_to_a(f, 1);
		ft_putendl(str2);
	}
	else
	{
		ft_putendl("Too little or too many arguments");
	}
	
}
*/