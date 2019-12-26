/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_bonus.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 11:41:11 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 23:29:29 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void			pf_convert_dbonus(t_pfinfo *p)
{
	if (p->flags & PF_L || p->flags & PF_LL)
		return (pf_convert_decimal(p, p->flags & PF_LL
		? va_arg(p->va, long long) : va_arg(p->va, long)));
	if (p->flags & PF_H || p->flags & PF_HH)
		return (pf_convert_decimal(p, p->flags & PF_HH
		? (char)va_arg(p->va, int) : (short)va_arg(p->va, int)));
	pf_convert_decimal(p, va_arg(p->va, int));
}

void			pf_convert_bonus(t_pfinfo *p)
{
	p->type == 'd' || p->type == 'i' ? pf_convert_dbonus(p) : NULL;
	if (p->type == 'x' || p->type == 'X')
	{
		if (p->flags & PF_L || p->flags & PF_LL)
			return (pf_convert_hexa(p, p->type == 'x' ? LOW_HEXA : UP_HEXA, p->flags & PF_LL ? va_arg(p->va, long long) : va_arg(p->va, long)));
		if (p->flags & PF_H || p->flags & PF_HH)
			return (pf_convert_hexa(p, p->type == 'x' ? LOW_HEXA : UP_HEXA, p->flags & PF_HH ? (unsigned char)va_arg(p->va, unsigned int) : (unsigned short)va_arg(p->va, unsigned int)));
		return (pf_convert_hexa(p, p->type == 'x' ? LOW_HEXA : UP_HEXA, va_arg(p->va, unsigned int)));
	}
	if (p->type == 'u')
	{
		if (p->flags & PF_L || p->flags & PF_LL)
			return (pf_convert_unsigned(p, p->flags & PF_LL ? va_arg(p->va, long long) : va_arg(p->va, long)));
		if (p->flags & PF_H || p->flags & PF_HH)
			return (pf_convert_unsigned(p, p->flags & PF_HH ? (unsigned char)va_arg(p->va, unsigned int) : (unsigned short)va_arg(p->va, unsigned int)));
		return (pf_convert_unsigned(p, va_arg(p->va, unsigned int)));
	}
}

void			pf_bind_ptr(t_pfinfo *p)
{
	t_pfcontent	*content;
	int			size;
	int			*ptr;

	if (!(ptr = va_arg(p->va, void *)))
		return ;
	content = p->content;
	size = 0;
	while (content)
	{
		size += content->size;
		content = content->next;
	}
	*ptr = size;
}
