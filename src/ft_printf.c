/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 11:59:19 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/17 16:29:52 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char *find_tag(const char *str, size_t j, size_t len_input)
{
	char *format_tag;
	char *temp;
	char *found;
	unsigned int i;
	
	temp = ft_strsub(str, j, len_input);
	if (temp[0] == '%')
		format_tag = ft_strsub(temp, 0, 1);
	else
	{
		i = 0;
		found = NULL;
		while (!found && temp[i] != '%' && temp[i] != '\0')
			found = ft_strchr(SPECIFIERS, temp[i++]);
		if (!found)
		{
			ft_putendl("Error: unvalid specifier.");
			exit(1);
		}
		else
			format_tag = ft_strsub(temp, 0, i);
	}
	ft_strdel(&temp);
	return (format_tag);
}

void assign_struct(char tag)
{
	int i;
	int flag_done;
	char *found;

	found = NULL;
	flag_done = 0;
	i = 0;
	while (flag_done == 0 && tag[i] != '\0')
	{
		found = ft_strchr(FLAGS, tag[i]);
		if (found)
		{
			insert_flag(tag[i]);
			i++;
		}
		else
			flag_done = 1;
	}
	while (is_digit(tag[i]) && tag[i] != '\0')
	{
		i++;
		//do atoi to get the number, what about 0 in the beginning?
	}
	if (tag[i] == '.')
	{
		i++;
		while (is_digit(tag[i]) && tag[i] != '\0')
		{
			//do atoi for precision, if no digits then precision 0
		}
	}
	if (tag[i] == 'h' || tag[i] == 'l' || tag[i] == 'L')
	{
		// do length modifiers
	}
	found = ft_strchr(SPECIFIERS, tag[i]);
	if (!found)
	{
		ft_putendl("Error: unvalid format tag.")
		exit(1);
	}
	else
		insert_specifier(tag[i]);
}

int read_format(const char *input, size_t i, size_t len_input)
{
	char *format_tag;

	format_tag = find_tag(input, i, len_input);
	if (format_tag[0] == '%')
		ft_putchar('%');
	else 
		assign_struct(format_tag);
	i += ft_strlen(format_tag);
	return (i);
}


int ft_printf(const char *format, ...)
{
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
