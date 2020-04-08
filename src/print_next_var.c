/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_next_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 13:49:20 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/08 17:18:27 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_error(char *message)
{
	ft_putstr("Error: ");
	ft_putendl(message);
	ft_putendl("\nSystem exits.");
	exit(1);
}

static int	find_specifier(t_tag **format)
{
	char	s;
	int		index;

	s = (*format)->specifier;
	index = 0;
	while (SPECIFIERS[index] != s)
		index++;
	return (index);
}

long long	print_null_char(char *str, unsigned int left_aligned, long long len)
{
	char *tmp;

	len--;
	tmp = NULL;
	if (len <= 0)
		write(1, "\0", 1);
	else if (left_aligned)
	{
		write(1, "\0", 1);
		if (!(tmp = ft_strsub(str, 1, len)))
			return (-1);
		ft_putstr(tmp);
	}
	else
	{
		if (!(tmp = ft_strsub(str, 0, len)))
			return (-1);
		ft_putstr(tmp);
		write(1, "\0", 1);
	}
	ft_strdel(&tmp);
	len++;
	return (len);
}

size_t		print_final_string(t_tag **format, char *str, int char_null)
{
	long long		len;
	unsigned int	left;

	left = 0;
	if ((*format)->has_value[WIDTH_ON] == '1')
		left = ((*format)->dash == 1) ? 1 : 0;
	len = ft_strlen(str);
	if (char_null)
		len = print_null_char(str, left, len);
	else
		ft_putstr(str);
	ft_strdel(&str);
	return (len);
}

int			print_next_var(t_tag **format, va_list args)
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
