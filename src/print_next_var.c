/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_next_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 13:49:20 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/19 15:42:56 by piaandersin      ###   ########.fr       */
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

int	print_float(t_tag **format, va_list args)
{
	(void)format;
	(void)args;
	ft_putendl("Printing float!");
	return (10);
}

int	print_pointer(t_tag **format, va_list args)
{
	(void)format;
	(void)args;
	ft_putendl("Printing pointer!");
	return (10);
}

int	print_string(t_tag **format, va_list args)
{
	(void)format;
	(void)args;
	ft_putendl("Printing string!");
	return (10);
}

int	print_char(t_tag **format, va_list args)
{
	(void)format;
	(void)args;
	ft_putendl("Printing char!");
	return (10);
}

int	print_HEXA(t_tag **format, va_list args)
{
	(void)format;
	(void)args;
	ft_putendl("Printing hexa WITH CAPITAL LETTERS!");
	return (10);
}

int	print_hexa(t_tag **format, va_list args)
{
	(void)format;
	(void)args;
	ft_putendl("Printing hexa!");
	return (10);
}

int	print_unsigned(t_tag **format, va_list args)
{
	(void)format;
	(void)args;
	ft_putendl("Printing unsigned!");
	return (10);
}

int	print_octal(t_tag **format, va_list args)
{
	(void)format;
	(void)args;
	ft_putendl("Printing octals!");
	return (10);
}

int	print_integer(t_tag **format, va_list args)
{
	(void)format;
	(void)args;
	ft_putendl("Printing integers!");
	return (10);
}

int	print_next_var(t_tag **format, va_list args)
{
	int len;
	int index;
	int (*prints[10])(t_tag**, va_list);
	
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
