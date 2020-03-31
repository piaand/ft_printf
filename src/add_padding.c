/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 13:08:33 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/31 09:34:40 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


static char *subtract_value(char *nb, size_t len, unsigned int len_pre)
{
	char *tmp;

	if (len_pre != 0)
		tmp = ft_strsub(nb, len_pre, len);
	else
		tmp = ft_strdup(nb);
	if (!tmp)
		ft_error("creating string dup returned a null pointer.");
	return (tmp);
}

static char *create_new_nb(char *nb, char *sign, unsigned int prefix, unsigned int padding_size)
{
	char *padding;
	char *tmp;
	char *value;
	char *new_nb;
	
	value = subtract_value(nb, ft_strlen(nb), prefix);
	if(!(padding = ft_strset(padding_size, '0')))
		ft_error("creating padding string returned a null pointer.");
	if (prefix > 0)
	{
		if(!(tmp = ft_strjoin(sign, padding)))
			ft_error("creating tmp string returned a null pointer.");
		ft_strdel(&sign);
		new_nb = ft_strjoin(tmp, value);
		ft_strdel(&tmp);
	}
	else
		new_nb = ft_strjoin(padding, value);
	if(!new_nb)
		ft_error("creating padded string failed.");
	ft_strdel(&padding);
	ft_strdel(&value);
	ft_strdel(&nb);
	return (new_nb);
}

/*
** Returns a string where padding amount of zeros is written between prefix
** and actual value
*/

char *add_padding(char *nb, unsigned int padding)
{
	size_t len;
	unsigned int len_pre;
	char *new_nb;
	char *prefix;

	len = ft_strlen(nb);
	len_pre = 0;
	prefix = NULL;
	if (len >= 2)
	{
		len_pre = check_prefix(nb);
		if (len_pre > 0)
		{
			if(!(prefix = ft_strsub(nb, 0, len_pre)))
				ft_error("creating substring returned a null pointer.");
		}
	}
	new_nb = create_new_nb(nb, prefix, len_pre, padding);
	return (new_nb);
}

char *create_padding(char *nb, unsigned int precision)
{
	size_t len;
	unsigned int prefix;
	int size;
	char *padded;

	len = ft_strlen(nb);
	prefix = check_prefix(nb);
	size = precision - (len - prefix);
	if (size > 0)
		padded = add_padding(nb, size);
	else
		padded = nb;
	return (padded);
}
