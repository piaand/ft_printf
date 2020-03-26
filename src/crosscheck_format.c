/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosscheck_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 09:41:24 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/26 10:02:07 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
