/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 17:32:47 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 23:04:57 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;

	str = NULL;

	va_start(ap, format);
	str = va_arg(ap, char *);
	if (!str)
		ft_putstr_fd("failed\n", 1);
	va_end(ap);
	ft_putstr_fd((char *)format, 1);
	// ft_putstr_fd(str, 1);
	return (0);
}
