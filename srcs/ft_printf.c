/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 17:32:47 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 02:05:54 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	t_pfinfo	*ft_initialise_pf_struct(const char *format)
{
	t_pfinfo	*list;

	if (!(list = malloc(sizeof(t_pfinfo))))
		return (NULL);
	list->flags = 0;
	list->width = 0;
	list->precision = -1;
	list->type = 0;
	list->content = NULL;
	list->count = 0;
	list->format = (char *)format;
	return (list);
}

int		ft_print(t_pfcontent *content)
{
	size_t		output_size;

	output_size = 0;
	while (content)
	{
		write(1, content->content, content->size);
		output_size += content->size;
		content = content->next;
	}
	return (1);
}

/*
**	1: create a structure containing all things needed,
**	2: parse into structure
**	3:
*/
int		ft_printf(const char *format, ...)
{
	t_pfinfo	*p;

	p = ft_initialise_pf_struct(format);
	va_start(p->va, format);
	if (!ft_strchr(format, '%') && write(1, format, ft_strlen(format)))
		return (ft_strlen(format));
	// pf_add_content(p, ft_substr(format, 0, ft_strchr_len(format, '%')));
	// pf_add_char(p, va_arg(p->va, int));
	// pf_add_content(p, ft_strdup("\n"));
	pf_add_content(p, ft_substr(format, 0, ft_strchr_len(format, '%')));
	p = parse(p);
	// while ((pf_infos = parse(pf_infos->format, pf_infos)))
	// {

	// }
	// while has flags
	// print
	// clear chained list with lstclear
	// printf("\033[1;31m[debug]starting PRINTING...\n\033[0m");
	va_end(p->va);
	return (ft_print(p->content));
}

// int		ft_printf(const char *format, ...)
// {
// 	va_list	ap;
// 	char	*str;
// 	int		nbr;
// 	int		size;

// 	str = NULL;

// 	va_start(ap, format);
// 	str = va_arg(ap, char *);
// 	nbr = va_arg(ap, int);
// 	va_end(ap);

// 	char *new_str = ft_strnstr(format, "%s", ft_strlen(format));

// 	size = (int)new_str - (int)format;

// 	char *to_print;

// 	to_print = ft_strjoin(ft_substr(format, 0, size), str);
// 	ft_print(to_print);
// 	ft_print(ft_itoa(nbr));
// 	return (0);
// }
