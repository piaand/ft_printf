/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:23:02 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:44:09 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_toupper(int c)
{
	if (!(ft_isalpha(c)))
		return (c);
	else
	{
		if (c >= 97 && c <= 122)
			return (c - 32);
		else
			return (c);
	}
}
