/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 11:05:33 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/26 15:07:54 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <limits.h> 

int main() {

	int base;
	long long int i;
	int p;
	char *str;
	char *str2;
	long double f;
	
	f = -55.0000789;
	i = LLONG_MIN + 0;
	p = 24;
	base = 10;
	ft_putendl("Before itoa");
	str = ft_itoa_base(i, base);
	ft_putstr("Resut from ft_itoa_base: ");
	ft_putendl(str);
	printf("Number: %lld, base %d\n", i, base);
	printf("Printf conversion for i says hexa: %llX\n", i);
	printf("Printf conversion for i says octal: %llo\n", i);
	ft_putendl("Ft_float_to_a:");
	printf("The float to print: %Lf with precision %d\n", f, p);
	str2 = ft_float_to_a(f, p);
	ft_putendl("Result:");
	ft_putendl(str2);
	printf("The float to print: %.24Lf\n", f);
	return (0);
}
