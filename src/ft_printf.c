/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 11:59:19 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/07 17:16:53 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	free_format_tag(t_tag *format)
{
	if (format)
	{
		ft_strdel(&(format->has_value));
		ft_strdel(&(format->length));
		free(format);
	}
}

char	*find_tag(const char **str)
{
	char			*format_tag;
	char			*temp;
	char			*found;
	unsigned int	i;

	format_tag = NULL;
	if (!(temp = ft_strnew(ft_strlen(*str))))
		return (NULL);
	temp = ft_strcpy(temp, *str);
	if (temp[0] == '%')
		format_tag = ft_strsub(temp, 0, 1);
	else
	{
		i = 0;
		found = NULL;
		while (!found && temp[i] != '%' && temp[i] != '\0')
			found = ft_strchr(SPECIFIERS, temp[i++]);
		if (!found)
			ft_error("unvalid specifier.");
		else
			format_tag = ft_strsub(temp, 0, i);
	}
	ft_strdel(&temp);
	return (format_tag);
}

int		print_from_var_list(char *format_tag, va_list args)
{
	t_tag	*new;
	int		len;
	int		ok;

	ok = 0;
	len = 0;
	if (!(new = (t_tag*)ft_memalloc(sizeof(t_tag))))
	{
		ft_strdel(&format_tag);
		return (-1);
	}
	ok = assign_tag_info(&new, format_tag);
	ft_strdel(&format_tag);
	if (ok < 0)
		return (-1);
	crosscheck_format(&new);
	len = print_next_var(&new, args);
	free_format_tag(new);
	return (len);
}

/*
** Returns the amount of printed argument characters
*/

int		print_argument(const char **input, va_list args)
{
	char	*format_tag;
	int		len_var;
	size_t	i;

	(*input)++;
	if (!(format_tag = find_tag(input)))
		return (-1);
	i = 0;
	while (i < ft_strlen(format_tag))
	{
		(*input)++;
		i++;
	}
	if (format_tag[0] == '%')
	{
		ft_putchar('%');
		len_var = 1;
		ft_strdel(&format_tag);
	}
	else
		len_var = print_from_var_list(format_tag, args);
	return (len_var);
}

char *find_color_tag(const char **input)
{
	size_t len;
	char *tag;
	char *tmp;

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

int		match_color_tag(char *tag)
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
			break;
		else
			i++;
	}
	if (i == 7)	
		return (-1);
	else
		return (i);
}

int 	color_argument(const char **input)
{
	char	*tag;
	int		verify;
	size_t	len;
	char	*colors[7];

	colors[0] = RED;
	colors[1] = GREEN;
	colors[2] = YELLOW;
	colors[3] = BLUE;
	colors[4] = MAGENTA;
	colors[5] = CYAN;
	colors[6] = EOC;

	if (!(tag = find_color_tag(input)))
		return (-1);
	if (!(ft_strequ(tag, "(not found)")))
	{
		verify = match_color_tag(tag);
		if (verify >= 0)
		{
			len = ft_strlen(tag);
			while (len-- > 0)
				(*input)++;
			ft_putstr(colors[verify]);
			ft_strdel(&tag);
			return (0);
		}
	}
	ft_strdel(&tag);
	ft_putchar('{');
	(*input)++;
	return (1);
}

/*
** Returns the amount of printed characters
*/

int		ft_printf(const char *format, ...)
{
	size_t	len;
	size_t	len_var;
	va_list	args;

	len = 0;
	len_var = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		while (*format != '%' && *format != '{' && *format != '\0')
		{
			ft_putchar(*format);
			len++;
			format++; //move this maybe inside putchar?
		}
		if (*format == '%')
			len_var = print_argument(&format, args);
		else if (*format == '{')
			len_var = color_argument(&format);
		if (len_var < 0)
			return (-1);
		else
			len += len_var;
		len_var = 0;
	}
	va_end(args);
	return (len);
}
