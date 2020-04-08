/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 09:17:17 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/08 13:45:46 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*convert_number(long long int nb, int base, t_tag **format)
{
	char *print_int;

	if ((*format)->has_value[PRECISION_ON] == '1' &&
	(*format)->precision == 0 && nb == 0)
		print_int = "";
	else
		print_int = ft_itoa_base(nb, base);
	return (print_int);
}

static char	*control_length(t_tag **format, long long i)
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

/*
** Contains the logic on how to decide the prefix for signed integer.
** Returns the string to be printed or NULL in case of error.
*/

static char	*create_prefix_signed(t_tag **format, char *nb)
{
	char	sign;
	char	*prefix;

	sign = ((*format)->plus == 1) ? '+' : ' ';
	if (!(prefix = ft_strset(1, sign)))
	{
		ft_strdel(&nb);
		return (NULL);
	}
	nb = add_prefix(nb, 1, prefix);
	ft_strdel(&prefix);
	return (nb);
}

/*
** Creates the prefix and adds all zeros from precision modifier.
** Returns the string to be printed or NULL in case of error.
*/

char		*format_integer(char *print_int, t_tag **format)
{
	if ((*format)->space == 1 || (*format)->plus == 1)
		print_int = create_prefix_signed(format, print_int);
	if (print_int && ((*format)->has_value[PRECISION_ON] == '1'))
		print_int = create_padding(print_int, (*format)->precision, 1);
	else if (print_int && (*format)->has_value[WIDTH_ON] == '1' &&
	(*format)->zero == 1)
		print_int = create_padding(print_int, (*format)->width, 0);
	return (print_int);
}

/*
** Makes sure signed integer is printed out correctly with format attributes.
** Returns how many characters was printed out when integer was written.
*/

int			print_integer(t_tag **format, va_list args)
{
	long long	i;
	size_t		len;
	char		*print_int;

	len = 0;
	i = va_arg(args, long long int);
	if (!(print_int = control_length(format, i)))
		return (-1);
	if (ft_strequ("", print_int))
	{
		print_int = NULL;
		len = empty_number(format);
	}
	else
	{
		if (!(print_int = format_integer(print_int, format)))
			return (-1);
		if (!(print_int = create_margin(format, print_int, 0)))
			return (-1);
		len = print_final_string(format, print_int, 0);
	}
	return (len);
}
