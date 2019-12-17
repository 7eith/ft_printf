/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lltoa_base.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 04:01:50 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 15:23:49 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_get_size(int number)
{
	int		count;

	count = 0;
	if (number < 0)
		number = -number;
	while (number > 9)
	{
		number = number / 10;
		count++;
	}
	return (count + 1);
}

char			*ft_lltoa_base(long long n, char *base)
{
	int		size;
	int		neg;
	char	*tab;

	size = ft_get_size(n);
	neg = 0;
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1 + neg))))
		return (NULL);
	if (neg)
		tab[0] = '-';
	tab[size + neg] = '\0';
	while (size)
	{
		tab[size - (neg ? 0 : 1)] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
		size--;
	}
	return (tab);
}
