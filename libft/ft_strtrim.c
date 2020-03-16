/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:41:04 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:41:03 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*ft_trimsub(char const *s, size_t start, size_t end)
{
	char	*str;
	size_t	i;

	str = ft_strnew((end - start) + 1);
	if (str == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (start <= end)
		{
			str[i] = s[start];
			i++;
			start++;
		}
		return (str);
	}
}

char		*ft_strtrim(char const *s)
{
	size_t	end;
	size_t	start;
	size_t	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	if (s[start] == '\0')
		return (ft_strnew(1));
	while (s[i] != '\0')
		i++;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0')
		i--;
	end = i;
	return (ft_trimsub(s, start, end));
}
