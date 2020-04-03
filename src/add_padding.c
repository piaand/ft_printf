/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 13:08:33 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/03 16:11:09 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*subtract_value(char *nb, size_t len, unsigned int len_pre)
{
	char *tmp;

	if (len_pre != 0)
		tmp = ft_strsub(nb, len_pre, len);
	else
		tmp = ft_strdup(nb);
	return (tmp);
}

static char		*create_new_nb(char *nb, char *sign, unsigned int prefix,
unsigned int padding_size)
{
	char *padding;
	char *tmp;
	char *value;
	char *new_nb;

	if (!(padding = ft_strset(padding_size, '0')))
	{
		ft_strdel(&sign);
		ft_strdel(&nb);
		value = NULL;
	}
	else
		value = subtract_value(nb, ft_strlen(nb), prefix);
	if (prefix > 0)
	{
		tmp = ft_strjoin(sign, padding);
		new_nb = ft_strjoin(tmp, value);
		ft_strdel(&tmp);
	}
	else
		new_nb = ft_strjoin(padding, value);
	ft_strdel(&sign);
	ft_strdel(&padding);
	ft_strdel(&value);
	ft_strdel(&nb);
	return (new_nb);
}

/*
** Returns the length of a prefix in a number.
*/

unsigned int	check_prefix(char *prefix)
{
	unsigned int len;

	len = 0;
	if (prefix[0] == '-' || prefix[0] == ' ' || prefix[0] == '+')
		len++;
	else if (prefix[0] == '0' && prefix[1] == 'X')
		len = 2;
	return (len);
}

/*
** Returns a string where padding amount of zeros is written between prefix
** and actual value
*/

char			*add_padding(char *nb, unsigned int padding)
{
	size_t			len;
	unsigned int	len_pre;
	char			*new_nb;
	char			*prefix;

	len = ft_strlen(nb);
	len_pre = 0;
	prefix = NULL;
	if (len >= 2)
	{
		len_pre = check_prefix(nb);
		if (len_pre > 0)
		{
			if (!(prefix = ft_strsub(nb, 0, len_pre)))
			{
				ft_strdel(&prefix);
				return (NULL);
			}
		}
	}
	new_nb = create_new_nb(nb, prefix, len_pre, padding);
	return (new_nb);
}

/*
** Calculated the number of zeros in the padding for integers
*/

char			*create_padding(char *nb, unsigned int space,
unsigned int precision)
{
	size_t	len;
	int		prefix;
	int		size;
	char	*padded;

	len = ft_strlen(nb);
	if (precision == 1)
	{
		prefix = check_prefix(nb);
		size = space - (len - prefix);
	}
	else
		size = space - len;
	if (size > 0)
		padded = add_padding(nb, size);
	else
		padded = nb;
	return (padded);
}
