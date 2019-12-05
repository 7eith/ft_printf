/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/17 17:17:50 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 02:19:54 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				debug__print_structure(t_pfinfo *p)
{
	struct s_pfcontent	*list;

	list = p->content;
	printf("======= DEBUG =======\n");
	printf("format=%s\n", p->format);
	printf("flags=%d\n", p->flags);
	printf("width=%d\n", p->width);
	printf("precision=%d\n", p->precision);
	printf("type=%c\n\n", p->type);
	if (!list)
		printf("[Error]empty pf_content...\n");
	while (list)
	{
		printf("[debug]size=%zu - content=%s\n", list->size, list->content);
		list = list->next;
	}
	printf("======================\n");
}

/*
** static	int			pf_is_type(char c)
** {
** 	size_t		count;
**
** 	count = 0;
** 	while (PF_TYPES[count])
** 	{
** 		if (PF_TYPES[count] == c)
** 			return (1);
** 		count++;
** 	}
** 	return (0);
** }
*/

static	int			pf_is_flag(char c)
{
	size_t		count;

	count = 0;
	while (PF_FLAGS[count])
	{
		if (PF_FLAGS[count] == c)
			return (1);
		count++;
	}
	return (0);
}

/*
**	parse_flags(struct printf_infos)
**	@description:		parse flags and put in @param
**	@param:				struct t_pfinfo
**	@return:			(?)
*/

int					parse_flags(t_pfinfo *p)
{
	p->count = ft_strchr_len(p->format, '%') + 1;
	while (p->format[p->count] && pf_is_flag(p->format[p->count]))
	{
		if (p->format[p->count] == '-')
			p->flags |= PF_MINUS;
		else if (p->format[p->count] == '+')
			p->flags |= PF_PLUS;
		else if (p->format[p->count] == '0')
			p->flags |= PF_ZERO;
		else if (p->format[p->count] == '#')
			p->flags |= PF_HASH;
		else if (p->format[p->count] == ' ')
			p->flags |= PF_SPACE;
		p->count++;
	}
	return (1);
}

/*
**	parse_size(struct printf_infos)
**	@description:		parse size and put in @param
**	@param:				struct t_pfinfo
**	@return:			(?)
*/

int					parse_size(t_pfinfo *p)
{
	if (p->format[p->count] == '*')
	{
		p->flags |= PF_STAR;
		p->width = va_arg(p->va, int);
		p->count++;
	}
	else if (ft_isdigit(p->format[p->count]))
	{
		p->flags |= PF_WIDTH;
		p->width = ft_atoi(p->format + p->count);
		p->count++;
	}
	if (p->format[p->count] == '.')
	{
		p->flags |= PF_PRECIS;
		p->count++;
		if (p->format[p->count] == '*')
			p->precision = va_arg(p->va, int);
		else
			p->precision = ft_atoi(p->format + p->count);
		p->count++;
	}
	return (1);
}

t_pfinfo			*parse(t_pfinfo *p)
{
	parse_flags(p);
	parse_size(p);
	p->type = p->format[p->count];
	debug__print_structure(p);
	return (p);
}
