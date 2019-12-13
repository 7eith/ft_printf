/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_converter.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 04:57:06 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 13:57:48 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// TODO: unit tests failed because of negative..
void		pf_convert_decimal(t_pfinfo *p)
{
	int		number;

	number = va_arg(p->va, int);
	if (p->flags & PF_PRECIS && p->precision > ft_numlen(number))
		pf_addzeros(p, p->precision - ft_numlen(number));
	if (!p->flags || (ft_numlen(number) == p->width))
		return (pf_add_content(p, ft_lltoa_base(number, DEC_BASE)));
	if (p->flags & PF_MINUS)
	{
		pf_add_content(p, ft_lltoa_base(number, DEC_BASE));
		if (p->flags & PF_WIDTH && p->width > (int)ft_numlen(number))
			pf_addspaces(p, p->width - (int)ft_numlen(number));
		return ;
	}
	if (p->flags & PF_WIDTH && p->width > (int)ft_numlen(number))
		pf_addspaces(p, p->width - (int)ft_numlen(number));
	pf_add_content(p, ft_lltoa_base(number, DEC_BASE));
	p->flags = 0;
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
			pf_addspaces(p, p->width - (int)ft_strlen(str));
		return ;
	}
	if (p->flags & PF_WIDTH && p->width > (int)ft_strlen(str))
		pf_addspaces(p, p->width - (int)ft_strlen(str));
	pf_add_content(p, str);
	p->flags = 0;
}
