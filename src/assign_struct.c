/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 08:51:13 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/03 12:46:19 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_error(char *message)
{
	ft_putstr("Error: ");
	ft_putendl(message);
	ft_putendl("\nSystem exits.");
	exit(1);
}

/*
** space ignored when plus, 0 ignored when minus
*/

static void	check_flag_override(t_tag **t)
{
	t_tag *new;

	new = *t;
	if (new->space == 1 && new->plus == 1)
		new->space = 0;
	if (new->zero == 1 && new->dash == 1)
		new->zero = 0;
}

void		insert_flags(t_tag **new, char **str)
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

static void	init_tag(t_tag **t)
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

int		assign_tag_info(t_tag **new, char *instructions)
{
	int		i;
	char	*found;

	found = NULL;
	i = 0;
	init_tag(new);
	if (*new)
	{
		found = ft_strchr(FLAGS, *instructions);
		if (found)
			insert_flags(new, &instructions);
		if (ft_isdigit(*instructions) && *instructions != '\0')
			insert_width(new, &instructions);
		if (*instructions == '.')
			insert_precision(new, &instructions);
		if (*instructions == 'h' || *instructions == 'l' || *instructions == 'L')
			insert_length(new, &instructions);
		found = ft_strchr(SPECIFIERS, *instructions);
		if (!found)
			ft_error("unvalid format tag.");
		else
			(*new)->specifier = *found;
		return (1);
	}
	else
		return (-1);
	
}

/* ADD HERE UNIT TESTS FOR STRUCT */

/*
void	print_flags(t_tag **new)
{
	t_tag *t;

	t = *new;
	ft_putendl("Found following flags");
	ft_putnbr(t->hash);
	ft_putendl(" :hash\n");
	ft_putnbr(t->zero);
	ft_putendl(" :zero\n");
	ft_putnbr(t->dash);
	ft_putendl(" :dash\n");
	ft_putnbr(t->plus);
	ft_putendl(" :plus\n");
	ft_putnbr(t->space);
	ft_putendl(" :space\n");
	ft_putendl("Done printing flags");
}

int	main(int argc, char **argv)
{
	t_tag *new;
	int i;
	char tag[] = "-.Lu";

	if (!(new = (t_tag*)ft_memalloc(sizeof(t_tag))))
		ft_error("memory allocation for tag failed.");
	if (argc == 2)
	{
		argv = NULL;
		assign_tag_info(&new, tag);
		ft_putendl("Printing info on struct that was given format tag:");
		ft_putendl(tag);
		ft_putendl("Struct values");
		ft_putstr("specifier: ");
		ft_putendl(&(new->specifier));
		ft_putstr("format tag values: ");
		ft_putendl(new->has_value);
		i = 0;
		while (new->has_value[i] != '\0')
		{
			if (new->has_value[i] == '1')
			{
				if (i == 0)
					print_flags(&new);
				else if (i == 1)
				{
					ft_putendl("Print width:");
					ft_putnbr(new->width);
					ft_putendl(" ");
				}
				else if (i == 2)
				{
					ft_putendl("Print precision:");
					ft_putnbr(new->precision);
					ft_putendl(" ");
				}
				else if (i == 3)
				{
					ft_putendl("Print length:");
					ft_putstr(new->length);
					ft_putendl(" ");
				}
				else
					ft_putendl("this should not happen, there is only 4 chars");
			}
			i++;
		}
		ft_putendl("Done with printing");
	}
	else
		ft_putendl("give only one argument");
	return(0);
}
*/