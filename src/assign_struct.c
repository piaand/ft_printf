/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 08:51:13 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/19 09:47:48 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

/*
** space ignored when plus, 0 ignored when minus
*/

void	check_flag_override(t_tag **t)
{
	t_tag *new;

	new = *t;
	if (new->space == 1 && new->plus == 1)
		new->space = 0;
	if (new->zero == 1 && new->dash == 1)
		new->zero = 0;
}

char	*init_newstring(size_t len, char c)
{
	char *str;

	if (!(str = ft_strnew(len)))
		ft_error("memory allocation for string failed.");
	ft_memset(str, c, (len * sizeof(char)));
	return (str);
}

void	init_tag(t_tag **t)
{
	char *status;
	char *len;
	t_tag *new;

	new = *t;
	status = init_newstring(4, '0');
	new->has_value = status;
	len = init_newstring(2, '0');
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
void insert_length(t_tag **new, char **str)
{
	i++;
		while (is_digit(tag[i]) && tag[i] != '\0')
		{
			//do atoi for precision, if no digits then precision 0
		}
}

void insert_precision(t_tag **new, char **str)
{
	i++;
		while (is_digit(tag[i]) && tag[i] != '\0')
		{
			//do atoi for precision, if no digits then precision 0
		}
}

*/
void	insert_width(t_tag **new, char **str) 
{
	char *nb;
	size_t len;
	int res;

	len = 0;
	res = 0;
	if (ft_isdigit(*(*str)) && *str != '\0')
	{
		(*new)->has_value[WIDTH_ON] = '1';
		while (ft_isdigit(*(*str)) && *str != '\0')
		{
			len++;
			(*str)++;
		}
		if (!(nb = ft_strnew(len)))
			ft_error("memory allocation for string failed.");
		while (len > 0)
		{
			(*str)--;
			len--;
		}
		while (ft_isdigit(*(*str)) && *str != '\0')
		{
			nb[len] = *(*str);
			(*str)++;
			len++;
		}
		res = ft_atoi(nb);
		(*new)->width = res;
	}
}

void	insert_flags(t_tag **t, char **str)
{
	t_tag *new;
	int flag_done;
	char *found;

	new = *t;
	flag_done = 0;
	while (flag_done == 0 && *str != '\0')
	{
		found = ft_strchr(FLAGS, *(*str));
		if (found)
		{
			new->has_value[FLAG_ON] = '1';
			if (*found == '#')
				new->hash = 1;
			else if (*found == ' ')
				new->space = 1;
			else if (*found == '-')
				new->dash = 1;
			else if (*found == '+')
				new->plus = 1;
			else if (*found == '0')
				new->zero = 1;
			else
				ft_error("met unknown flag.");
			(*str)++;
		}
		else
			flag_done = 1;
	}
	found = NULL;
}

void	assign_tag_info(t_tag **new, char *instructions)
{
	int i;
	char *found;

	found = NULL;
	i = 0;
	init_tag(new);
	insert_flags(new, &instructions);
	check_flag_override(new);
	insert_width(new, &instructions);/*
	if (*instructions == '.')
		insert_precision(new, &instructions);
	if (*instructions == 'h' || *instructions == 'l' || *instructions == 'L')
		insert_length(new, &instructions);*/
	found = ft_strchr(SPECIFIERS, *instructions);
	if (!found)
		ft_error("unvalid format tag.");
	else
		(*new)->specifier = *found;
}

/* ADD HERE UNIT TESTS FOR STRUCT */


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
	char tag[] = "-20s";

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
