/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosscheck_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 09:41:24 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/31 09:33:57 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	lower_letter(char *str)
{
	*(str) = ft_tolower(*(str));
}

unsigned int check_prefix(char *prefix)
{
	unsigned int len;

	len = 0;
	if (prefix[0] == '-' || prefix[0] == ' ' || prefix[0] == '+' || prefix[0] == '0')
	{
		len++;
		if (prefix[1] == 'x' || prefix[1] == 'X')
			len++;
	}
	return (len);
}

char *add_decimal(char *nb)
{
	char *postfix;
	char *added;

	if(!(postfix = ft_strset(1, '.')))
		ft_error("creating new string returned a null pointer.");
	if(!(added = ft_strjoin(nb, postfix)))
		ft_error("joining strings returned a null pointer.");
	ft_strdel(&postfix);
	ft_strdel(&nb);
	return (added);
}

char *add_prefix(char *nb, unsigned int len, char *str)
{
	char *prefix;
	char *added;

	if (nb[0] == '-')
		return (nb);
	else
	{
		if (len == 1)
			prefix = ft_strset(len, str[0]);
		else
			prefix = ft_strdup(str);
		if (!prefix)
			ft_error("creating new string returned a null pointer.");
		if (ft_strlen(nb) == 0)
			added = ft_strdup(prefix);
		else
			added = ft_strjoin(prefix, nb);
		if (!added)
			ft_error("joining strings returned a null pointer.");
		ft_strdel(&prefix);
		if (nb && *nb)
			ft_strdel(&nb);
		return (added);
	}
}

char *add_margin(char *str, unsigned int width, unsigned int left_align)
{
	size_t len;
	unsigned int diff;
	char *margin;
	char *new_str;

	len = ft_strlen(str);
	diff = 0;
	if (width > len)
	{
		diff = width - len;
		if(!(margin = ft_strset(diff, ' ')))
			ft_error("creating new string returned a null pointer.");
		if (left_align == 1)
			new_str = ft_strjoin(str, margin);
		else
			new_str = ft_strjoin(margin, str);
		if (!new_str)
			ft_error("string join returned a null pointer.");
		ft_strdel(&margin);
		if(len > 0)
			ft_strdel(&str);
		return (new_str);
	}
	else
		return (str);	
}

int check_length(char specifier, char *length)
{
	if (specifier == 'c' || specifier == 's' || specifier == 'p')
		return (0);
	else if (specifier == 'f')
	{
		if (ft_strequ(length, "0L") || ft_strequ(length, "0l"))
			return (1);
		else
			return (0);
	}
	else
	{
		if (ft_strequ(length, "0L"))
			return (0);
		else
			return (1);
	}
}

void	crosscheck_format(t_tag **format)
{
	int ok;

	ok = 0;
	if ((*format)->has_value[LENGTH_ON] == '1')
	{
		ok = check_length((*format)->specifier, (*format)->length);
		if (!ok)
			ft_error("found unvalid specifier - length combination");
	}
}
