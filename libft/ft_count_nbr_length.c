/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nbr_length.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:12:33 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:24:05 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** counts how many characters the number takes - including the negative sign.
*/

#include "includes/libft.h"

size_t	ft_count_nbr_length(size_t i)
{
	size_t		n;
	size_t		len;

	n = i;
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
