/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 08:51:13 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/18 11:01:45 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"
/*
void insert_flag(char flag) {
	// insert all flgs to struct
}

void	assign_struct(char *tag)
{
	int i;
	int flag_done;
	char *found;

	found = NULL;
	flag_done = 0;
	i = 0;
	while (flag_done == 0 && tag[i] != '\0')
	{
		found = ft_strchr(FLAGS, tag[i]);
		if (found)
		{
			insert_flag(tag[i]);
			i++;
		}
		else
			flag_done = 1;
	}
	while (is_digit(tag[i]) && tag[i] != '\0')
	{
		i++;
		//do atoi to get the number, what about 0 in the beginning?
	}
	if (tag[i] == '.')
	{
		i++;
		while (is_digit(tag[i]) && tag[i] != '\0')
		{
			//do atoi for precision, if no digits then precision 0
		}
	}
	if (tag[i] == 'h' || tag[i] == 'l' || tag[i] == 'L')
	{
		// do length modifiers
	}
	found = ft_strchr(SPECIFIERS, tag[i]);
	if (!found)
	{
		ft_putendl("Error: unvalid format tag.")
		exit(1);
	}
	else
		insert_specifier(tag[i]);
}*/