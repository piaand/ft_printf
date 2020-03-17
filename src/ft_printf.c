/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 11:59:19 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/17 13:03:12 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char *find_tag(const char *str, size_t j, size_t len_input) {
	char *format_tag;
	char *temp;
	long long index;
	unsigned int i;
	
	temp = ft_strsub(str, j, len_input);
	i = 0;
	index = -1;
	while (index == -1 && SPECIFIERS[i] != '\0')
	{
		index = ft_strchri(temp, SPECIFIERS[i]);
		i++;
	}
	if (index == -1)
	{
		if (temp[0] == '%')
			format_tag = ft_strsub(temp, 0, 1);
		else
			ft_putendl("Error: unvalid specifier.");
			exit(1);
	}
	else
		format_tag = ft_strsub(temp, 0, (index + 1));
	ft_strdel(&temp);
	return (format_tag);
}


int read_format(const char *input, size_t i, size_t len_input) {
	char *format_tag;

	format_tag = find_tag(input, i, len_input);
	ft_putstr(format_tag);
	// assign the structs
	i = ft_strlen(format_tag) + i;
	return (i);
}


int ft_printf(const char *format, ...) {
	size_t i;
	size_t j;
	size_t len_output;
	size_t len_input;

	len_input = ft_strlen(format);
	len_output = len_input;
	j = 0;
	i = 0;
	while (format[i] != '\0') {
		while (format[i] != '%' && format[i] != '\0')
		{
			ft_putchar(format[i]);
			i++;
		}
		if (format[i] != '\0')
		{
			j = i++;
			i = read_format(format, i, len_input);
			len_output -= (i-j);
			i++;
		}
	}
	return (len_output);
}
