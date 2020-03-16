/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:56:14 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:35:57 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	if ((!s1) && (!s2))
		return (0);
	i = ft_strcmp(s1, s2);
	if (i == 0)
		return (1);
	else
		return (0);
}
