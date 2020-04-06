/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 10:21:31 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/06 17:36:56 by piaandersin      ###   ########.fr       */
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
	else if ((*format)->has_value[LENGTH_ON] == '1')
	{
		print_int = NULL;
		if (ft_strequ((*format)->length, "0h"))
			print_int = ft_itoa_base_unsigned((unsigned short int)nb, base);
		else if (ft_strequ((*format)->length, "0l"))
			print_int = ft_itoa_base_unsigned((unsigned long int)nb, base);
		else if (ft_strequ((*format)->length, "ll"))
			print_int = ft_itoa_base_unsigned((unsigned long long int)nb, base);
		else if (ft_strequ((*format)->length, "hh"))
			print_int = ft_itoa_base_unsigned((unsigned char)nb, base);
	}
	else if (c == 'p')
		print_int = ft_itoa_base_unsigned(nb, base);
	else
		print_int = ft_itoa_base_unsigned((unsigned int)nb, base);
	return (print_int);
}

char		*create_prefix_unsigned(char specifier, unsigned int hash_on, char *nb)
{
	size_t len;

	if (!nb)
		return (nb);
	len = ft_strlen(nb);
	if (hash_on == 1)
	{
		if (specifier == 'o' && nb[0] != '0')
			nb = add_prefix(nb, 1, "0");
		else if (len > 0 && (specifier == 'x' || specifier == 'X') &&
		nb[0] != '0')
			nb = add_prefix(nb, 2, "0X");
	}
	else if (specifier == 'p')
		nb = add_prefix(nb, 2, "0x");
	return (nb);
}

char *format_unsigned(t_tag **format, char *print_unsigned)
{
	char	c;

	c = (*format)->specifier;
	if (c != 'u')
		print_unsigned = create_prefix_unsigned(c, (*format)->hash, print_unsigned);
	if (print_unsigned && (*format)->has_value[PRECISION_ON] == '1' && c != 'p')
		print_unsigned = create_padding(print_unsigned,
		(*format)->precision, 1);
	else if (print_unsigned && (*format)->has_value[WIDTH_ON] == '1' && (*format)->zero == 1)
		print_unsigned = create_padding(print_unsigned, (*format)->width, 0);
	if (print_unsigned && (c == 'x' || c == 'p'))
		ft_striter(print_unsigned, lower_letter);
	return (print_unsigned);
}

int			print_unsigned(t_tag **format, va_list args)
{
	size_t	i;
	size_t	len;
	char	*print_unsigned;
	char	c;

	c = (*format)->specifier;
	i = va_arg(args, unsigned long);
	if (c == 'u')
		print_unsigned = convert_number_unsigned(i, 10, format);
	else if (c == 'o')
		print_unsigned = convert_number_unsigned(i, 8, format);
	else
		print_unsigned = convert_number_unsigned(i, 16, format);
	if (!print_unsigned)
		return(-1);
	if (ft_strequ(print_unsigned, ""))
		len = empty_number(format);
	else
	{
		if (!(print_unsigned = format_unsigned(format, print_unsigned)))
			return (-1);
		if (!(print_unsigned = create_margin(format, print_unsigned, 0)))
			return (-1);
		len = print_final_string(format, print_unsigned, 0);
	}
	return (len);
}
