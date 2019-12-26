/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_int_converter.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 06:38:49 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 22:27:11 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	pf_convert_hexaminus :: static void (struct printf_info, string str)
**	@description:	converter functions for hexa and '-' flag.
**	@params:		struct t_pfinfo *p, string str
*/

static void		pf_convert_hexaminus(t_pfinfo *p, char *str)
{
	int				len;

	if (p->flags & PF_HASH)
		pf_stradd(p, p->type == 'X' ? ft_strdup("0X") : ft_strdup("0x"));
	if (p->flags & PF_PRECIS && p->precision
	&& p->precision > (int)ft_strlen(str))
		pf_addzeros(p, (int)ft_strlen(str) - p->precision);
	pf_stradd(p, str);
	len = p->precision > (int)ft_strlen(str) ? p->precision : ft_strlen(str);
	if (p->flags & PF_HASH)
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

void			pf_convert_hexa(t_pfinfo *p, char *base, long long number)
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
	if (p->flags & PF_MINUS)
		return (pf_convert_hexaminus(p, (char *)str));
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

static void		pf_convert_dminus(t_pfinfo *p, long number)
{
	const int	neg = number < 0 ? 1 : 0;
	int			len;

	if (neg)
		pf_charadd(p, '-');
	if (p->flags & PF_PRECIS && p->precision
	&& p->precision > ft_numlen(number))
		pf_addzeros(p, ft_numlen(number) - p->precision);
	pf_stradd(p, ft_ulltoa_base(neg ? number * -1 : number, DEC_BASE));
	len = p->precision > (int)ft_numlen(number)
	? p->precision + neg : ft_numlen(number) + neg;
	if (p->flags & PF_WIDTH && p->width > ft_numlen(number) &&
	!(p->flags & PF_PRECIS || p->precision))
		return (pf_addspaces(p, p->width - (ft_numlen(number) + neg)));
	if (p->flags & PF_WIDTH && p->width >= len)
		return (pf_addspaces(p, p->width - len));
}

/*
**	pf_convert_decimal 	:: static void (struct printf_info)
**	@description:	converter functions for decimal & integer.
**	@params:		struct t_pfinfo *p, long number
*/

void			pf_convert_decimal(t_pfinfo *p, long long int n)
{
	int				neg;
	int				len;

	neg = n < 0 ? 1 : 0;
	if (!p->flags && !neg)
		return (pf_stradd(p, neg ? ft_ltoa(n) : ft_ulltoa_base(n, DEC_BASE)));
	if (p->flags & PF_PRECIS && !p->precision && !n)
		return (pf_addspaces(p, p->width));
	if (p->flags & PF_MINUS)
		return (pf_convert_dminus(p, n));
	len = p->precision > (int)ft_numlen(n)
	? p->precision + neg : ft_numlen(n) + neg;
	if (p->flags & PF_WIDTH && p->width >= len &&
	(!(p->flags & PF_ZERO) || p->flags & PF_PRECIS))
		pf_addspaces(p, p->width - len);
	if (neg)
		pf_charadd(p, '-');
	if (p->flags & PF_WIDTH && p->width >= len
	&& p->flags & PF_ZERO && !(p->flags & PF_PRECIS))
		pf_addzeros(p, p->width - len);
	if (p->flags & PF_PRECIS && p->precision > ft_numlen(n))
		pf_addzeros(p, ft_numlen(n) - p->precision);
	pf_stradd(p, ft_ulltoa_base(neg ? n * -1 : n, DEC_BASE));
}
