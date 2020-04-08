/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifier_length.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 09:41:24 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/08 17:16:32 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*join_nb_prefix(char *nb, char *prefix)
{
	char *added;

	if (ft_strlen(nb) == 0)
		added = ft_strdup(prefix);
	else
		added = ft_strjoin(prefix, nb);
	ft_strdel(&prefix);
	if (nb && *nb)
		ft_strdel(&nb);
	return (added);
}

char		*add_prefix(char *nb, unsigned int len, char *str)
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
		{
			if (nb && *nb)
				ft_strdel(&nb);
			return (NULL);
		}
		added = join_nb_prefix(nb, prefix);
		return (added);
	}
}

char		*add_margin(char *str, unsigned int width,
unsigned int left_align, int char_null)
{
	size_t			len;
	unsigned int	diff;
	char			*margin;
	char			*new_str;

	len = (char_null == 1) ? 1 : ft_strlen(str);
	diff = 0;
	if (width > len)
	{
		diff = width - len;
		if (!(margin = ft_strset(diff, ' ')))
		{
			ft_strdel(&str);
			str = NULL;
		}
		if (left_align == 1)
			new_str = ft_strjoin(str, margin);
		else
			new_str = ft_strjoin(margin, str);
		ft_strdel(&margin);
		ft_strdel(&str);
		return (new_str);
	}
	else
		return (str);
}

char		*add_decimal(char *nb)
{
	char *postfix;
	char *added;

	if (!(postfix = ft_strset(1, '.')))
		return (NULL);
	added = ft_strjoin(nb, postfix);
	ft_strdel(&postfix);
	ft_strdel(&nb);
	return (added);
}

void		check_specifier_length(t_tag **format)
{
	int		ok;
	char	specifier;
	char	*length;

	ok = 0;
	specifier = (*format)->specifier;
	length = (*format)->length;
	if ((*format)->has_value[LENGTH_ON] == '1')
	{
		if (specifier == 'c' || specifier == 's' || specifier == 'p')
			ok = 0;
		else if (specifier == 'f')
		{
			if (ft_strequ(length, "0L") || ft_strequ(length, "0l"))
				ok = 1;
		}
		else
		{
			if (!(ft_strequ(length, "0L")))
				ok = 1;
		}
		if (!ok)
			ft_error("found unvalid specifier - length combination");
	}
}
