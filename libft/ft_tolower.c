/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:30:29 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:43:03 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_tolower(int c)
{
	if (!(ft_isalpha(c)))
		return (c);
	else
	{
		if (c >= 65 && c <= 90)
			return (c + 32);
		else
			return (c);
	}
}
