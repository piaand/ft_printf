/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:19:42 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:41:12 by pandersi         ###   ########.fr       */
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
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(join = ft_strnew(len)))
		return (NULL);
	temp = join;
	while (*s1 != '\0')
	{
		*join = *s1;
		join++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*join = *s2;
		join++;
		s2++;
	}
	return (temp);
}
