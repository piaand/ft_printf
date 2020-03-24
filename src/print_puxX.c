/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_puxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 10:21:31 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/24 11:19:40 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** lower_letter function is needed only because ft_striter doens't accept the 
** function prototype og ft_tolower (it returns the new lower case charater).
*/

static void	lower_letter(char *str)
{
	*(str) = ft_tolower(*(str));
}

static char	*convert_number_unsigned(size_t nb, int base) 
{
	char *print_int;

	if(!(print_int = ft_itoa_base_unsigned(nb, base)))
		ft_error("itoa returned a NULL pointer.");
	return (print_int);
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

int	print_hexa(t_tag **format, va_list args)
{
	int i;
	size_t len;
	char *print_int;

	len = 0;
	i = va_arg(args, int);
	print_int = convert_number_unsigned(i, 16);
	if ((*format)->specifier == 'x')
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