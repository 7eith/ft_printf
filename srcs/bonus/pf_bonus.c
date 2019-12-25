/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_bonus.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 11:41:11 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/25 11:43:58 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void			pf_bind_ptr(t_pfinfo *p)
{
	t_pfcontent	*content;
	int			size;
	int			*ptr;

	if (!(ptr = va_arg(p->va, void *)))
		return ;
	content = p->content;
	size = 0;
	while (content)
	{
		size += content->size;
		content = content->next;
	}
	*ptr = size;
}
