/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 11:59:19 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/16 13:17:31 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/* #include "../libft/includes/libft.h" */

int ft_printf(const char *format, ...) {
	ft_putstr("Inside ft_printf.c\n");
	ft_putstr(format);
	return (1);
}
