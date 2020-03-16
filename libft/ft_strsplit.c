/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandersi <pandersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:14:46 by pandersi          #+#    #+#             */
/*   Updated: 2019/11/11 15:41:53 by pandersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char			*ft_form_str(char const *s, char c, size_t *i)
{
	char			*str;
	size_t			j;
	size_t			k;
	unsigned int	len;

	j = *i;
	while (s[j] != c && s[j] != '\0')
		j++;
	len = j - *i;
	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	else
	{
		k = 0;
		j = *i;
		while (k < len)
		{
			str[k] = s[j];
			k++;
			j++;
		}
		*i = j;
		return (str);
	}
}

static char			**ft_split(char **array, char const *s, char c,
unsigned int words)
{
	char			*str;
	unsigned int	n;
	size_t			i;

	n = 0;
	i = 0;
	while (n < words && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			str = ft_form_str(s, c, &i);
			if (str == NULL)
				return (NULL);
			else
				array[n] = str;
			n++;
		}
		if (s[i] != '\0')
			i--;
		i++;
	}
	array[words] = NULL;
	return (array);
}

static unsigned int	ft_count_words(char const *s, char c)
{
	unsigned int	count;
	size_t			i;
	int				found;

	i = 0;
	count = 0;
	found = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			found = 1;
			i++;
		}
		if (found)
		{
			count++;
			found = 0;
		}
	}
	return (count);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**array;
	unsigned int	n;

	if (!s || !c)
		return (NULL);
	n = ft_count_words(s, c);
	array = (char**)ft_memalloc(sizeof(char*) * n + 2);
	if (array == NULL || !array)
		return (NULL);
	else if (n == 0)
	{
		array[n] = NULL;
		return (array);
	}
	else
	{
		array = ft_split(array, s, c, n);
		return (array);
	}
}
