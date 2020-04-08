/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 11:57:42 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/08 17:32:15 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** Returns the index value of a first occurrance of character c
** if the c is not in the string s, returns -1
*/

long long	ft_strchri(const char *s, int c)
{
	long long i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		else
			i++;
	}
	if (s[i] == c)
		return (i);
	else
		return (-1);
}
