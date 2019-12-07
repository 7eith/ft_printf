/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_converter.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 04:57:06 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/07 06:31:13 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*pf_resize(char *str, int width, int precision)
{
	char			*string;
	char			*tmp;
	const size_t	size = ft_strlen(str) + width - precision;

	string = ft_memset(ft_calloc(sizeof(char), size), ' ', width - precision);
	tmp = ft_strjoin(string, str);
	free(string);
	string = tmp;
	return (string);
}

void		pf_convert_string(t_pfinfo *p)
{
	char	*str;

	str = va_arg(p->va, char *);
	if (!p->flags)
		return (pf_add_content(p, str));
	if (p->flags & PF_WIDTH)
	{
		if (ft_strlen(str) < (unsigned long)p->width)
			pf_add_content(p, pf_resize(str, p->width, p->precision));
	}
	p->flags &= ~PF_WIDTH;
	p->flags &= ~PF_PRECIS;
}
