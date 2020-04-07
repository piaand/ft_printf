/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_width_precision_length.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 08:58:42 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/07 16:11:39 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	subtract_number(char **str)
{
	size_t	len;
	int		res;
	char	*nb;

	len = 0;
	while (ft_isdigit(*(*str)) && (*(*str)) != '\0')
	{
		len++;
		(*str)++;
	}
	if (!(nb = ft_strnew(len)))
		return (-1);
	while (len > 0)
	{
		(*str)--;
		len--;
	}
	while (ft_isdigit(*(*str)) && (*(*str)) != '\0')
	{
		nb[len] = *(*str);
		(*str)++;
		len++;
	}
	res = ft_atoi(nb);
	ft_strdel(&nb);
	return (res);
}

static char	*create_length(t_tag **format, char first, char second)
{
	char *str;

	if (!(str = ft_strnew(2)))
		return (NULL);
	str[0] = first;
	str[1] = second;
	ft_strdel(&(*format)->length);
	return (str);
}

void		insert_length(t_tag **new, char **str)
{
	(*new)->has_value[LENGTH_ON] = '1';
	if ((*(*str)) == 'h')
	{
		if ((*(*str + 1)) == 'h')
		{
			(*new)->length = create_length(new, 'h', 'h');
			(*str)++;
		}
		else
			(*new)->length = create_length(new, '0', 'h');
	}
	else if ((*(*str)) == 'l')
	{
		if ((*(*str + 1)) == 'l')
		{
			(*new)->length = create_length(new, 'l', 'l');
			(*str)++;
		}
		else
			(*new)->length = create_length(new, '0', 'l');
	}
	else if ((*(*str)) == 'L')
		(*new)->length = create_length(new, '0', 'L');
	(*str)++;
}

int			insert_precision(t_tag **new, char **str)
{
	int precision;

	(*str)++;
	precision = 0;
	(*new)->has_value[PRECISION_ON] = '1';
	if (ft_isdigit(*(*str)) && (*(*str)) != '\0')
		precision = subtract_number(str);
	if (precision == -1)
		return (-1);
	else
	{
		(*new)->precision = precision;
		return (1);
	}
}

int			insert_width(t_tag **new, char **str)
{
	int res;

	(*new)->has_value[WIDTH_ON] = '1';
	res = subtract_number(str);
	if (res == -1)
		return (-1);
	else
	{
		(*new)->width = res;
		return (1);
	}
}
