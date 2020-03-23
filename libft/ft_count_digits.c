/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 11:36:00 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/23 16:13:11 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** counts how many digits the number takes - excluding the negative sign.
*/

#include "includes/libft.h"

unsigned int	ft_count_digits(size_t n, int base)
{
	size_t len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= base;
	}
	return (len);
}
