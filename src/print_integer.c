/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 09:17:17 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/31 09:57:08 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*convert_number(long long int nb, int base) 
{
	char *print_int;

	if(!(print_int = ft_itoa_base(nb, base)))
		ft_error("itoa returned a NULL pointer.");
	return (print_int);
}

int	print_integer(t_tag **format, va_list args)
{
	int long long i;
	size_t len;
	char *print_int;
	char sign;
	char *prefix;

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
	if ((*format)->space == 1 || (*format)->plus == 1)
	{
		sign = ((*format)->plus == 1) ? '+' : ' ';
		if(!(prefix = ft_strset(1, sign)))
			ft_error("creating new string returned a null value.");
		print_int = add_prefix(print_int, 1, prefix);
	}
	if ((*format)->has_value[PRECISION_ON] == '1')
		print_int = create_padding(print_int, (*format)->precision);
	len = print_final_string(format, print_int);
	return (len);
}