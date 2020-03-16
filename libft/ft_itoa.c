/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 08:31:49 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:26:38 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_count_digits(long n)
{
	int len;

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

char		*ft_itoa(int n)
{
	char	*ascii;
	long	i;
	int		len;

	i = n;
	len = ft_count_digits(i);
	if (!(ascii = ft_strnew(len)))
		return (NULL);
	if (i < 0)
	{
		ascii[0] = '-';
		i *= -1;
	}
	else if (i == 0)
		ascii[0] = '0';
	while (i > 0)
	{
		ascii[--len] = (i % 10) + '0';
		i /= 10;
	}
	return (ascii);
}
