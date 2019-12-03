/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/17 17:17:50 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 06:21:33 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		debug__print_structure(t_pfinfo *p)
{
	struct s_pfcontent	*list;
	list = p->content;
	printf("======= DEBUG =======\n");
	printf("format=%s\n", p->format);
	printf("flags=%d\n", p->flags);
	printf("width=%d\n", p->width);
	printf("precision=%d\n", p->precision);
	printf("type=%d\n\n", p->type);

	if (!list)
		printf("[Error] empty pf_content...\n");
	while (list)
	{
		printf("size=%zu - content=%s\n", list->size, list->content);
		list = list->next;
	}
	printf("======================\n");

}

// static	int			ft_is_flag(char c)
// {
// 	size_t		count;

// 	count = 0;
// 	while(PF_FLAGS[count])
// 	{
// 		if (PF_FLAGS[count] == c)
// 			return (1);
// 		count++;
// 	}
// 	return (0);
// }

// void				parse_flags(char *format, t_pfinfo *pf_infos)
// {
// 	pf_infos->count = ft_strchr_len(format, '%') + 1;
// } // useless not?

t_pfinfo			*parse(char	*format, t_pfinfo *pf_infos)
{
	if (!ft_strchr(format, '%'))
		return (NULL); // TODO: return and print str and size
	pf_infos->count = ft_strchr_len(format, '%') + 1;
	if (format[pf_infos->count] == '-')
		pf_infos->flags |= PF_MINUS;
	if (format[pf_infos->count + 1] == '*')
	{
		pf_infos->flags |= PF_STAR;
		pf_infos->width = va_arg(pf_infos->va, int);
	}
	debug__print_structure(pf_infos); // TODO: reorganiser le code psk wtf
	return (pf_infos);
}
