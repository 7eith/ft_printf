/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_converter.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 04:57:06 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 01:52:59 by amonteli    ###    #+. /#+    ###.fr     */
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

void		pf_apply_minus(t_pfinfo *p, char *str)
{
	if (p->flags & PF_PRECIS)
		pf_add_content(p, ft_strncpy(
			ft_calloc(p->precision, sizeof(char)), str, p->precision));
	else
		pf_add_content(p, str);
	if (p->flags & PF_WIDTH && p->width > (int)ft_strlen(str))
		return (pf_add_content(p, pf_create_blank_string(p->width -
		(int)ft_strlen(str))));
	else
		pf_add_content(p, pf_create_blank_string(p->width - ft_strlen(str)
		+ (ft_strlen(str) - p->precision)));
	p->flags = 0;
}

void		pf_convert_string(t_pfinfo *p)
{
	char	*str;

	str = va_arg(p->va, char *);
	if (!str)
		str = "(null)";
	if (!p->flags || (ft_strlen(str) == (size_t)p->width &&
	!(p->flags & PF_PRECIS)))
		return (pf_add_content(p, str));
	if (p->flags & PF_MINUS)
		return (pf_apply_minus(p, str));
	if (p->flags & PF_WIDTH)
	{
		if (p->flags & PF_PRECIS && p->precision < (int)ft_strlen(str))
			pf_add_content(p, pf_create_blank_string(p->width - ft_strlen(str)
			+ (ft_strlen(str) - p->precision)));
		else
			pf_add_content(p, pf_create_blank_string(
				ft_strlen(str) - p->width));
	}
	if (p->flags & PF_PRECIS)
		pf_add_content(p, ft_strncpy(ft_calloc(
			p->precision, sizeof(char)), str, p->precision));
	else
		pf_add_content(p, str);
	p->flags = 0;
}
