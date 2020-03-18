/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 11:59:19 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/18 12:13:30 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_error(char *message)
{
	ft_putstr("Error: ");
	ft_putendl(message);
	exit(1);
}

char *find_tag(const char **str)
{
	char *format_tag;
	char *temp;
	char *found;
	unsigned int i;
	
	format_tag = NULL;
	if (!(temp = ft_strnew(ft_strlen(*str))))
		ft_error("memory allocation for string failed.");
	temp = ft_strcpy(temp, *str);
	if (temp[0] == '%')
		format_tag = ft_strsub(temp, 0, 1);
	else
	{
		i = 0;
		found = NULL;
		while (!found && temp[i] != '%' && temp[i] != '\0')
			found = ft_strchr(SPECIFIERS, temp[i++]);
		if (!found)
			ft_error("unvalid specifier.");
		else
			format_tag = ft_strsub(temp, 0, i);
	}
	ft_strdel(&temp);
	return (format_tag);
}

int	print_form_var_list(char *format_tag)
{
	/*t_tag *new;
	int len;

	if (!(new = (t_tag*)ft_memalloc(sizeof(t_tag))));
		ft_error("memory allocation for tag failed.");
	assign_tag_info(&new, instructions);
	// apply switch table to do printing
	// return the amount of printed characters */
	ft_putendl("Print tag");
	ft_putendl(format_tag);
	return (1);
}

/*
** Returns the amount of printed argument characters
*/

int	print_argument(const char **input)
{
	char *format_tag;
	int len_var;
	size_t i;

	format_tag = find_tag(input);
	i = 0;
	while (i < ft_strlen(format_tag))
	{
		(*input)++;
		i++;
	}
	if (format_tag[0] == '%')
	{
		ft_putchar('%');
		len_var = 1;
	}
	else
		 len_var = print_form_var_list(format_tag);
	return (len_var);
}

/*
** Returns the amount of printed characters
*/

int ft_printf(const char *format, ...)
{
	size_t len;
	size_t len_var;

	len = 0;
	len_var = 0;
	while (*format != '\0') {
		while (*format != '%' && *format != '\0')
		{
			ft_putchar(*format);
			len++;
			format++;
		}
		if (*format != '\0')
		{
			format++;
			len_var = print_argument(&format);
			len += len_var;
		}
	}
	return (len);
}
