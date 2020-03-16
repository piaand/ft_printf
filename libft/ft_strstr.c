/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:43:27 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:36:28 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_run_needle(const char *haystack, const char *needle, int i)
{
	int try;
	int j;

	try = 0;
	j = 0;
	while (needle[j] == haystack[i] && needle[j] != '\0'
	&& haystack[i] != '\0')
	{
		j++;
		i++;
	}
	if (needle[j] == '\0')
		try = 1;
	return (try);
}

static char	*ft_find_needle(const char *haystack, const char *needle)
{
	int i;
	int found;

	i = 0;
	while (haystack[i] != '\0')
	{
		found = ft_run_needle(haystack, needle, i);
		if (found == 1)
			return ((char*)&haystack[i]);
		else
			i++;
	}
	return (NULL);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0')
		return ((char*)haystack);
	else if (*haystack == '\0')
		return (NULL);
	else if (ft_strlen(needle) > ft_strlen(haystack))
		return (NULL);
	else
		return (ft_find_needle(haystack, needle));
}
