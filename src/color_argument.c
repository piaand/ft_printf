/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 10:11:54 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/08 10:54:25 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Prints the color tag pointed by color index. Moves the printf input pointer
** the amount of the color tag characters and does not print it out.
*/

static void	print_color(int color, char **input, char *tag)
{
	size_t	len;
	char	*colors[7];

	colors[0] = RED;
	colors[1] = GREEN;
	colors[2] = YELLOW;
	colors[3] = BLUE;
	colors[4] = MAGENTA;
	colors[5] = CYAN;
	colors[6] = EOC;
	len = ft_strlen(tag);
	while (len-- > 0)
		(*input)++;
	ft_putstr(colors[color]);
}

/*
** Returns the tag found between two brackets {}. If right formatted tag is not
** found returns string "(not found)" instead.
*/

static char	*find_color_tag(const char **input)
{
	size_t	len;
	char	*tag;
	char	*tmp;

	if (!(tmp = ft_strnew(ft_strlen(*input))))
		return (NULL);
	tmp = ft_strcpy(tmp, *input);
	len = 0;
	while (tmp[len] != '\0' && tmp[len] != '%' && tmp[len] != '}')
		len++;
	if (tmp[len] == '}')
	{
		len++;
		tag = ft_strsub(tmp, 0, len);
	}
	else
		tag = ft_strdup("(not found)");
	ft_strdel(&tmp);
	return (tag);
}

/*
** Takes the color printing tag and sees weather it matches with any allowed
** printing colors. Returns the index of matching print color or -1 if match
** was not found.
*/

static int	match_color_tag(char *tag)
{
	char	*colors[7];
	int		i;

	colors[0] = "{red}";
	colors[1] = "{green}";
	colors[2] = "{yellow}";
	colors[3] = "{blue}";
	colors[4] = "{magenta}";
	colors[5] = "{cyan}";
	colors[6] = "{eoc}";
	i = 0;
	while (i >= 0 && i < 7)
	{
		if (ft_strequ(tag, colors[i]))
			break ;
		else
			i++;
	}
	if (i == 7)
		return (-1);
	else
		return (i);
}

/*
** Takes the ft_printf input and reads the tag that gives the information on
** what color to print. Returns 0 when color printing was done correctly,
** 1 when color tag was not correct and -1 when unexpected error happened.
*/

int			color_argument(const char **input)
{
	char	*tag;
	int		verify;
	int		print;

	if (!(tag = find_color_tag(input)))
		return (-1);
	if (!(ft_strequ(tag, "(not found)")))
	{
		verify = match_color_tag(tag);
		if (verify >= 0)
		{
			print_color(verify, input, tag);
			ft_strdel(&tag);
			return (0);
		}
	}
	ft_strdel(&tag);
	ft_putchar('{');
	(*input)++;
	return (1);
}
