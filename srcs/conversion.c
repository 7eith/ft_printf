/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conversion.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 04:54:36 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 15:26:12 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			pf_debug_print_flags(t_pfinfo *p)
{
	unsigned char flags = p->flags;

	if (flags & PF_MINUS)
		printf("[Flags] Minus\n");
	if (flags & PF_ZERO)
		printf("[Flags] Zero\n");
	if (flags & PF_STAR)
		printf("[Flags] Star\n");
	if (flags & PF_WIDTH)
		printf("[Flags] Width\n");
	if (flags & PF_PRECIS)
		printf("[Flags] Precision\n");
	if (flags & PF_PLUS)
		printf("[Flags] Plus\n");
 	if (flags & PF_SPACE)
		printf("[Flags] Space\n");
	if (flags & PF_HASH)
		printf("[Flags] Hash\n");
}

void			convert(t_pfinfo *p)
{
	if (p->type == '%')
		pf_convert_char(p, 1);
	if (p->type == 'c')
		pf_convert_char(p, 0);
	if (p->type == 's')
		pf_convert_string(p);
	if (p->type == 'd')
		pf_convert_decimal(p);
	p->flags = 0;
}
