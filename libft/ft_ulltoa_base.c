/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ulltoa_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 04:01:50 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 17:33:45 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ulltoa_base(unsigned long long n, char *base)
{
	int		size;
	char	*tab;

	size = ft_numlen(n);
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	tab[size] = '\0';
	while (size)
	{
		tab[size - 1] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
		size--;
	}
	return (tab);
}
