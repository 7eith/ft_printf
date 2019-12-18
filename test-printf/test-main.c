/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test-printf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 16:54:40 by aalleman     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/07 17:19:51 by aalleman    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <wchar.h>
#include <locale.h>

int		ft_printf(const char *s, ...);

int		main(int ac, char **av)
{
	int		nb;
	int		count;

	nb = atoi(av[1]);
	count = 0;


	// [G - Tests with minimum field width, flag - and .].
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0%") : ft_printf("%-1.0%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1%") : ft_printf("%-1.1%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2%") : ft_printf("%-1.2%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10%") : ft_printf("%-1.10%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0%") : ft_printf("%-2.0%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1%") : ft_printf("%-2.1%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2%") : ft_printf("%-2.2%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10%") : ft_printf("%-2.10%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0%") : ft_printf("%-10.0%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1%") : ft_printf("%-10.1%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2%") : ft_printf("%-10.2%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10%") : ft_printf("%-10.10%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0s", "") : ft_printf("%-1.0s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1s", "") : ft_printf("%-1.1s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2s", "") : ft_printf("%-1.2s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10s", "") : ft_printf("%-1.10s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%-5.0s", "Hello") : ft_printf("%-5.0s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-5.1s", "Hello") : ft_printf("%-5.1s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-5.2s", "Hello") : ft_printf("%-5.2s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-5.10s", "Hello") : ft_printf("%-5.10s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-6.0s", "Hello") : ft_printf("%-6.0s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-6.1s", "Hello") : ft_printf("%-6.1s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-6.2s", "Hello") : ft_printf("%-6.2s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-6.10s", "Hello") : ft_printf("%-6.10s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0i", 0) : ft_printf("%-1.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1i", 0) : ft_printf("%-1.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2i", 0) : ft_printf("%-1.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10i", 0) : ft_printf("%-1.10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0i", 0) : ft_printf("%-2.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1i", 0) : ft_printf("%-2.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2i", 0) : ft_printf("%-2.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10i", 0) : ft_printf("%-2.10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0i", 0) : ft_printf("%-10.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1i", 0) : ft_printf("%-10.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2i", 0) : ft_printf("%-10.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10i", 0) : ft_printf("%-10.10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0i", -1) : ft_printf("%-1.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1i", -1) : ft_printf("%-1.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2i", -1) : ft_printf("%-1.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10i", -1) : ft_printf("%-1.10i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0i", -1) : ft_printf("%-2.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1i", -1) : ft_printf("%-2.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2i", -1) : ft_printf("%-2.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10i", -1) : ft_printf("%-2.10i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.0i", -1) : ft_printf("%-3.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.1i", -1) : ft_printf("%-3.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.2i", -1) : ft_printf("%-3.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.10i", -1) : ft_printf("%-3.10i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.0i", INT_MAX) : ft_printf("%-9.0i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.1i", INT_MAX) : ft_printf("%-9.1i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.2i", INT_MAX) : ft_printf("%-9.2i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.10i", INT_MAX) : ft_printf("%-9.10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0i", INT_MAX) : ft_printf("%-10.0i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1i", INT_MAX) : ft_printf("%-10.1i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2i", INT_MAX) : ft_printf("%-10.2i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10i", INT_MAX) : ft_printf("%-10.10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.0i", INT_MAX) : ft_printf("%-11.0i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.1i", INT_MAX) : ft_printf("%-11.1i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.2i", INT_MAX) : ft_printf("%-11.2i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.10i", INT_MAX) : ft_printf("%-11.10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0d", 0) : ft_printf("%-1.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1d", 0) : ft_printf("%-1.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2d", 0) : ft_printf("%-1.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10d", 0) : ft_printf("%-1.10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0d", 0) : ft_printf("%-2.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1d", 0) : ft_printf("%-2.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2d", 0) : ft_printf("%-2.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10d", 0) : ft_printf("%-2.10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0d", 0) : ft_printf("%-10.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1d", 0) : ft_printf("%-10.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2d", 0) : ft_printf("%-10.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10d", 0) : ft_printf("%-10.10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0d", -1) : ft_printf("%-1.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1d", -1) : ft_printf("%-1.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2d", -1) : ft_printf("%-1.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10d", -1) : ft_printf("%-1.10d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0d", -1) : ft_printf("%-2.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1d", -1) : ft_printf("%-2.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2d", -1) : ft_printf("%-2.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10d", -1) : ft_printf("%-2.10d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.0d", -1) : ft_printf("%-3.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.1d", -1) : ft_printf("%-3.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.2d", -1) : ft_printf("%-3.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.10d", -1) : ft_printf("%-3.10d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.0d", INT_MAX) : ft_printf("%-9.0d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.1d", INT_MAX) : ft_printf("%-9.1d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.2d", INT_MAX) : ft_printf("%-9.2d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.10d", INT_MAX) : ft_printf("%-9.10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0d", INT_MAX) : ft_printf("%-10.0d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1d", INT_MAX) : ft_printf("%-10.1d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2d", INT_MAX) : ft_printf("%-10.2d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10d", INT_MAX) : ft_printf("%-10.10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.0d", INT_MAX) : ft_printf("%-11.0d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.1d", INT_MAX) : ft_printf("%-11.1d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.2d", INT_MAX) : ft_printf("%-11.2d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.10d", INT_MAX) : ft_printf("%-11.10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0u", 0) : ft_printf("%-1.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1u", 0) : ft_printf("%-1.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2u", 0) : ft_printf("%-1.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10u", 0) : ft_printf("%-1.10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0u", 0) : ft_printf("%-2.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1u", 0) : ft_printf("%-2.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2u", 0) : ft_printf("%-2.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10u", 0) : ft_printf("%-2.10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0u", 0) : ft_printf("%-10.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1u", 0) : ft_printf("%-10.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2u", 0) : ft_printf("%-10.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10u", 0) : ft_printf("%-10.10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0u", -1) : ft_printf("%-1.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1u", -1) : ft_printf("%-1.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2u", -1) : ft_printf("%-1.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10u", -1) : ft_printf("%-1.10u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0u", -1) : ft_printf("%-2.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1u", -1) : ft_printf("%-2.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2u", -1) : ft_printf("%-2.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10u", -1) : ft_printf("%-2.10u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.0u", -1) : ft_printf("%-3.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.1u", -1) : ft_printf("%-3.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.2u", -1) : ft_printf("%-3.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.10u", -1) : ft_printf("%-3.10u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.0u", UINT_MAX) : ft_printf("%-9.0u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.1u", UINT_MAX) : ft_printf("%-9.1u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.2u", UINT_MAX) : ft_printf("%-9.2u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.10u", UINT_MAX) : ft_printf("%-9.10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0u", UINT_MAX) : ft_printf("%-10.0u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1u", UINT_MAX) : ft_printf("%-10.1u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2u", UINT_MAX) : ft_printf("%-10.2u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10u", UINT_MAX) : ft_printf("%-10.10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.0u", UINT_MAX) : ft_printf("%-11.0u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.1u", UINT_MAX) : ft_printf("%-11.1u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.2u", UINT_MAX) : ft_printf("%-11.2u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.10u", UINT_MAX) : ft_printf("%-11.10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0x", 0) : ft_printf("%-1.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1x", 0) : ft_printf("%-1.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2x", 0) : ft_printf("%-1.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10x", 0) : ft_printf("%-1.10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0x", 0) : ft_printf("%-2.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1x", 0) : ft_printf("%-2.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2x", 0) : ft_printf("%-2.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10x", 0) : ft_printf("%-2.10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0x", 0) : ft_printf("%-10.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1x", 0) : ft_printf("%-10.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2x", 0) : ft_printf("%-10.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10x", 0) : ft_printf("%-10.10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0x", -1) : ft_printf("%-1.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1x", -1) : ft_printf("%-1.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2x", -1) : ft_printf("%-1.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10x", -1) : ft_printf("%-1.10x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0x", -1) : ft_printf("%-2.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1x", -1) : ft_printf("%-2.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2x", -1) : ft_printf("%-2.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10x", -1) : ft_printf("%-2.10x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.0x", -1) : ft_printf("%-3.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.1x", -1) : ft_printf("%-3.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.2x", -1) : ft_printf("%-3.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.10x", -1) : ft_printf("%-3.10x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.0x", UINT_MAX) : ft_printf("%-9.0x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.1x", UINT_MAX) : ft_printf("%-9.1x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.2x", UINT_MAX) : ft_printf("%-9.2x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.10x", UINT_MAX) : ft_printf("%-9.10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0x", UINT_MAX) : ft_printf("%-10.0x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1x", UINT_MAX) : ft_printf("%-10.1x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2x", UINT_MAX) : ft_printf("%-10.2x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10x", UINT_MAX) : ft_printf("%-10.10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.0x", UINT_MAX) : ft_printf("%-11.0x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.1x", UINT_MAX) : ft_printf("%-11.1x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.2x", UINT_MAX) : ft_printf("%-11.2x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.10x", UINT_MAX) : ft_printf("%-11.10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0X", 0) : ft_printf("%-1.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1X", 0) : ft_printf("%-1.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2X", 0) : ft_printf("%-1.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10X", 0) : ft_printf("%-1.10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0X", 0) : ft_printf("%-2.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1X", 0) : ft_printf("%-2.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2X", 0) : ft_printf("%-2.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10X", 0) : ft_printf("%-2.10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0X", 0) : ft_printf("%-10.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1X", 0) : ft_printf("%-10.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2X", 0) : ft_printf("%-10.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10X", 0) : ft_printf("%-10.10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0X", -1) : ft_printf("%-1.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1X", -1) : ft_printf("%-1.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2X", -1) : ft_printf("%-1.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10X", -1) : ft_printf("%-1.10X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0X", -1) : ft_printf("%-2.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1X", -1) : ft_printf("%-2.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2X", -1) : ft_printf("%-2.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10X", -1) : ft_printf("%-2.10X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.0X", -1) : ft_printf("%-3.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.1X", -1) : ft_printf("%-3.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.2X", -1) : ft_printf("%-3.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.10X", -1) : ft_printf("%-3.10X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.0X", UINT_MAX) : ft_printf("%-9.0X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.1X", UINT_MAX) : ft_printf("%-9.1X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.2X", UINT_MAX) : ft_printf("%-9.2X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.10X", UINT_MAX) : ft_printf("%-9.10X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0X", UINT_MAX) : ft_printf("%-10.0X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1X", UINT_MAX) : ft_printf("%-10.1X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2X", UINT_MAX) : ft_printf("%-10.2X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10X", UINT_MAX) : ft_printf("%-10.10X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.0X", UINT_MAX) : ft_printf("%-11.0X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.1X", UINT_MAX) : ft_printf("%-11.1X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.2X", UINT_MAX) : ft_printf("%-11.2X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.10X", UINT_MAX) : ft_printf("%-11.10X", UINT_MAX));

	// [H - Tests with minimum field width, flag 0 and .].
return (0);
}
