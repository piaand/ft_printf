/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 10:21:31 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/01 16:49:12 by piaandersin      ###   ########.fr       */
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

static char	*convert_number_unsigned(size_t nb, int base, t_tag **format) 
{
	char *print_int;
	char c;
	
	c = (*format)->specifier;
	if ((*format)->has_value[PRECISION_ON] == '1' && (*format)->precision == 0
	&& nb == 0 && (c != 'p'))
		print_int = "";
	else if ((*format)->has_value[LENGTH_ON] == '1' && ft_strequ((*format)->length, "0h"))
		print_int = ft_itoa_base_unsigned((unsigned short int)nb, base);
	else
		print_int = ft_itoa_base_unsigned(nb, base);
	if (!print_int)
		ft_error("itoa returned a NULL pointer.");
	return (print_int);
}

char *create_prefix(char specifier, unsigned int hash_on, char *nb)
{
	size_t len;
	
	len = ft_strlen(nb);
	if (hash_on == 1)
	{
		if (specifier == 'o')
			nb = add_prefix(nb, 1, "0");
		else if (len > 0 && (specifier == 'x' || specifier == 'X') && nb[0] != '0')
			nb = add_prefix(nb, 2, "0X");
	}
	else if (specifier == 'p')
		nb = add_prefix(nb, 2, "0x");
	return(nb);
}	

int	print_unsigned(t_tag **format, va_list args)
{
	size_t i;
	size_t len;
	char *print_unsigned;
	char c;

	c = (*format)->specifier;
	i = va_arg(args, size_t);
	if (c == 'u')
		print_unsigned = convert_number_unsigned(i, 10, format);
	else if (c == 'o')
		print_unsigned = convert_number_unsigned(i, 8, format);
	else
		print_unsigned = convert_number_unsigned(i, 16, format);
	if (c != 'u')
		print_unsigned = create_prefix(c, (*format)->hash, print_unsigned);
	if ((*format)->has_value[PRECISION_ON] == '1' && c != 'p')
		print_unsigned = create_padding(print_unsigned, (*format)->precision, 1);
	else if ((*format)->has_value[WIDTH_ON] == '1' && (*format)->zero == 1)
		print_unsigned = create_padding(print_unsigned, (*format)->width, 0);
	if (c == 'x' || c == 'p')
		ft_striter(print_unsigned, lower_letter);
	len = print_final_string(format, print_unsigned);
	return (len);
}
