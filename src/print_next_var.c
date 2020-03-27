/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_next_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 13:49:20 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/27 09:51:57 by piaandersin      ###   ########.fr       */
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

static char	*convert_number(long long int nb, int base) 
{
	char *print_int;

	if(!(print_int = ft_itoa_base(nb, base)))
		ft_error("itoa returned a NULL pointer.");
	return (print_int);
}

int	print_string(t_tag **format, va_list args)
{
	char *str;
	size_t len;

	len = 0;
	str = va_arg(args, char*);
	if ((*format)->has_value[PRECISION_ON] == '1')
	{
		if (!(str = ft_strsub(str, 0, (*format)->precision)))
			ft_error("creating substring returned a null value.");
	}
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


int	print_integer(t_tag **format, va_list args)
{
	int long long i;
	size_t len;
	char *print_int;

	len = 0;
	i = va_arg(args, long long int);
	if ((*format)->has_value[LENGTH_ON] == '1')
	{
		if (ft_strequ((*format)->length, "0h"))
			print_int = convert_number((short int)i, 10);
		else if (ft_strequ((*format)->length, "0l"))
			print_int = convert_number((long int)i, 10);
		else
			print_int = convert_number(i, 10);
	}
	else
		print_int = convert_number((int)i, 10);
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