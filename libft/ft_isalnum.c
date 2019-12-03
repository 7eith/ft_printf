/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isalnum.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 13:16:11 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 13:21:18 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9') ? 1 : 0);
}