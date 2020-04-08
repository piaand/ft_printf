/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 12:12:29 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/08 12:58:05 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned int	print_margin(char *nb, unsigned int margin)
{
	if (!(nb = ft_strset(margin, ' ')))
		return (-1);
	ft_putstr(nb);
	ft_strdel(&nb);
	return (margin);
}

static long long	print_empty_signed(t_tag **format, unsigned int margin)
{
	char		*tmp;
	char		*nb;
	long long	len;

	if (!(tmp = ft_strset(1, '1')))
		return (-1);
	if (!(tmp = format_integer(tmp, format)))
		return (-1);
	nb = NULL;
	len = ft_strlen(tmp);
	if (len == 1 && margin > 0)
		len = print_margin(nb, margin);
	else if (len == 1)
		len = 0;
	else
	{
		len--;
		nb = ft_strsub(tmp, 0, len);
		nb = create_margin(format, nb, 0);
		len = print_final_string(format, nb, 0);
	}
	ft_strdel(&tmp);
	return (len);
}

static long long	print_empty_unsigned(t_tag **format, unsigned int margin)
{
	char		*nb;
	long long	len;

	nb = "";
	nb = format_unsigned(format, nb);
	if (!nb)
		return (-1);
	if (ft_strequ(nb, "") && margin > 0)
		len = print_margin(nb, margin);
	else if (ft_strequ(nb, ""))
		len = 0;
	else
		len = print_final_string(format, nb, 0);
	return (len);
}

long long	empty_number(t_tag **format)
{
	char			specifier;
	long long		len;
	unsigned int	margin;

	specifier = (*format)->specifier;
	margin = (*format)->width;
	if (specifier == 'd' || specifier == 'i')
		len = print_empty_signed(format, margin);
	else
		len = print_empty_unsigned(format, margin);
	return (len);
}
