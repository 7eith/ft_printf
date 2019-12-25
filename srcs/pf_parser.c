/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_parser.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/17 17:17:50 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/25 18:34:33 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int			pf_is_flag(char c)
{
	size_t		count;

	count = 0;
	while (PF_FLAGS[count])
	{
		if (PF_FLAGS[count] == c)
			return (1);
		count++;
	}
	return (0);
}

/*
**	parse_flags(struct printf_infos)
**	@description:		parse flags and put in @param
**	@param:				struct t_pfinfo
*/

void				parse_flags(t_pfinfo *p)
{
	while (p->format[p->count] && pf_is_flag(p->format[p->count]))
	{
		if (p->format[p->count] == '-')
			p->flags |= PF_MINUS;
		else if (p->format[p->count] == '+')
			p->flags |= PF_PLUS;
		else if (p->format[p->count] == '0')
			p->flags |= PF_ZERO;
		else if (p->format[p->count] == '#')
			p->flags |= PF_HASH;
		else if (p->format[p->count] == ' ')
			p->flags |= PF_SPACE;
		p->count++;
	}
}

/*
**	parse_size(struct printf_infos)
**	@description:		parse size and put in @param
**	@param:				struct t_pfinfo
*/

void				parse_size(t_pfinfo *p)
{
	if (p->format[p->count] == '*')
	{
		p->flags |= PF_WIDTH;
		p->width = va_arg(p->va, int);
		p->count++;
	}
	else if (ft_isdigit(p->format[p->count]))
	{
		p->flags |= PF_WIDTH;
		p->width = ft_atoi(p->format + p->count);
		p->count += ft_numlen(p->width);
	}
	if (p->format[p->count] == '.' && (p->flags |= PF_PRECIS))
	{
		p->count++;
		if (p->format[p->count] == '*' && (p->count++))
			p->precision = va_arg(p->va, int);
		else if (ft_isdigit(p->format[p->count]))
		{
			p->precision = ft_atoi(p->format + p->count);
			while (ft_isdigit(p->format[p->count]))
				p->count++;
		}
	}
}

void				pf_parse_modificator(t_pfinfo *p)
{
	while (p->format[p->count] && ft_strchr(PF_MF, p->format[p->count]))
	{
		if (p->format[p->count] == 'l')
		{
			if (p->format[++p->count] == 'l')
				p->flags |= PF_LL;
			else
				p->flags |= PF_L;
		}
		if (p->format[p->count] == 'h')
		{
			if (p->format[++p->count] == 'h')
				p->flags |= PF_HH;
			else
				p->flags |= PF_H;
		}
		if (p->format[p->count] == 'z')
			p->flags |= PF_Z;
		p->count++;
	}
	p->type = p->format[p->count];
	p->count++;
}

void				parse(t_pfinfo *p)
{
	if (p->format[p->count] == '%')
		p->count++;
	parse_flags(p);
	parse_size(p);
	pf_parse_modificator(p);
	if (p->width < 0)
	{
		p->width *= -1;
		p->flags |= PF_MINUS;
	}
	if (p->precision < 0)
		p->flags &= ~PF_PRECIS;
}