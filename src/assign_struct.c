/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 08:51:13 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/08 17:44:49 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** space ignored when plus, 0 ignored when minus
*/

static void		check_flag_override(t_tag **t)
{
	t_tag *new;

	new = *t;
	if (new->space == 1 && new->plus == 1)
		new->space = 0;
	if (new->zero == 1 && new->dash == 1)
		new->zero = 0;
}

static void		insert_flags(t_tag **new, char **str)
{
	int		flag_done;
	char	*found;

	(*new)->has_value[FLAG_ON] = '1';
	flag_done = 0;
	while (flag_done == 0 && *str != '\0')
	{
		if ((found = ft_strchr(FLAGS, *(*str))))
		{
			if (*found == '#')
				(*new)->hash = 1;
			else if (*found == ' ')
				(*new)->space = 1;
			else if (*found == '-')
				(*new)->dash = 1;
			else if (*found == '+')
				(*new)->plus = 1;
			else if (*found == '0')
				(*new)->zero = 1;
			(*str)++;
		}
		else
			flag_done = 1;
	}
	check_flag_override(new);
}

static void		init_tag(t_tag **t)
{
	char	*status;
	char	*len;
	t_tag	*new;

	new = *t;
	if (!(status = ft_strset(4, '0')))
		new = NULL;
	new->has_value = status;
	if (!(len = ft_strset(2, '0')))
		new = NULL;
	new->length = len;
	new->hash = 0;
	new->space = 0;
	new->zero = 0;
	new->dash = 0;
	new->plus = 0;
	new->width = 0;
	new->precision = 0;
}

/*
** Reads the printf input and returns 0 when struct is assigned or
** -1 with error. If format tag is not undefined exits the program.
*/

static int		read_info(t_tag **new, char *instructions)
{
	char	*found;
	int		ok;

	found = NULL;
	ok = 0;
	found = ft_strchr(FLAGS, *instructions);
	if (found)
		insert_flags(new, &instructions);
	if (ft_isdigit(*instructions) && *instructions != '\0')
		ok = insert_width(new, &instructions);
	if (ok >= 0 && *instructions == '.')
		ok = insert_precision(new, &instructions);
	if (ok >= 0 && (*instructions == 'h' || *instructions == 'l' ||
	*instructions == 'L'))
		insert_length(new, &instructions);
	found = ft_strchr(SPECIFIERS, *instructions);
	if (!found)
		ft_error("unvalid format tag.");
	else
		(*new)->specifier = *found;
	return (ok);
}

/*
** Inits the t_tag structs and assigns all the information from printf
** input to it. Returns 1 on success and -1 when error happens.
*/

int				assign_tag_info(t_tag **new, char *instructions)
{
	int	ok;

	init_tag(new);
	if (*new)
	{
		ok = read_info(new, instructions);
		if ((*new)->length == NULL || ok < 0)
		{
			free_format_tag(*new);
			return (-1);
		}
		return (1);
	}
	else
		return (-1);
}
