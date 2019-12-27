/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_converter.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 04:57:06 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 02:10:01 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		pf_convert_uminus(t_pfinfo *p, char *str)
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

void			pf_convert_unsigned(t_pfinfo *p, long long number)
{
	const	char		*str = ft_ulltoa_base(number, DEC_BASE);
	int					len;

	if (!p->flags)
		return (pf_stradd(p, (char *)str));
	if (p->flags & PF_PRECIS && !p->precision && !number)
	{
		free((char *)str);
		return (pf_addspaces(p, p->width));
	}
	if (p->flags & PF_MINUS)
		return (pf_convert_uminus(p, (char *)str));
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
	return (pf_stradd(p, (char *)str));
}

void			pf_convert_pointer(t_pfinfo *p)
{
	const	intptr_t	ptr = (intptr_t)va_arg(p->va, void *);
	char				*str;

	if (p->flags & PF_PRECIS && !ptr)
		str = ft_strdup("0x");
	else
		str = ft_strjoin(ft_strdup("0x"),
		ft_ulltoa_base((unsigned long long)ptr, LOW_HEXA));
	if (p->flags & PF_WIDTH && !(p->flags & PF_MINUS)
	&& p->width > (int)ft_strlen(str))
		pf_addspaces(p, p->width - ft_strlen(str));
	pf_stradd(p, str);
	if (p->flags & PF_WIDTH && p->flags & PF_MINUS
	&& p->width > (int)ft_strlen(str))
		pf_addspaces(p, p->width - ft_strlen(str));
}

void			pf_convert_char(t_pfinfo *p, int is_pourcent)
{
	const char	c = is_pourcent ? '%' : va_arg(p->va, int);

	if (p->flags & PF_MINUS)
	{
		pf_charadd(p, c);
		if (p->width > 1)
			pf_addspaces(p, p->width - 1);
		return ;
	}
	if (p->width > 1 && p->flags & PF_ZERO)
		pf_addzeros(p, p->width - 1);
	else if (p->flags & PF_WIDTH && p->width > 1)
		pf_addspaces(p, p->width - 1);
	pf_charadd(p, c);
}

void			pf_convert_string(t_pfinfo *p)
{
	char	*str;

	str = va_arg(p->va, char *);
	if (!str)
		str = "(null)";
	str = ft_strdup(str);
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
