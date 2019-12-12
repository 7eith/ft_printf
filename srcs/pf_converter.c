/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_converter.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 04:57:06 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 06:46:09 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*pf_create_blank_string(int width)
{
	if (width < 0)
		width *= -1;
	return (ft_memset(ft_calloc(width + 1, sizeof(char)), 32, width));
}

void		pf_convert_string(t_pfinfo *p)
{
	char	*str;

	str = va_arg(p->va, char *);
	if (!str)
		str = "(null)";
	str = ft_strncpy(ft_calloc(ft_strlen(str) + 1, sizeof(char)),
	str, p->flags & PF_PRECIS ? p->precision : ft_strlen(str));
	if (!p->flags || (ft_strlen(str) == (size_t)p->width))
		return (pf_add_content(p, str));
	if (p->flags & PF_MINUS)
	{
		pf_add_content(p, str);
		if (p->flags & PF_WIDTH && p->width > (int)ft_strlen(str))
			return (pf_add_content(p, pf_create_blank_string(
				p->width - (int)ft_strlen(str))));
		else
			return ;
	}
	if (p->flags & PF_WIDTH && p->width > (int)ft_strlen(str))
		pf_add_content(p, pf_create_blank_string(p->width -
		(int)ft_strlen(str)));
	pf_add_content(p, str);
	p->width = 0;
	p->precision = 0;
	p->flags = 0;
}
