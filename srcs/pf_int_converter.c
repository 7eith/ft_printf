/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_int_converter.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 06:38:49 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 04:58:10 by amonteli    ###    #+. /#+    ###.fr     */
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

	if (p->flags & PF_PRECIS && p->precision
	&& p->precision > (int)ft_strlen(str))
		pf_addzeros(p, (int)ft_strlen(str) - p->precision);
	pf_stradd(p, str);
	len = ft_strlen(str);
	if (p->precision > (int)ft_strlen(str))
		len = p->precision;
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

void			pf_convert_hexa(t_pfinfo *p)
{
	const	char	*base = p->type == 'x' ? LOW_HEXA : UP_HEXA;
	const	int		number = va_arg(p->va, unsigned int);
	const	char	*str = ft_utoa_base(number, (char *)base);
	int				len;

	if (!p->flags)
		return (pf_stradd(p, ft_utoa_base(number, (char *)base)));
	if (p->flags & PF_PRECIS && !p->precision && !number)
		return (pf_addspaces(p, p->width));
	if (p->flags & PF_MINUS)
		return (pf_convert_hexaminus(p, (char *)str));
	len = ft_strlen(str);
	if (p->precision > (int)ft_strlen(str))
		len = p->precision;
	if (p->flags & PF_WIDTH && p->width >= len &&
	(!(p->flags & PF_ZERO) || p->flags & PF_PRECIS))
		pf_addspaces(p, p->width - len);
	if (p->flags & PF_WIDTH && p->width >= len
	&& p->flags & PF_ZERO && !(p->flags & PF_PRECIS))
		pf_addzeros(p, p->width - len);
	if (p->flags & PF_PRECIS && p->precision > (int)ft_strlen(str))
		pf_addzeros(p, ft_strlen(str) - p->precision);
	return (pf_stradd(p, ft_utoa_base(number, (char *)base)));
}

static void		pf_convert_dminus(t_pfinfo *p, long number)
{
	const int	neg = number < 0 ? 1 : 0;
	int			len_to_print;

	if (neg)
		pf_charadd(p, '-');
	if (p->flags & PF_PRECIS && p->precision
	&& p->precision > ft_numlen(number))
		pf_addzeros(p, ft_numlen(number) - p->precision);
	pf_stradd(p, ft_ltoa(neg ? number * -1 : number));
	len_to_print = ft_numlen(number) + neg;
	if (p->precision > ft_numlen(number))
		len_to_print = p->precision + neg;
	if (p->flags & PF_WIDTH && p->width > ft_numlen(number) &&
	!(p->flags & PF_PRECIS || p->precision))
		return (pf_addspaces(p, p->width - (ft_numlen(number) + neg)));
	if (p->flags & PF_WIDTH && p->width >= len_to_print)
		return (pf_addspaces(p, p->width - len_to_print));
}

void			pf_convert_decimal(t_pfinfo *p)
{
	const	long	number = (long)va_arg(p->va, int);
	int				neg;
	int				len_to_print;

	neg = number < 0 ? 1 : 0;
	if (!p->flags)
		return (pf_stradd(p, ft_ltoa(number)));
	if (p->flags & PF_PRECIS && !p->precision && !number)
		return (pf_addspaces(p, p->width));
	if (p->flags & PF_MINUS)
		return (pf_convert_dminus(p, number));
	len_to_print = ft_numlen(number) + neg;
	if (p->precision > ft_numlen(number))
		len_to_print = p->precision + neg;
	if (p->flags & PF_WIDTH && p->width >= len_to_print &&
	(!(p->flags & PF_ZERO) || p->flags & PF_PRECIS))
		pf_addspaces(p, p->width - len_to_print);
	if (neg)
		pf_charadd(p, '-');
	if (p->flags & PF_WIDTH && p->width >= len_to_print
	&& p->flags & PF_ZERO && !(p->flags & PF_PRECIS))
		pf_addzeros(p, p->width - len_to_print);
	if (p->flags & PF_PRECIS && p->precision > ft_numlen(number))
		pf_addzeros(p, ft_numlen(number) - p->precision);
	pf_stradd(p, ft_ltoa(neg ? number * -1 : number));
}
