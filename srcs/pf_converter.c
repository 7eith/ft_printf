/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_converter.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 04:57:06 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 03:07:22 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		pf_convert_dminus(t_pfinfo *p, long number)
{
	const int	neg = number < 0 ? 1 : 0;
	int			len_to_print;

	if (p->flags & PF_PRECIS && !p->precision && !number)
		return (pf_addspaces(p, p->width));
	if (neg)
	{
		number *= -1;
		pf_charadd(p, '-');
	}
	if (p->flags & PF_PRECIS && p->precision
	&& p->precision > ft_numlen(number))
		pf_addzeros(p, ft_numlen(number) - p->precision);
	pf_stradd(p, ft_ltoa(number));
	len_to_print = ft_numlen(number) + neg;
	if (p->precision > ft_numlen(number))
		len_to_print = p->precision + neg;
	if (p->flags & PF_WIDTH && p->width > ft_numlen(number) &&
	!(p->flags & PF_PRECIS || p->precision))
		return (pf_addspaces(p, p->width - (ft_numlen(number) + neg)));
	if (p->flags & PF_WIDTH && p->width >= len_to_print)
		return (pf_addspaces(p, p->width - len_to_print));
}

void		pf_convert_decimal(t_pfinfo *p)
{
	const	long	number = (long)va_arg(p->va, int);
	int				neg;
	int				len_to_print;

	neg = number < 0 ? 1 : 0;
	if (!p->flags)
		return (pf_stradd(p, ft_ltoa(number)));
	if (p->flags & PF_MINUS)
		return (pf_convert_dminus(p, number));
	if (p->flags & PF_PRECIS && !p->precision && !number)
		return (pf_addspaces(p, p->width));
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

void		pf_convert_char(t_pfinfo *p, int is_pourcent)
{
	const char	c = is_pourcent ? '%' : va_arg(p->va, int);

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
	if (!p->flags)
		return (pf_stradd(p, str));
	if (p->flags & PF_PRECIS)
		str = ft_strncpy(ft_calloc(p->precision + 1, sizeof(char)), str,
		p->precision);
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
}
