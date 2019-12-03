/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/16 18:26:57 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 05:44:26 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	ft_printf("hello akhy %-*s\n", 21, "salut");
	printf("%*.1s\n", 700, "salut");
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
