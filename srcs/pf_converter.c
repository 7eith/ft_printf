/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_converter.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 04:57:06 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 17:40:20 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		pf_convert_decimal(t_pfinfo *p)
{
	int		number;

	number = va_arg(p->va, int);
	if (p->flags & PF_PRECIS && p->precision > ft_numlen(number))
		pf_addzeros(p, p->precision - ft_numlen(number));
	if (!p->flags || (ft_numlen(number) == p->width))
		return (pf_stradd(p, ft_lltoa_base(number, DEC_BASE)));
	if (p->flags & PF_MINUS)
	{
		pf_stradd(p, ft_lltoa_base(number, DEC_BASE));
		if (p->flags & PF_WIDTH && p->width > (int)ft_numlen(number))
			pf_addspaces(p, p->width - (int)ft_numlen(number));
		return ;
	}
	if (p->flags & PF_WIDTH && p->width > (int)ft_numlen(number))
		pf_addspaces(p, p->width - (int)ft_numlen(number));
	pf_stradd(p, ft_lltoa_base(number, DEC_BASE));
	p->flags = 0;
}

void		pf_convert_char(t_pfinfo *p, int is_pourcent)
{
	char	c;

	c = is_pourcent ? '%' : va_arg(p->va, int);
	if (p->flags & PF_MINUS)
	{
		pf_charadd(p, c);
		if (p->width > 1)
			pf_addspaces(p, p->width - 1);
		return ;
	}
	if (p->flags & PF_WIDTH && p->width > 1)
		pf_addspaces(p, p->width - 1);
	pf_charadd(p, c);
}

void		pf_convert_string(t_pfinfo *p)
{
	char	*str;

	str = va_arg(p->va, char *);
	if (!str)
		str = "(null)";
	if (p->flags & PF_PRECIS)
		str = ft_strncpy(ft_calloc(p->precision + 1, sizeof(char)), str,
		p->precision);
	if (!p->flags)
		return (pf_stradd(p, str));
	if (p->flags & PF_MINUS)
	{
		pf_stradd(p, str);
		if (p->flags & PF_WIDTH && p->width > (int)ft_strlen(str))
			pf_addspaces(p, p->width - (int)ft_strlen(str));
		return ;
	}
	if (p->flags & PF_WIDTH && p->width > (int)ft_strlen(str))
		pf_addspaces(p, p->width - (int)ft_strlen(str));
	pf_stradd(p, str);
	p->flags = 0;
}
