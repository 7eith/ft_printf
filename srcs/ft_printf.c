/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 17:32:47 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 21:40:46 by amonteli    ###    #+. /#+    ###.fr     */
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

int		ft_print(char *str)
{
	ft_putstr_fd(str, 1);
	return (1);
}

/*
**	1: create a structure containing all things needed,
**	2: parse into structure
**	3:
*/
int		ft_printf(const char *format, ...)
{
	t_pfinfo	*pf_infos;

	pf_infos = ft_initialise_pf_struct(format);
	va_start(pf_infos->va, format);
	if (!ft_strchr(format, '%') && write(1, format, ft_strlen(format)))
		return (ft_strlen(format));
	parse((char *)format, pf_infos);
	// print
	// clear chained list with lstclear
	va_end(pf_infos->va);
	return (0);
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
