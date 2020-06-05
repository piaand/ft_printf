/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_deattached.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 09:07:50 by piaandersin       #+#    #+#             */
/*   Updated: 2020/03/30 09:03:46 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>

int main() {

	char kissa[] = "Mustan kissan paksut posket";
	char c;
	short int i;
	int num;
	long long_num;
	long long longer_num;
	float dec;
	double bb;
	long double long_bb;
	
	c = 'p';
	i = 14000;
	num = 62;
	long_num = 1000;
	longer_num = 1000;
	dec = -100;
	bb = 0.00995;
	long_bb = 0.0099555551111222444;
	printf("This testfile is a deattached file to be used to see real printf configurations\n");
	printf("%.p\n", &kissa[3]);
	printf("%5.3X\n", i);
	printf("%#.f\n", dec);
	printf("%#.10lf\n", bb);
	printf("%.35Lf\n", long_bb);
	printf("testing length conversions in diouxX\n");
	printf("%i\n", num);
	printf("%li\n", long_num);
	printf("%lli\n", longer_num);
	printf("testing precision in diouxX\n");
	printf("%.6i\n", num);
	printf("%+.6i\n", num);
	printf("%.6o\n", num);
	printf("%0.6o\n", num);
	printf("%.6x\n", num);
	printf("%#.6x\n", num);
	return (0);
}