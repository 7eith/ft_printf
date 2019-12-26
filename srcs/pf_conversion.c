/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_conversion.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 04:54:36 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 21:37:58 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			convert(t_pfinfo *p)
{
	p->type == '%' ? pf_convert_char(p, 1) : NULL;
	p->type == 'c' ? pf_convert_char(p, 0) : NULL;
	p->type == 'p' ? pf_convert_pointer(p) : NULL;
	p->type == 's' ? pf_convert_string(p) : NULL;
	p->type == 'n' ? pf_bind_ptr(p) : NULL;
	pf_convert_bonus(p);
	p->flags = 0;
}
