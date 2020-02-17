/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_int_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonteli <amonteli@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 06:38:49 by amonteli          #+#    #+#             */
/*   Updated: 2020/02/17 09:42:10 by amonteli         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	pf_convert_hexaminus :: static void (struct printf_info, string str)
**	@description:	converter functions for hexa and '-' flag.
**	@params:		struct t_pfinfo *p, string str
*/

static void			pf_convert_hexaminus(t_pfinfo *p, char *str, long long n)
{
	int				len;

	if (p->flags & PF_HASH && n)
		pf_stradd(p, p->type == 'X' ? ft_strdup("0X") : ft_strdup("0x"));
	if (p->flags & PF_PRECIS && p->precision
	&& p->precision > (int)ft_strlen(str))
		pf_addzeros(p, (int)ft_strlen(str) - p->precision);
	pf_stradd(p, str);
	len = p->precision > (int)ft_strlen(str) ? p->precision : ft_strlen(str);
	if (p->flags & PF_HASH && n)
		p->width -= 2;
	if (p->flags & PF_WIDTH && p->width > (int)ft_strlen(str) &&
	!(p->flags & PF_PRECIS || p->precision))
		return (pf_addspaces(p, p->width - (ft_strlen(str))));
	if (p->flags & PF_WIDTH && p->width >= len)
		return (pf_addspaces(p, p->width - len));
}

/*
**	pf_convert_hexa 	:: static void (struct printf_info)
**	@description:	converter functions for hexa.
**	@params:		struct t_pfinfo *p
*/

void				pf_convert_hexa(t_pfinfo *p, char *base, long long number)
{
	const	char	*str = ft_ulltoa_base(number, base);
	int				len;

	if (!p->flags)
		return (pf_stradd(p, (char *)str));
	if (p->flags & PF_PRECIS && !p->precision && !number)
	{
		free((char *)str);
		return (pf_addspaces(p, p->width));
	}
	if (p->flags & (1 << 0))
		return (pf_convert_hexaminus(p, (char *)str, number));
	len = p->precision > (int)ft_strlen(str) ? p->precision : ft_strlen(str);
	len += p->flags & PF_HASH && number ? 2 : 0;
	if (p->flags & PF_WIDTH && p->width >= len &&
	(!(p->flags & PF_ZERO) || p->flags & PF_PRECIS))
		pf_addspaces(p, p->width - len);
	if (p->flags & PF_HASH && number)
		pf_stradd(p, p->type == 'X' ? ft_strdup("0X") : ft_strdup("0x"));
	if (p->flags & PF_WIDTH && p->width >= len
	&& p->flags & PF_ZERO && !(p->flags & PF_PRECIS))
		pf_addzeros(p, p->width - len);
	if (p->flags & PF_PRECIS && p->precision > (int)ft_strlen(str))
		pf_addzeros(p, ft_strlen(str) - p->precision);
	return (pf_stradd(p, (char *)str));
}

/*
**	pf_convert_dminus 	:: static void (struct printf_info, long number)
**	@description:	converter functions for decimal & integer. with '-' flag.
**	@params:		struct t_pfinfo *p, long number
*/

static void			pf_convert_dminus(t_pfinfo *p, long long number)
{
	int			neg;
	int			len;

	neg = number < 0 || p->flags & PF_SPACE || p->flags & PF_PLUS ? 1 : 0;
	if (number < 0)
		pf_charadd(p, '-');
	if ((p->flags & PF_SPACE || p->flags & PF_PLUS) && !(number < 0))
		p->flags & PF_SPACE ? pf_charadd(p, ' ') : pf_charadd(p, '+');
	if (p->flags & PF_PRECIS && !p->precision && !number
	&& (p->flags & PF_SPACE || p->flags & PF_PLUS) && p->width - neg > 0)
		return (pf_addspaces(p, p->width - neg));
	if (p->flags & PF_PRECIS && p->precision
	&& p->precision > ft_numlen(number))
		pf_addzeros(p, ft_numlen(number) - p->precision);
	pf_stradd(p, ft_ulltoa_base(number < 0 ? number * -1 : number, DEC_BASE));
	len = p->precision > (int)ft_numlen(number)
	? p->precision + neg : ft_numlen(number) + neg;
	if (p->flags & PF_WIDTH && p->width > ft_numlen(number) &&
	!(p->flags & PF_PRECIS || p->precision))
		return (pf_addspaces(p, p->width - (ft_numlen(number) + neg)));
	if (p->flags & PF_WIDTH && p->width >= len)
		return (pf_addspaces(p, p->width - len));
}

static inline void	pf_normebonus(t_pfinfo *p, long long int n, int len)
{
	if (p->flags & PF_PRECIS && !p->precision && !n &&
	(p->flags & PF_SPACE || p->flags & PF_PLUS))
		return (p->flags & PF_SPACE ? pf_charadd(p, ' ') : pf_charadd(p, '+'));
	if (n < 0)
		pf_charadd(p, '-');
	if ((p->flags & PF_SPACE || p->flags & PF_PLUS) && !(n < 0))
		p->flags & PF_SPACE ? pf_charadd(p, ' ') : pf_charadd(p, '+');
	if (p->flags & PF_WIDTH && p->width >= len
	&& p->flags & PF_ZERO && !(p->flags & PF_PRECIS))
		pf_addzeros(p, p->width - len);
	if (p->flags & PF_PRECIS && p->precision > ft_numlen(n))
		pf_addzeros(p, ft_numlen(n) - p->precision);
	pf_stradd(p, ft_ulltoa_base(n < 0 ? n * -1 : n, DEC_BASE));
}

/*
**	pf_convert_decimal 	:: static void (struct printf_info)
**	@description:	converter functions for decimal & integer.
**	@params:		struct t_pfinfo *p, long number
*/

void				pf_convert_decimal(t_pfinfo *p, long long int n)
{
	int				padding;
	int				len;

	padding = n < 0 || p->flags & PF_SPACE || p->flags & PF_PLUS ? 1 : 0;
	if (!p->flags && !(n < 0))
		return (pf_stradd(p, n < 0 ? ft_ltoa(n) : ft_ulltoa_base(n, DEC_BASE)));
	if (p->flags & PF_PRECIS && !p->precision
	&& !n && !(p->flags & PF_SPACE || p->flags & PF_PLUS))
		return (pf_addspaces(p, p->width - padding));
	if (p->flags & PF_PRECIS && !p->precision && !n
	&& !(p->flags & (1 << 0)) && (p->flags & PF_SPACE || p->flags & PF_PLUS))
	{
		if (p->width - padding > 0)
			pf_addspaces(p, p->width - padding);
		return (p->flags & PF_SPACE ? pf_charadd(p, ' ') : pf_charadd(p, '+'));
	}
	if (p->flags & (1 << 0))
		return (pf_convert_dminus(p, n));
	len = p->precision > (int)ft_numlen(n)
	? p->precision + padding : ft_numlen(n) + padding;
	if (p->flags & PF_WIDTH && p->width > len &&
	(!(p->flags & PF_ZERO) || p->flags & PF_PRECIS))
		pf_addspaces(p, p->width - len);
	pf_normebonus(p, n, len);
}
