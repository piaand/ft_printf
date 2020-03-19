/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 11:30:01 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/19 15:05:28 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/includes/libft.h"

# define SPECIFIERS "diouxXcspf"
# define FLAGS "#0-+ "
# define FLAG_ON 0
# define WIDTH_ON 1
# define PRECISION_ON 2
# define LENGTH_ON 3


typedef struct			s_tag
{
	char				*has_value;
	char				specifier;
	int					hash;
	int					space;
	int					zero;
	int					dash;
	int					plus;
	unsigned int		width;
	unsigned int		precision;
	char				*length;
}						t_tag;

int		ft_printf(const char *format, ...);
void	ft_error(char *message);
void	assign_tag_info(t_tag **new, char *instructions);
int		print_next_var(t_tag **format, va_list args);

# endif