/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_numlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 03:04:51 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 03:06:23 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int			ft_numlen(int number)
{
	int		count;

	count = 0;
	if (number < 0)
		number = -number;
	while (number > 9)
	{
		number /= 10;
		count++;
	}
	return (count + 1);
}
