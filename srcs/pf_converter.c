/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_converter.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 04:57:06 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 06:46:29 by amonteli    ###    #+. /#+    ###.fr     */
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

// char		*pf_strresize(char *str, t_pfinfo *p)
// {
// 	char			*string;
// 	char			*tmp;
// 	const size_t	size = ft_strlen(str) + p->width - p->precision;

// 	string = ft_memset(ft_calloc(sizeof(char), size), ' ', p->width - p->precision);
// 	tmp = ft_strjoin(string, str);
// 	free(string);
// 	string = tmp;
// 	return (string);
// }

void		pf_convert_string(t_pfinfo *p)
{
	char	*str;

	str = va_arg(p->va, char *);
	if (!str)
		str = "(null)";
	if (!p->flags || ft_strlen(str) == (size_t)p->width)
		return (pf_add_content(p, str));
	if (p->flags & PF_WIDTH)
	{
		if (p->flags & PF_PRECIS && p->precision < (int)ft_strlen(str))
			pf_add_content(p, pf_create_blank_string(p->width - ft_strlen(str) + (ft_strlen(str) - p->precision)));
		else
			pf_add_content(p, pf_create_blank_string(ft_strlen(str) - p->width));
	}
	if (p->flags & PF_PRECIS)
		pf_add_content(p, ft_strncpy(ft_calloc(p->precision, sizeof(char)), str, p->precision));
	else
		pf_add_content(p, str);

	// if (p->flags & PF_WIDTH && ft_strlen(str) < (size_t)p->width)
	// {
	// 	pf_add_content(p, pf_create_blank_string(p->width - ft_strlen(str)));
	// 	pf_add_content(p, str);
	// }
	// if (p->flags & PF_PRECIS)
	// 	return (pf_add_content(p, ft_strncpy(ft_calloc(p->precision, sizeof(char)), str, p->precision)));
	// else if (p->flags & PF_MINUS && p->flags & PF_WIDTH)
	// 77yy8{
	// 	pf_add_content(p, str);
	// 	pf_add_content(p, pf_create_blank_string(p->width - ft_strlen(str)));
	// }
	// else if (p->flags & PF_MINUS)
	// {
	// 	pf_add_content(p, str);
	// 	return ;
	// }
	p->flags = 0;
}
