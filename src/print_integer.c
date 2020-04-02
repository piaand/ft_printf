/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 09:17:17 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/02 13:25:52 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*convert_number(long long int nb, int base, t_tag **format) 
{
	char *print_int;

	if ((*format)->has_value[PRECISION_ON] == '1' && (*format)->precision == 0 && nb == 0)
		print_int = "";
	else if(!(print_int = ft_itoa_base(nb, base)))
		ft_error("itoa returned a NULL pointer.");
	return (print_int);
}

static char *control_length(t_tag **format, long long i)
{
	char *print_int;
	
	if ((*format)->has_value[LENGTH_ON] == '1')
	{
		if (ft_strequ((*format)->length, "0h"))
			print_int = convert_number((short int)i, 10, format);
		else if (ft_strequ((*format)->length, "0l"))
			print_int = convert_number((long int)i, 10, format);
		else if (ft_strequ((*format)->length, "hh"))
			print_int = convert_number((signed char)i, 10, format);
		else
			print_int = convert_number(i, 10, format);
	}
	else
		print_int = convert_number((int)i, 10, format);
	return (print_int);
}

int	print_integer(t_tag **format, va_list args)
{
	long long i;
	size_t len;
	char *print_int;
	char sign;
	char *prefix;

	len = 0;
	i = va_arg(args, long long int);
	print_int = control_length(format, i);
	if ((*format)->space == 1 || (*format)->plus == 1)
	{
		sign = ((*format)->plus == 1) ? '+' : ' ';
		if(!(prefix = ft_strset(1, sign)))
			ft_error("creating new string returned a null value.");
		print_int = add_prefix(print_int, 1, prefix);
	}
	if ((*format)->has_value[PRECISION_ON] == '1')
		print_int = create_padding(print_int, (*format)->precision, 1);
	else if ((*format)->has_value[WIDTH_ON] == '1' && (*format)->zero == 1)
		print_int = create_padding(print_int, (*format)->width, 0);
	len = print_final_string(format, print_int, 0);
	return (len);
}
