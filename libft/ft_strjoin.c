/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:19:42 by pandersi          #+#    #+#             */
/*   Updated: 2020/04/01 17:18:20 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*temp;
	int		len;

	if ((!s1) && (!s2))
		return (NULL);
	len = (s1) ? ft_strlen(s1) : 0;
	len = (s2) ? len + ft_strlen(s2) : len;
	len++;
	if (!(join = ft_strnew(len)))
		return (NULL);
	temp = join;
	while (s1 && *s1 != '\0')
	{
		*join = *s1;
		join++;
		s1++;
	}
	while (s2 && *s2 != '\0')
	{
		*join = *s2;
		join++;
		s2++;
	}
	return (temp);
}
