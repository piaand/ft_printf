/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 11:30:01 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/08 10:13:00 by piaandersin      ###   ########.fr       */
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
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define EOC "\x1b[0m"


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

int				ft_printf(const char *format, ...);
void			free_format_tag(t_tag *format);
void			ft_error(char *message);
int				assign_tag_info(t_tag **new, char *instructions);
int				insert_width(t_tag **new, char **str);
int				insert_precision(t_tag **new, char **str);
void			insert_length(t_tag **new, char **str);
int				print_next_var(t_tag **format, va_list args);
int				print_integer(t_tag **format, va_list args);
int				print_unsigned(t_tag **format, va_list args);
int				print_float(t_tag **format, va_list args);
long long		empty_number(t_tag **format);
void			crosscheck_format(t_tag **format);
char 			*format_unsigned(t_tag **format, char *print_unsigned);
size_t 			print_final_string(t_tag **format, char *str, int char_null);
char			*create_padding(char *nb, unsigned int space, unsigned int precision);
char 			*create_margin(t_tag **format, char *str, int char_null);
char 			*add_padding(char *nb, unsigned int padding);
char			*add_prefix(char *nb, unsigned int len, char *str);
char 			*add_margin(char *str, unsigned int width, unsigned int left_align, int char_null);
char			*add_decimal(char *nb);
unsigned int	check_prefix(char *prefix);
int				color_argument(const char **input);


# endif