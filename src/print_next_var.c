/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_next_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 13:49:20 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/23 16:55:31 by piaandersin      ###   ########.fr       */
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

/*
** lower_letter function is needed only because ft_striter doens't accept the 
** function prototype og ft_tolower (it returns the new lower case charater).
*/

void	lower_letter(char *str)
{
	*(str) = ft_tolower(*(str));
}

char	*convert_number_unsigned(size_t nb, int base) 
{
	char *print_int;

	if(!(print_int = ft_itoa_base_unsigned(nb, base)))
		ft_error("itoa returned a NULL pointer.");
	return (print_int);
}

char	*convert_number(int nb, int base) 
{
	char *print_int;

	if(!(print_int = ft_itoa_base(nb, base)))
		ft_error("itoa returned a NULL pointer.");
	return (print_int);
}

int	print_float(t_tag **format, va_list args)
{
	(void)format;
	(void)args;
	ft_putendl("Printing float!");
	return (10);
}

int	print_pointer(t_tag **format, va_list args)
{
	size_t memory;
	size_t len;
	char *address;
	char *print_ptr;

	len = 0;
	memory = va_arg(args, size_t);
	address = convert_number_unsigned(memory, 16);
	ft_striter(address, lower_letter);
	print_ptr = ft_strjoin("0x", address);
	if ((*format)->has_value[FLAG_ON] == '1')
		memory = 1;
	len = ft_strlen(print_ptr);
	ft_putstr(print_ptr);
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

int	print_HEXA(t_tag **format, va_list args)
{
	int i;
	size_t len;
	char *print_int;

	len = 0;
	i = va_arg(args, int);
	print_int = convert_number(i, 16);
	if ((*format)->has_value[FLAG_ON] == '1')
		i = 1;
	len = ft_strlen(print_int);
	ft_putstr(print_int);
	return (len);
}

int	print_hexa(t_tag **format, va_list args)
{
	int i;
	size_t len;
	char *print_int;

	len = 0;
	i = va_arg(args, int);
	print_int = convert_number(i, 16);
	ft_striter(print_int, lower_letter);
	if ((*format)->has_value[FLAG_ON] == '1')
		i = 1;
	len = ft_strlen(print_int);
	ft_putstr(print_int);
	return (len);
}

int	print_unsigned(t_tag **format, va_list args)
{
	int i;
	size_t len;
	char *print_int;

	len = 0;
	i = va_arg(args, unsigned int);
	print_int = convert_number_unsigned(i, 10);
	if ((*format)->has_value[FLAG_ON] == '1')
		i = 1;
	len = ft_strlen(print_int);
	ft_putstr(print_int);
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
	prints[5] = print_HEXA;
	prints[6] = print_char;
	prints[7] = print_string;
	prints[8] = print_pointer;
	prints[9] = print_float;
	index = find_specifier(format);
	len = prints[index](format, args);
	return (len);
}
