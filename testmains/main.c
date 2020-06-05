/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 11:54:30 by piaandersin       #+#    #+#             */
/*   Updated: 2020/04/08 17:41:32 by piaandersin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

/*void undefined()
{
	char *str = "Hello World";
	char	*test;
	void	*pointer;
	int 	a;
	long long int lli = 55165;
	long long int lli_n = -55165;
	int 	i = 3;
	int		i_n = -3;
	unsigned long long int 	llu = 55165;
 	unsigned long long int 	llu_m = 18446744073709551615;
 	unsigned int			u = 3;
	long long int llu_n = -55165;
 	int	u_n = -3;
	long double lf = 432232342.0193840923840982309580927350274;
	long double lf_n = -432232342.0193840923840982309580927350274;
	double f = 432232342.01938409238;
	double f_n = -432232342.01938409238;

	pointer = &test;
	printf("PRINTF: \n'%0.p'\n'%.p'\n", 0, 0);
	ft_printf("FT_PRINTF: \n'%0.p'\n'%.p'\n", 0, 0);
	ft_printf("'%10 p'\n", &test);
 	printf("'%10 p'\n", &test);
	ft_printf("'% p'\n", &test);
 	printf("'% p'\n", &test);
	ft_printf("\nUNDEFINED BEHAVIOUR ZERO: \n'%020p'\n", &a);
 	printf("\nUNDEFINED BEHAVIOUR ZERO: \n'%020p'\n", &a);
	ft_printf("'%-015s'\n'%15c'\n", str, str);
 	printf("'%-015s'\n'%15c'\n", str, str);
 	ft_printf("'%-10 i'\n'%-10 lli'\n", i, lli);
 	printf("'%-10 i'\n'%-10 lli'\n", i, lli);
 	ft_printf("'%-10 i'\n'%-10 lli'\n", i_n, lli_n);
 	printf("'%-10 i'\n'%-10 lli'\n", i_n, lli_n);
	ft_printf("'%10 i'\n'%10 lli'\n", i, lli);
 	printf("'%10 i'\n'%10 lli'\n", i, lli);
	ft_printf("'%+0*.5d'\n", 10, i);
 	printf("'%+0*.5d'\n", 10, i);
	ft_printf("\n****** TEST #7 - o ******\n\n");
 	ft_printf("'%+#.30o'\n'%+#ll.30o'\n", i, lli);
 	printf("'%+#.30o'\n'%+#ll.30o'\n", i, lli);
	
 	ft_printf("\n****** TEST #8 - o ******\n\n");
 	ft_printf("'%+.30o'\n'%+ll.30o'\n", i, lli);
 	printf("'%+.30o'\n'%+ll.30o'\n", i, lli);
	ft_printf("\n****** TEST #19 ******\n\n");
 	ft_printf("'%-+050.o'\n'%-+050ll.o'\n", i, lli);
 	printf("'%-+050.o'\n'%-+050ll.o'\n", i, lli);

 	ft_printf("\n****** TEST #20 ******\n\n");
 	ft_printf("'%-+050.0o'\n'%-+050ll.0o'\n", i, lli);
 	printf("'%-+050.0o'\n'%-+050ll.0o'\n", i, lli);
	ft_printf("\n****** TEST #7 ******\n\n");
 	ft_printf("'%+#.30o'\n'%+#ll.30o'\n", i, lli);
 	printf("'%+#.30o'\n'%+#ll.30o'\n", i, lli);
	
 	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%+.30o'\n'%+ll.30o'\n", i, lli);
 	printf("'%+.30o'\n'%+ll.30o'\n", i, lli);

	ft_printf("\n****** TEST #19 ******\n\n");
 	ft_printf("'%-+050.o'\n'%-+050ll.o'\n", i, lli);
 	printf("'%-+050.o'\n'%-+050ll.o'\n", i, lli);

 	ft_printf("\n****** TEST #20 ******\n\n");
 	ft_printf("'%+050.0o'\n'%+050ll.0o'\n", i, lli);
 	printf("'%+050.0o'\n'%+050ll.0o'\n", i, lli);

	ft_printf("\n****** TEST #5 ******\n\n");
 	ft_printf("'%-10 u'\n'%-10 llu'\n", u, llu);
 	printf("'%-10 u'\n'%-10 llu'\n", u, llu);

	ft_printf("\n****** TEST #11 ******\n\n");
 	ft_printf("'%-10 u'\n'%-10 llu'\n", u_n, llu_n);
 	printf("'%-10 u'\n'%-10 llu'\n", u_n, llu_n);
	ft_printf("\n****** TEST #3 ******\n\n");
 	ft_printf("'%10 u'\n'%10 llu'\n", u, llu);
 	printf("'%10 u'\n'%10 llu'\n", u, llu);
	 
	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%+0*.5u'\n", 10, u);
 	printf("'%+0*.5u'\n", 10, u);
	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%+.30x'\n'%+ll.30x'\n", i, lli);
 	printf("'%+.30x'\n'%+ll.30x'\n", i, lli);
	ft_printf("\n****** TEST #7 ******\n\n");
 	ft_printf("'%+#.30x'\n'%+#ll.30x'\n", i, lli);
 	printf("'%+#.30x'\n'%+#ll.30x'\n", i, lli);
	ft_printf("\n****** TEST #19 ******\n\n");
 	ft_printf("'%-+050.x'\n'%-+050ll.x'\n", i, lli);
 	printf("'%-+050.x'\n'%-+050ll.x'\n", i, lli);

 	ft_printf("\n****** TEST #20 ******\n\n");
 	ft_printf("'%-+050.0x'\n'%-+050ll.0x'\n", i, lli);
 	printf("'%-+050.0x'\n'%-+050ll.0x'\n", i, lli);
	ft_printf("\n****** TEST #7 ******\n\n");
 	ft_printf("'%+#.30X'\n'%+#ll.30X'\n", i, lli);
 	printf("'%+#.30X'\n'%+#ll.30X'\n", i, lli);
	
 	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%+.30X'\n'%+ll.30X'\n", i, lli);
 	printf("'%+.30X'\n'%+ll.30X'\n", i, lli);
	ft_printf("\n****** TEST #19 ******\n\n");
 	ft_printf("'%-+050.X'\n'%-+050ll.X'\n", i, lli);
 	printf("'%-+050.X'\n'%-+050ll.X'\n", i, lli);

 	ft_printf("\n****** TEST #20 ******\n\n");
 	ft_printf("'%+050.0X'\n'%+050ll.0X'\n", i, lli);
 	printf("'%+050.0X'\n'%+050ll.0o'\n", i, lli);

	ft_printf("\n****** TEST #1 ******\n\n");
	ft_printf("'%-.*Lf'\n", 50,lf);
	printf("'%-.*Lf'\n", 50,lf);

	ft_printf("\n****** TEST #2 ******\n\n");
	ft_printf("'%-.*Lf'\n", 50,lf_n);
	printf("'%-.*Lf'\n", 50,lf_n);
	ft_printf("\n****** TEST #16 ******\n\n");
 	ft_printf("'%-10 f'\n'%-10 Lf'\n", f, lf);
 	printf("'%-10 f'\n'%-10 Lf'\n", f, lf);
	ft_printf("\n****** TEST #23 ******\n\n");
 	ft_printf("'%-10 f'\n'%-10 Lf'\n", f_n, lf_n);
 	printf("'%-10 f'\n'%-10 Lf'\n", f_n, lf_n);
	ft_printf("\n****** TEST #1 ******\n\n");
	ft_printf("'%.*Lf'\n", 50,lf);
	printf("'%.*Lf'\n", 50,lf);

	ft_printf("\n****** TEST #2 ******\n\n");
	ft_printf("'%.*Lf'\n", 50,lf_n);
	printf("'%.*Lf'\n", 50,lf_n);
	ft_printf("\n****** TEST #16 ******\n\n");
 	ft_printf("'%10 f'\n'%10 Lf'\n", f, lf);
 	printf("'%10 f'\n'%10 Lf'\n", f, lf);
	ft_printf("\n****** TEST #23 ******\n\n");
 	ft_printf("'%10 f'\n'%10 Lf'\n", f_n, lf_n);
 	printf("'%10 f'\n'%10 Lf'\n", f_n, lf_n);
	
		ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%+#50.30o'\n'%+#50.30llo'\n", i, lli);
 	printf("'%+#50.30o'\n'%+#50.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #9 ******\n\n");
 	ft_printf("'%+50.30o'\n'%+50.30llo'\n", i, lli);
 	printf("'%+50.30o'\n'%+50.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%-+#50.30o'\n'%-+#50.30llo'\n", i, lli);
 	printf("'%-+#50.30o'\n'%-+#50.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%-+50.30o'\n'%-+50.30llo'\n", i, lli);	
 	printf("'%-+50.30o'\n'%-+50.30llo'\n", i, lli);	

 	ft_printf("\n****** TEST #11 ******\n\n");
 	ft_printf("'%-+#050.30o'\n'%-+#050.30llo'\n", i, lli);
 	printf("'%-+#050.30o'\n'%-+#050.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%+050.30o'\n'%+050.30llo'\n", i, lli);
 	printf("'%+050.30o'\n'%+050.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%-+#050.30o'\n'%-+#050.30llo'\n", i, lli);
 	printf("'%-+#050.30o'\n'%-+#050.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #14 ******\n\n");
 	ft_printf("'%-+050.30o'\n'%-+050.30llo'\n", i, lli);	
 	printf("'%-+050.30o'\n'%-+050.30llo'\n", i, lli);
	
	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%+#50.30o'\n'%+#50.30llo'\n", i, lli);
 	printf("'%+#50.30o'\n'%+#50.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #9 ******\n\n");
 	ft_printf("'%+50.30o'\n'%+50.30llo'\n", i, lli);
 	printf("'%+50.30o'\n'%+50.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%+#50.30o'\n'%+#50.30llo'\n", i, lli);
 	printf("'%+#50.30o'\n'%+#50.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%+50.30o'\n'%+50.30llo'\n", i, lli);	
 	printf("'%+50.30o'\n'%+50.30llo'\n", i, lli);	

 	ft_printf("\n****** TEST #11 ******\n\n");
 	ft_printf("'%+#050.30o'\n'%+#050.30llo'\n", i, lli);
 	printf("'%+#050.30o'\n'%+#050.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%+050.30o'\n'%+050.30llo'\n", i, lli);
 	printf("'%+050.30o'\n'%+050.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%+#050.30o'\n'%+#050.30llo'\n", i, lli);
 	printf("'%+#050.30o'\n'%+#050.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #14 ******\n\n");
 	ft_printf("'%+050.30o'\n'%+050.30llo'\n", i, lli);	
 	printf("'%+050.30o'\n'%+050.30llo'\n", i, lli);	

 	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'%+#050o'\n'%+#050llo'\n", i, lli);
 	printf("'%+#050o'\n'%+#050llo'\n", i, lli);
	
	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%+010u'\n'%+010llu'\n", u, llu);
 	printf("'%+010u'\n'%+010llu'\n", u, llu);

 	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'%010u'\n'%-+010.5u'\n", u, u);
 	printf("'%010u'\n'%-+010.5u'\n", u, u);
	
	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%+#050.30X'\n'%+#050.30llX'\n", i, lli);
 	printf("'%+#050.30X'\n'%+#050.30llX'\n", i, lli);
	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'%+#050X'\n'%+#050llX'\n", i, lli);
 	printf("'%+#050X'\n'%+#050llX'\n", i, lli);
}
*/
void cs()
{
	ft_printf("\n******************  TESTING ENVIRONMENT WITH %%s ******************\n\n");

 	char *str = "Hello World";
	int len;

 	ft_printf("'%s'\n", str);
	printf("'%s'\n", str);
	ft_printf("'%c'\n", 0);
	printf("'%c'\n", 0);
	ft_printf("'%10c'\n", 0);
	printf("'%10c'\n", 0);
	ft_printf("'%15s'\n", str);
	printf("'%15s'\n", str);
	ft_printf("'%-15s'\n'%15c'\n", str, *str);
 	printf("'%-15s'\n'%15c'\n", str, *str);
	len = printf("'hello, %s.'\n", NULL);
	printf("len: %d\n", len);
	len = ft_printf("'hello, %s.'\n", NULL);
	printf("len: %d\n", len);
	len = printf("'hello, %-20s.'\n", NULL);
	printf("len: %d\n", len);
	len = ft_printf("'hello, %-20s.'\n", NULL);
	printf("len: %d\n", len);
	len = printf("'hello, %.4s.'\n", NULL);
	printf("len: %d\n", len);
	len = ft_printf("'hello, %.4s.'\n", NULL);
	printf("len: %d\n", len);
	ft_printf("\n****** MOULITEST ******\n\n");
	len = ft_printf("%2c", 0);
	printf("len: %d\n", len);
	len = printf("%2c", 0);
	printf("len: %d\n", len);
	len = ft_printf("%.2c", NULL);
	printf("len: %d\n", len);
	len = printf("%.2c", NULL);
	printf("len: %d\n", len);
	len = ft_printf("@moulitest: %c", 0);
	printf("len: %d\n", len);
	len = printf("@moulitest: %c", 0);
	printf("len: %d\n", len);
	len = ft_printf("%10s is a string", "");
	printf("len: %d\n", len);
	len = printf("%10s is a string", "");
	printf("len: %d\n", len);

}

void p()
{
	ft_printf("\n******************  TESTING ENVIRONMENT WITH %%p ******************\n\n");

 	char	*test;
 	void	*pointer;
 	int		a;

 	pointer = &test;
	ft_printf("'%p'\n", pointer);
 	printf("'%p'\n", pointer);

 	ft_printf("'%p'\n", &test);
 	printf("'%p'\n", &test);
	ft_printf("'%15p'\n", &a);
 	printf("'%15p'\n", &a);
}

void id()
{
	long long int 	lli = 55165;
	long long int 	lli_n = -55165;
	int 			i = 3;
	int				i_n = -3;
	int len;
	
	ft_printf("\n****** TEST ******\n\n");
	ft_printf("'%+010d'\n'%+010lld'\n", i, lli);
 	printf("'%+010d'\n'%+010lld'\n", i, lli);
	ft_printf("\n****** TEST ******\n\n");
	ft_printf("'%+010d'\n'%+010lld'\n", i, lli_n);
 	printf("'%+010d'\n'%+010lld'\n", i, lli_n);
	ft_printf("\n****** TEST ******\n\n");
	ft_printf("'%010d'\n'%-010d'\n", i, i);
 	printf("'%010d'\n'%-010d'\n", i, i);
	ft_printf("\n****** TEST ******\n\n");
 	ft_printf("'%010d'\n'%-010d'\n", i, i);
 	printf("'%010d'\n'%-010d'\n", i, i);
	ft_printf("\n****** TEST ******\n\n");
	ft_printf("'%10.2d'\n'%-+010.5d'\n", i, i);
 	printf("'%10.2d'\n'%-+010.5d'\n", i, i);
	ft_printf("\n****** TEST ******\n\n");
	ft_printf("'%07i'\n", -54);
 	printf("'%07i'\n", -54);
	ft_printf("\n****** TEST ******\n\n");
	ft_printf("'%010d'\n'%-+010.5d'\n", i_n, i_n);
 	printf("'%010d'\n'%-+010.5d'\n", i_n, i_n);
	ft_printf("\n****** TEST PFT ******\n\n");
	ft_printf("'%5.i'\n", 0);
	printf("'%5.i'\n", 0);
	ft_printf("\n****** MOULITEST ******\n\n");
	len = ft_printf("%hhd\n", 128);
	printf("len: %d \n", len);
	len = printf("%hhd\n", 128);
	printf("len: %d \n", len);
	len = ft_printf("%hhd\n", -129);
	printf("len: %d \n", len);
	len = printf("%hhd\n", -129);
	printf("len: %d \n", len);
	
}

void o()
{
	int	i = 3;
 	unsigned long long int lli = 6964321;
	
	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%#50.10o'\n'%#50.10llo'\n", i, lli);
 	printf("'%#50.10o'\n'%#50.10llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #9 ******\n\n");
 	ft_printf("'%50.10o'\n'%50.10llo'\n", i, lli);
 	printf("'%50.10o'\n'%50.10llo'\n", i, lli);

 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%-#50.30o'\n'%-#50.30llo'\n", i, lli);
 	printf("'%-#50.30o'\n'%-#50.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%-50.30o'\n'%-50.30llo'\n", i, lli);	
 	printf("'%-50.30o'\n'%-50.30llo'\n", i, lli);	

 	ft_printf("\n****** TEST #11 ******\n\n");
 	ft_printf("'%-#050.30o'\n'%-#050.30llo'\n", i, lli);
 	printf("'%-#050.30o'\n'%-#050.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%050.30o'\n'%050.30llo'\n", i, lli);
 	printf("'%050.30o'\n'%050.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%-#050.30o'\n'%-#050.30llo'\n", i, lli);
 	printf("'%-#050.30o'\n'%-#050.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #14 ******\n\n");
 	ft_printf("'%-050.30o'\n'%-050.30llo'\n", i, lli);	
 	printf("'%-050.30o'\n'%-050.30llo'\n", i, lli);
	
	ft_printf("\n****** TEST #8 ******\n\n");
 	ft_printf("'%#50.30o'\n'%#50.30llo'\n", i, lli);
 	printf("'%#50.30o'\n'%#50.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #9 ******\n\n");
 	ft_printf("'%50.30o'\n'%50.30llo'\n", i, lli);
 	printf("'%50.30o'\n'%50.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%#50.30o'\n'%#50.30llo'\n", i, lli);
 	printf("'%#50.30o'\n'%#50.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #10 ******\n\n");
 	ft_printf("'%50.30o'\n'%50.30llo'\n", i, lli);	
 	printf("'%50.30o'\n'%50.30llo'\n", i, lli);	

 	ft_printf("\n****** TEST #11 ******\n\n");
 	ft_printf("'%#050.30o'\n'%#050.30llo'\n", i, lli);
 	printf("'%#050.30o'\n'%#050.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%050.30o'\n'%050.30llo'\n", i, lli);
 	printf("'%050.30o'\n'%050.30llo'\n", i, lli);

 	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%#050.30o'\n'%#050.30llo'\n", i, lli);
 	printf("'%#050.30o'\n'%#050.30llo'\n", i, lli);
	
 	ft_printf("\n****** TEST #14 ******\n\n");
 	ft_printf("'%050.30o'\n'%050.30llo'\n", i, lli);	
 	printf("'%050.30o'\n'%050.30llo'\n", i, lli);	

 	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'%#050o'\n'%#050llo'\n", i, lli);
 	printf("'%#050o'\n'%#050llo'\n", i, lli);
	
	ft_printf("\n****** TEST #21 ******\n\n");
	ft_printf("'%08.5i'\n", 0);
	printf("'%08.5i'\n", 0);
	
	ft_printf("\n****** PFT ******\n\n");
	ft_printf("this %#o number\n", 0);
	printf("this %#o number\n", 0);
	ft_printf("@moulitest: %#.o \n", 0);
	printf("@moulitest: %#.o \n", 0);
	ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
	printf("@moulitest: %#.o %#.0o\n", 0, 0);
	ft_printf("@moulitest: %.o %.0o\n", 0, 0);
	printf("@moulitest: %.o %.0o\n", 0, 0);
}

void u()
{
	unsigned long long int 	llu = 55165;
 	//unsigned long long int 	llu_m = 18446744073709551;
 	unsigned int			u = 3;

	ft_printf("\n****** TEST #12 ******\n\n");
 	ft_printf("'%010u'\n'%010llu'\n", u, llu);
 	printf("'%010u'\n'%010llu'\n", u, llu);
	ft_printf("\n****** TEST #14 ******\n\n");
 	ft_printf("'%010u'\n'%-010u'\n", u, u);
 	printf("'%010u'\n'%-010u'\n", u, u);

 	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'%010u'\n'%-010.5u'\n", u, u);
 	printf("'%010u'\n'%-010.5u'\n", u, u);
	ft_printf("\n****** MOULITEST ******\n\n");
	ft_printf("'%u'\n", -1);
	printf("'%u'\n", -1); 
}

void x()
{
	int	i = 3;
 	unsigned long long int lli = 6964321;
	int len;

	ft_printf("\n****** TEST #13 ******\n\n");
 	ft_printf("'%#050.30X'\n'%#050.30llX'\n", i, lli);
 	printf("'%#050.30X'\n'%#050.30llX'\n", i, lli);
	ft_printf("\n****** TEST #15 ******\n\n");
 	ft_printf("'%#050X'\n'%#050llX'\n", i, lli);
 	printf("'%#050X'\n'%#050llX'\n", i, lli);
	ft_printf("'%#.3x'", 0);
 	printf("'%#.3x'\n", 0);
	ft_printf("'%#10x'", 0);
 	printf("'%#10x'\n", 0);
	ft_printf("\n****** MOULITEST ******\n\n");
	ft_printf("%x\n", 4294967296);
	printf("%x\n", 4294967296);
	ft_printf("%hhX\n", 4294967296);
	printf("%hhX\n", 4294967296);
	len = ft_printf("%x\n", -42);
	printf("len: %d \n", len);
	len = printf("%x\n", -42);
	printf("len: %d \n", len);
	ft_printf("this %#x number\n", 0);
	printf("this %#x number\n", 0);
}

void flouty()
{
	double f_n = -432232342.01938409238;
	long double lf_n = -432232342.0193840923840982309580927350274;
	//long double lf_n = 432232342.0193840923840982309580927350274;
	//double f_n = -1000.01;
	
	ft_printf("\n****** TEST #26 ******\n\n");
 	ft_printf("'%-+60.20f'\n", f_n);
 	printf("'%-+60.20f'\n", f_n);
	ft_printf("\n****** TEST #26 ******\n\n");
 	ft_printf("'%+60.20f'\n", f_n);
 	printf("'%+60.20f'\n", f_n);
	ft_printf("\n****** TEST #28 ******\n\n");
 	ft_printf("'%10.5Lf'\n'%010.5f'\n", lf_n, f_n);
 	printf("'%10.5Lf'\n'%010.5f'\n", lf_n, f_n);
	ft_printf("\n****** TEST #28 ******\n\n");
 	ft_printf("'%010.5Lf'\n'%10.5f'\n", lf_n, f_n);
 	printf("'%010.5Lf'\n'%10.5f'\n", lf_n, f_n);
	ft_printf("\n****** PFT ******\n\n");
	ft_printf("%f\n", -0.00032);
	printf("%f\n", -0.00032);
	ft_printf("%.0f\n", -0.00032);
	printf("%.0f\n", -0.00032);
	ft_printf("%.7Lf\n", -0.999999l);
	printf("%.7Lf\n", -0.999999l);
	ft_printf("%.1f\n", -3.85000);
	printf("%.1f\n", -3.85000);
	ft_printf("%.1f\n", 3.85000);
	printf("%.1f\n", 3.85000);
	ft_printf("%.1f\n", 3.95);
	printf("%.1f\n", 3.95);
	ft_printf("%.1f\n", 3.65);
	printf("%.1f\n", 3.65);
	ft_printf("%.1f\n", 3.75);
	printf("%.1f\n", 3.75);
	ft_printf("%.1f\n", 4.05);
	printf("%.1f\n", 4.05);

}

void length()
{
	float dec;
	long double dec_double;
	short int nb_short;
	long int nb_long;
	long long int nb_longlong;
	char c;

	dec = 21.2214561567;
	nb_short = 42;
	nb_long = 777777777777;
	nb_longlong = -9999999999999;
	dec_double = 666.6666666666;
	c = 70;
	printf("Float long %lf\nFloat long double %20.12Lf\nInt to short %hd\nInt to char int %hhd\nInt to long %ld\nInt to long long %lld\n\n", dec, dec_double, nb_short, c, nb_long, nb_longlong);
	printf("Float long %lf\nFloat long double %Lf\nInt to short %ho\nInt to char int %hhi\nInt to long %lx\nInt to long long %llu\n\n", dec, dec_double, nb_short, c, nb_long, nb_longlong);
}

void float_print() {
	float dec;

	dec = 21.2214561567;
	printf("Real printf printing float % .2f\n", dec);
	ft_printf("My printf printing float % .2f\n", dec);
	printf("Real printf printing float %+.2f\n", dec);
	ft_printf("My printf printing float %+.2f\n", dec);
	dec = -20;
	printf("Real printing float %08.2f\n\n", dec);
	ft_printf("Mine printing float %08.2f\n\n", dec);
	printf("Real printing float %#20.f\n\n", dec);
	ft_printf("Mine printing float %#20.f\n\n", dec);
	printf("Real printing float %-20.2f\n\n", dec);
	ft_printf("Mine printing float %-20.2f\n\n", dec);
}

void csp_percent() {
	char *str;
	char c;
	
	printf("Example of csp\n");
	str = "";
	c = 'h';
	printf("Real printf: With c you get %-10c\nWith s you get %-10.5s\nWith p you get %p\nFinally single percentage: %%\n", c, str, str);
	ft_printf("My printf: with c you get %-10c\nWith s you get %-10.5s\nWith p you get %p\nFinally single percentage: %%\n", c, str, str);
	printf("Real: %%%%%%\n\n");
	ft_printf("My: %%%%%%\n\n");
}

void diouxX() {
	int nb;
	short int short_nb;
	long int long_nb;
	long long longer_nb;
	
	nb = -294579;
	printf("Example of diouxX\n");
	printf("Printing several hexas in the row\n");
	printf("Real printf: %X, %X, %X, %X\n", nb, nb, nb, nb);
	ft_printf("My printf: %X, %X, %X, %X\n\n", nb, nb, nb, nb);

	nb = -42;
	printf("Real printf: d is %+.6d\ni is % .3i\no is %#.8o\nu is %.2u\nx is %.8x\nX is %.5X\n\n", nb, nb, nb, nb, nb, nb);
	ft_printf("My printf: d is %+.6d\ni is % .3i\no is %#.8o\nu is %.2u\nx is %.8x\nX is %.5X\n\n", nb, nb, nb, nb, nb, nb);
	nb = -294579;
	printf("Real printf: d is %d\ni is %+i\no is %#.2o\nu is %u\nx is %x\nX is %X\n\n", nb, nb, nb, nb, nb, nb);
	ft_printf("My printf: d is %d\ni is %+i\no is %#.2o\nu is %u\nx is %x\nX is %X\n\n", nb, nb, nb, nb, nb, nb);
	short_nb = -124;
	long_nb = -50069928377;
	longer_nb = -500699283771;
	printf("Real printf: d is %hd\ni is %lli\no is %#lo\nu is %hu\nx is %#1.10llx\nX is %#lX\n\n", short_nb, longer_nb, long_nb, short_nb, longer_nb, long_nb);
	ft_printf("My printf: d is %hd\ni is %lli\no is %#lo\nu is %hu\nx is %#1.10llx\nX is %#lX\n\n", short_nb, longer_nb, long_nb, short_nb, longer_nb, long_nb);
	nb = 0;
	printf("Real printf: print zero with precision of 0: %.x\n", nb);
	ft_printf("My printf: print zero with precision of 0: %.x\n", nb);
	printf("Real printf: print hash flag zero octal with precision of 0: %#.o\n", nb);
	ft_printf("My printf: print hash flag zero octal with precision of 0: %#.o\n", nb);
	printf("Real printf: print hash flag zero hexa with precision of 0: %#.x\n", nb);
	ft_printf("My printf: print hash flag zero hexa with precision of 0: %#.x\n", nb);
	//printf("Real printf: print zero with precision of 0, but with p: %.p\n", nb);
	//ft_printf("My printf: print zero with precision of 0 but with p: %.p\n", nb);
	ft_putchar('\n');
}

void color()
{
	long long int 	lli = 55165;
	char	str[] = "kissoja ja koiria";
	char	str2[] = "ihmisiä";
	int nb;

	ft_printf("this should be {red}'%-+010.5d' red{eoc}\x1b[0m\n", lli);
	ft_printf("this has no color '%#.10d'\n", lli);
	ft_printf("Here we print {yellow}%.8s{eoc}{magenta}%s{eoc}\n", str, str2);
	ft_printf("some more {magenta}text supposed to be here{eoc}.\n");
	ft_printf("this has color cyan {cyan}'%#.10d'{eoc}\n", lli);
	nb = ft_printf("{green}");
	printf("%d\n", nb);
	ft_printf("'{%f}'\n'{%lf}'\n'{%Lf}'\n", 1.42, 1.42, 1.42l);
	ft_printf("{eoc}");
	ft_printf("'{%f'\n'%lf}'\n'{%Lf'{\n", 1.42, 1.42, 1.42l);
	ft_printf("{blue}This whole text is blue\n{eoc}");
	ft_printf("{green}%i green is my fav\n", lli);
}


int main(int argc, char **argv) {
	int len;
	int i;
	unsigned int j;
	float f;
	double dd;
	long double long_d;
	char c;

	if (argc == 2) {
		printf("Starting the test main\n\n");
		//undefined();
		cs();
		p();
		id();
		o();
		u();
		x();
		flouty();
		diouxX();
		csp_percent();
		float_print();
		length();
		color();
		i = -42;
		j = 300;
		f = -1.2300000000;
		dd = 0.0;
		long_d = -1.2500000000;
		char str[] = "koira";
		char str2[] = "hevonen";
		char str3[] = "marsu";
		c = 'p';
		//char c;
		//c = '!';
		len = ft_printf("print char: %c, then print whole string: %s, then print pointer address: %p\n", *str, str2, str3);
		printf("\nlength from ft_printf\n");
		ft_printf("%c is special?\n", '-');
		printf("%c is special?", '-');
		ft_putnbr(len);
		len = ft_printf(argv[1], c);
		printf("\nc %c and str2 %s and str3 %p\n", *str, str2, str3);
		while (1);
	}
	else {
		printf("Too many or too few arguments.");
	}
	return (0);
}