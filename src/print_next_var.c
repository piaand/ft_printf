/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_next_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 13:49:20 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/02 12:05:26 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int find_specifier(t_tag **format)
{
	char s;
	int index;

	s = (*format)->specifier;
	index = 0;
	while (SPECIFIERS[index] != s)
		index++;
	return (index);
}

size_t print_final_string(t_tag **format, char *str, int char_null)
{
	size_t len;
	unsigned int left;
	
	left = 0;
	if ((*format)->has_value[WIDTH_ON] == '1')
	{
		left = ((*format)->dash == 1) ? 1 : 0;
		str = add_margin(str, (*format)->width, left, char_null);
	}
	len = ft_strlen(str);
	if (char_null && left)
	{
		write(1, "\0", 1);
		ft_putstr(str);
		len++;
	}
	else if (char_null)
	{
		ft_putstr(str);
		write(1, "\0", 1);
		len++;
	}
	else
		ft_putstr(str);
	if (str && *str)
		ft_strdel(&str);
	return (len);
}

int	print_string(t_tag **format, va_list args)
{
	char *str;
	char *output;
	size_t len;

	len = 0;
	str = va_arg(args, char*);
	if (!str)
		output = ft_strdup("(null)");
	else 
		output = ft_strdup(str);
	if (!output)
		ft_error("creating dublicate string returned a null value");
	if ((*format)->has_value[PRECISION_ON] == '1')
	{
		if (!(output = ft_strsub(output, 0, (*format)->precision)))
			ft_error("creating substring returned a null value.");
	}
	len = print_final_string(format, output, 0);
	return (len);
}

int	print_char(t_tag **format, va_list args)
{
	char c;
	char *str;
	int char_null;
	size_t len;

	len = 0;
	c = va_arg(args, int);
	if (c == 0)
		char_null = 1;
	else
		char_null = 0;
	if (!(str = ft_strset(1, c)))
		ft_error("creating a new string returned a null value.");
	len = print_final_string(format, str, char_null);
	return (len);
}

int	print_next_var(t_tag **format, va_list args)
{
	int		len;
	int		index;
	int		(*prints[10])(t_tag**, va_list);
	
	prints[0] = print_integer;
	prints[1] = print_integer;
	prints[2] = print_unsigned;
	prints[3] = print_unsigned;
	prints[4] = print_unsigned;
	prints[5] = print_unsigned;
	prints[6] = print_char;
	prints[7] = print_string;
	prints[8] = print_unsigned;
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