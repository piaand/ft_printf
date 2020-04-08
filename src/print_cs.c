/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 11:15:41 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/08 17:20:35 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*create_margin(t_tag **format, char *str, int char_null)
{
	unsigned int	left;

	left = 0;
	if ((*format)->has_value[WIDTH_ON] == '1')
	{
		left = ((*format)->dash == 1) ? 1 : 0;
		str = add_margin(str, (*format)->width, left, char_null);
	}
	return (str);
}

int			print_string(t_tag **format, va_list args)
{
	char	*str;
	char	*output;
	char	*tmp;
	size_t	len;

	str = va_arg(args, char*);
	if (!str)
		output = ft_strdup("(null)");
	else
		output = ft_strdup(str);
	if (!output)
		return (-1);
	if ((*format)->has_value[PRECISION_ON] == '1')
	{
		tmp = ft_strsub(output, 0, (*format)->precision);
		ft_strdel(&output);
		if (!tmp)
			return (-1);
		output = tmp;
	}
	if (!(tmp = create_margin(format, output, 0)))
		return (-1);
	len = print_final_string(format, tmp, 0);
	return (len);
}

int			print_char(t_tag **format, va_list args)
{
	char	c;
	char	*str;
	int		char_null;
	size_t	len;

	len = 0;
	c = va_arg(args, int);
	if (c == 0)
	{
		char_null = 1;
		if (!(str = ft_strset(1, 'c')))
			return (-1);
	}
	else
	{
		char_null = 0;
		if (!(str = ft_strset(1, c)))
			return (-1);
	}
	if (!(str = create_margin(format, str, char_null)))
		return (-1);
	len = print_final_string(format, str, char_null);
	return (len);
}
