/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_conversion.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 04:54:36 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/25 19:22:48 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			convert(t_pfinfo *p)
{
	if (p->type == '%')
		pf_convert_char(p, 1);
	if (p->type == 'c')
		pf_convert_char(p, 0);
	if (p->type == 's')
		pf_convert_string(p);
	if (p->type == 'd' || p->type == 'i')
		pf_convert_decimal(p);
	if (p->type == 'p')
		pf_convert_pointer(p);
	if (p->type == 'x' || p->type == 'X')
		pf_convert_hexa(p, p->type == 'x' ? LOW_HEXA : UP_HEXA,
		va_arg(p->va, unsigned int));
	if (p->type == 'u')
		pf_convert_unsigned(p);
	if (p->type == 'n')
		pf_bind_ptr(p);
	p->flags = 0;
}
