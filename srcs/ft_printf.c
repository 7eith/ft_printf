/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 17:32:47 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 06:23:48 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	t_pfinfo	*ft_initialise_pf_struct(t_pfinfo *list, const char *format)
{
	list->flags = 0;
	list->width = 0;
	list->precision = 0;
	list->type = 0;
	list->content = NULL;
	list->count = 0;
	list->format = (char *)format;
	return (list);
}

// int					ft_print(t_pfinfo *p)
// {
// 	size_t			output_size;
// 	t_pfcontent		*content;

// 	output_size = 0;
// 	content = p->content;
// 	while (content)
// 	{
// 		write(1, content->content, content->size);
// 		output_size += content->size;
// 		content = content->next;
// 	}
// 	return (output_size);
// }

/*
** for print and free
*/

int					ft_print(t_pfinfo *p)
{
	size_t			output_size;
	t_pfcontent 	*content;
	t_pfcontent		*next;

	output_size = 0;
	content = p->content;
	while (content)
	{
		next = content->next;
		write(1, content->content, content->size);
		output_size += content->size;
		free(content->content);
		free(content);
		content = next;
	}
	return (output_size);
}

// TODO: Leaks, %n, %o %b +#
int					ft_printf(const char *format, ...)
{
	t_pfinfo	p;

	ft_initialise_pf_struct(&p, format);
	va_start(p.va, format);
	if (!ft_strchr(format, '%') && write(1, format, ft_strlen(format)))
		return (ft_strlen(format));
	while (ft_strchr(p.format + p.count, '%'))
	{
		pf_stradd(&p, ft_substr(format, p.count,
		ft_strchr_len(p.format + p.count, '%')));
		p.count += ft_strchr_len(p.format + p.count, '%');
		parse(&p);
		convert(&p);
	}
	pf_stradd(&p, ft_substr(format, p.count, ft_strlen(p.format + p.count)));
	va_end(p.va);
	return (ft_print(&p));
}
