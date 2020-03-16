/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:42:01 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:43:50 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_run_needle(const char *haystack, const char *needle, int i,
size_t len)
{
	int		try;
	size_t	j;

	try = 0;
	j = 0;
	while (needle[j] == haystack[i] && needle[j] != '\0'
	&& haystack[i] != '\0' && (j + i) < len)
	{
		j++;
		i++;
	}
	if (needle[j] == '\0')
		try = 1;
	return (try);
}

static char	*ft_find_needle(const char *haystack, const char *needle,
size_t len)
{
	size_t	i;
	int		found;

	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		found = ft_run_needle(haystack, needle, i, len);
		if (found == 1)
			return ((char*)&haystack[i]);
		else
			i++;
	}
	return (NULL);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char*)haystack);
	else if (*haystack == '\0')
		return (NULL);
	else if (ft_strlen(needle) > len)
		return (NULL);
	else
		return (ft_find_needle(haystack, needle, len));
}
