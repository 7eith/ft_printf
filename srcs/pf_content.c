/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_content.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 20:22:32 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/07 05:01:43 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_pfcontent	*pf_lstnew(char *content, char has_char)
{
	t_pfcontent	*list;

	if (!(list = malloc(sizeof(t_pfcontent))))
		return (NULL);
	list->content = content;
	if (has_char)
		list->size = 1;
	else
		list->size = ft_strlen(content);
	list->next = NULL;
	return (list);
}

static void		pf_lstadd_back(t_pfcontent **alst, t_pfcontent *new)
{
	t_pfcontent	*lst;

	if (!alst || !new)
		return ;
	if (!(*alst))
		*alst = new;
	else
	{
		lst = *alst;
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}

int				pf_add_char(t_pfinfo *p, int c)
{
	char	*str;

	if (c != '\0')
	{
		str = ft_strdup(" ");
		str[0] = c;
	}
	else
		str = ft_strdup("");
	pf_lstadd_back(&p->content, pf_lstnew(str, 1));
	return (1);
}

/*
**	pf_add_content
**	@description:		add content to chained list who contain output of printf.
**	@param:				struct t_pfinfo, string str.
**	@return:			1 parsed or 0 nothing to parse, maybe -1 if error
*/

void			pf_add_content(t_pfinfo *p, char *str)
{
	pf_lstadd_back(&p->content, pf_lstnew(str, 0));
}
