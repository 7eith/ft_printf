/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_content.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 20:22:32 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 20:27:46 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


static t_pfcontent	*pf_lstnew(char *content)
{
	t_pfcontent	*list;

	if (!(list = malloc(sizeof(t_pfcontent))))
		return (NULL);
	list->content = content;
	list->size = ft_strlen(content);
	list->next = NULL;
	return (list);
}


static void		pf_lstadd_back(t_pfcontent **alst, t_pfcontent *new)
{
	t_list	*lst;

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

int				pf_add_content(t_pfinfo *p, char *str)
{
	pf_lstadd_back(&p->content, pf_lstnew(str));
}
