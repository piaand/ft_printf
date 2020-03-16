/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:16:21 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:43:58 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	if ((!s1) && (!s2) && (!n))
		return (0);
	i = ft_strncmp(s1, s2, n);
	if (i == 0)
		return (1);
	else
		return (0);
}
