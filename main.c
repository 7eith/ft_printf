/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/16 18:26:57 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/07 07:22:46 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	// Without any flags
	// printf("-------------[ 0/X - WITHOUT FLAGS ]-------------\n");
	// printf("printed_size=%d\n", ft_printf("simple printf hello!\n"));
	// printf("printed_size=%d\n", printf("simple printf hello!\n"));

	// printf("printed_size=%d\n", ft_printf("salut %c", '\0'));

	// ft_printf("salut %c\n", '\0');
	// printf("salut %c\n", '\0');

	// printf("salut %c", '\0');


	// printf("-------------[ 1/X - FLAGS %% ]-------------\n");

	// ft_printf("simple printf hello %% !\n");
	// printf("simple printf hello %%!\n");

	// printf("-------------[ 2/X - FLAGS %% ]-------------\n");

	// ft_printf("salut %s", "ca vaedsxz?");

	// printf("-------------[ 3/X - WIDTH ]-------------\n");

	// ft_printf("[minepf]%*s\n", 15, "123456789");
	//    printf("[printf]%*s\n", 15, "123456789");

	// printf("\n\n-------------[ 3.5/X - WIDTH ]-------------\n\n");


	// ft_printf("[minepf]%123s\n", "123456789atoi");
	//    printf("[printf]%123s\n", "123456789atoi");

	// printf("\n\n-------------[ 4/X - PRECISION ]-------------\n");

	// ft_printf("[minepf]%.500s\n", "123456789atoi");
	//    printf("[printf]%.500s\n", "123456789atoi");

	// printf("\n\n-------------[ 4.5/X - PRECISION ]-------------\n");

	// ft_printf("[minepf]%.*s\n", 9, "123456789atoi");
	//    printf("[printf]%.*s\n", 9, "123456789atoi");


	// printf("\n\n-------------[ 5/X - WIDTH & PRECISION ]-------------\n");

	// ft_printf("[minepf]%50.*s\n", 9, "123456789atoi");
	//    printf("[printf]%50.*s\n", 9, "123456789atoi");

	// ft_printf("[minepf]%*.*s\n", 15, 9, "123456789atoi");
	//    printf("[printf]%*.*s\n", 15, 9, "123456789atoi");

	// ft_printf("[minepf]%50.500s\n", "123456789atoi");
	//    printf("[printf]%50.500s\n", "123456789atoi");


	ft_printf("[my_printf]%*s others flags=%.*d\n", 10, "salut", 50, 69);
	   printf("\n");
	   printf("[printf]%*s others flags=%4.*d\n", 10, "salut", 5, 69);

	// printf("\n\n-------------[ 4.5/X - PRECISION ]-------------\n");

	// ft_printf("%s\n", 35, "this a flags star with a 100 precision not seeing this bro");
	//    printf("%.*s\n", 35, "this a flags star with a 100 precision not seeing this bro");

	// printf("hello akhy %.*s\n", 21, "salut");

	// printf("hello akhy % -*s\n", 21, "salut");

	// ft_printf("hello akhy %-*.*s\n", 21, 45, "salut");
	// printf("hello akhy %-*.*s\n", 21, 45, "salut");

//
	// ft_printf("integer% -*d\n", 21, 420);
	// printf("integer%*d\n", 201, 420);

	// printf("%'i", -10000);
	// printf("%*.1s\n", 700, "salut");
	// char	*str;
	// char	*ret;

	// str = "ok, should result a %c";
	// printf("%-*d\n", 5, 10);
	// ft_printf("string=%s, nbr=%d\n", "str", -2147483647);

	// ret = ft_strreplace(str, "%c", "s");
	// printf("[ft_strreplace]%s\n", ret);
	// free(ret);

	// int count;

	// count = 0;
	// while (PF_FLAGS[count])
	// {
	// 	printf("flag=%c\n", PF_FLAGS[count]);
	// 	count++;
	// }
}
// bitwise operator
	// unsigned char flags = 0;
	// flags |= PF_ZERO;
	// flags &= ~(1 << 6);

	// if (flags & PF_ZERO)
	// 	printf("IL EST LA");
	// flags &= ~PF_ZERO;
	// printf("%d\n", flags);
