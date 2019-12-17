/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_numlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 03:04:51 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 20:04:27 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>

int			ft_numlen(int number)
{
	int		count;

	count = 1;
	printf("number is =%d\n", number);
	if (number < 0)
		number *= -1;
	while (number > 9)
	{
		number /= 10;
		count++;
	}
	return (count);
}
