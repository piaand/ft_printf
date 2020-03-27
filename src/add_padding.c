/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 13:08:33 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/27 14:03:09 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char *create_substr(char *nb, size_t len, char sign)
{
	char *tmp;

	if (sign == '-' || sign == ' ' || sign == '+')
		tmp = ft_strsub(nb, 1, len);
	else
		tmp = ft_strdup(nb);
	if (!tmp)
		ft_error("creating string dup returned a null pointer.");
	return (tmp);
}

static char *create_new_nb(char *nb, size_t len, char sign, unsigned int padding_size)
{
	char *padding;
	char *tmp;
	char *new_nb;
	unsigned int prefix;
	
	prefix = (sign == '-' || sign == ' ' || sign == '+') ? 1 : 0;
	tmp = create_substr(nb, len, sign);
	if(!(padding = ft_strset((padding_size - len + prefix), '0')))
		ft_error("creating padding string returned a null pointer.");
	if (prefix == 1)
		padding[0] = sign;
	if(!(new_nb = ft_strjoin(padding, tmp)))
		ft_error("creating precision string returned a null pointer.");
	ft_strdel(&padding);
	ft_strdel(&nb);
	ft_strdel(&tmp);
	return (new_nb);
}

char *add_padding(char *nb, unsigned int padding)
{
	size_t len;
	char sign;
	char *new_nb;

	len = ft_strlen(nb);
	sign = nb[0];
	if (sign == '-' || sign == ' ' || sign == '+')
		len--;
	if (len < padding)
		new_nb = create_new_nb(nb, len, sign, padding);
	else
		new_nb = nb;
	return (new_nb);
}
