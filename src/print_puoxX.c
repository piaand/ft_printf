/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_puoxX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 10:21:31 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/31 10:04:20 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** lower_letter function is needed only because ft_striter doens't accept the 
** function prototype og ft_tolower (it returns the new lower case charater).
*/

static char	*convert_number_unsigned(size_t nb, int base, t_tag **format) 
{
	char *print_int;
	
	if ((*format)->has_value[PRECISION_ON] == '1' && (*format)->precision == 0
	&& nb == 0 && (!((*format)->specifier == 'p')))
		print_int = "";
	else if ((*format)->has_value[LENGTH_ON] == '1' && ft_strequ((*format)->length, "0h"))
		print_int = ft_itoa_base_unsigned((unsigned short int)nb, base);
	else
		print_int = ft_itoa_base_unsigned(nb, base);
	if (!print_int)
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
	address = convert_number_unsigned(memory, 16, format);
	ft_striter(address, lower_letter);
	if (!(print_ptr = ft_strjoin("0x", address)))
		ft_error("joining strings retruned NULL pointer.");
	len = print_final_string(format, print_ptr);
	return (len);
}

int	print_hexa(t_tag **format, va_list args)
{
	size_t i;
	size_t len;
	char *hexa_printout;

	len = 0;
	i = va_arg(args, size_t);
	hexa_printout = convert_number_unsigned(i, 16, format);
	if ((*format)->has_value[PRECISION_ON] == '1')
		hexa_printout = create_padding(hexa_printout, (*format)->precision);
	if ((*format)->hash == 1 && (ft_strlen(hexa_printout) > 0))
		hexa_printout = add_prefix(hexa_printout, 2, "0X");
	if ((*format)->specifier == 'x')
		ft_striter(hexa_printout, lower_letter);
	len = print_final_string(format, hexa_printout);
	return (len);
}

int	print_octal(t_tag **format, va_list args)
{
	size_t i;
	size_t len;
	char *print_octal;

	len = 0;
	i = va_arg(args, size_t);
	print_octal = convert_number_unsigned(i, 8, format);
	if ((*format)->has_value[PRECISION_ON] == '1')
		print_octal = create_padding(print_octal, (*format)->precision);
	if ((*format)->hash == 1)
		print_octal = add_prefix(print_octal, 1, "0");
	len = print_final_string(format, print_octal);
	return (len);
}

int	print_unsigned(t_tag **format, va_list args)
{
	size_t i;
	size_t len;
	char *print_unsigned;

	len = 0;
	i = va_arg(args, size_t);
	print_unsigned = convert_number_unsigned(i, 10, format);
	if ((*format)->has_value[PRECISION_ON] == '1')
		print_unsigned = create_padding(print_unsigned, (*format)->precision);
	len = print_final_string(format, print_unsigned);
	return (len);
}
