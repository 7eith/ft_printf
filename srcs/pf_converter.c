/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_converter.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/07 04:57:06 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 18:05:38 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			debg(t_pfinfo *p)
{
	unsigned char flags = p->flags;

	if (flags & PF_MINUS)
		printf("[Flags] Minus\n");
	if (flags & PF_ZERO)
		printf("[Flags] Zero\n");
	if (flags & PF_STAR)
		printf("[Flags] Star\n");
	if (flags & PF_WIDTH)
		printf("[Flags] Width\n");
	if (flags & PF_PRECIS)
		printf("[Flags] Precision\n");
	if (flags & PF_PLUS)
		printf("[Flags] Plus\n");
 	if (flags & PF_SPACE)
		printf("[Flags] Space\n");
	if (flags & PF_HASH)
		printf("[Flags] Hash\n");
}


void		pf_dminus(t_pfinfo *p, long number)
{
	if (number < 0)
	{
		number *= -1;
		printf("is negative\n");
		printf("number is =%ld\n", number);
		p->width--;
		pf_charadd(p, '-');
	}
	if (p->flags & PF_PRECIS)
	{
		printf("added zeros\n");
		pf_addzeros(p, ft_numlen(number) - p->precision);
	}
	printf("enculer de merde %s\n", ft_itoa(number));
	pf_stradd(p, ft_itoa(number));
	if (p->flags & PF_WIDTH)
	{
		printf("added spaces\n");
		pf_addspaces(p, p->width - ft_numlen(number));
	}
}

void		pf_convert_decimal(t_pfinfo *p)
{
	long	number;

	number = va_arg(p->va, int);
	if (!p->flags)
		return (pf_stradd(p, ft_itoa(number)));
	if (p->flags & PF_MINUS)
		return (pf_dminus(p, number));
	if (p->flags & PF_PRECIS && !(p->flags & PF_WIDTH))
	{
		if (number < 0)
			pf_charadd(p, '-');
		pf_addzeros(p, p->precision - ft_numlen(number));
		return (pf_stradd(p, ft_itoa(number < 0 ? number * -1 : number)));
	}
	if (p->flags & PF_PRECIS && p->flags & PF_WIDTH)
	{
		if (number < 0)
			p->width--;
		printf("width=%d, numlen=%d, precision=%d\n", p->width, ft_numlen(number), p->precision);
		pf_addspaces(p, p->width - p->precision);
		pf_charadd(p, '-');
		pf_addzeros(p, p->precision - ft_numlen(number));
		return (pf_stradd(p, ft_itoa(number < 0 ? number * -1 : number)));
	}
	if (p->flags & PF_WIDTH)
	{
		if (number < 0)
			p->width--;
		pf_addspaces(p, p->width - ft_numlen(number));
		return (pf_stradd(p, ft_itoa(number)));
	}
}

// twice[    -00123]

// void		pf_convert_decimal(t_pfinfo *p)
// {
// 	int		number;

// 	number = va_arg(p->va, int);
// 	if (!p->flags)
// 		return (pf_stradd(p, ft_itoa(number)));
// 	if (number < 0)
// 	{
// 		if (p->flags & PF_ZERO)
// 		{
// 			pf_charadd(p, '-');
// 			number *= -1;
// 		}
// 		p->width--;
// 	}
// 	if (p->flags & PF_PRECIS && p->precision > ft_numlen(number))
// 		pf_addzeros(p, p->precision - ft_numlen(number));
// 	if (p->flags & PF_MINUS)
// 	{
// 		pf_stradd(p, ft_itoa(number));
// 		if (p->flags & PF_WIDTH && p->width > (int)ft_numlen(number))
// 			pf_addspaces(p, p->width - (int)ft_numlen(number));
// 		return ;
// 	}
// 	if (p->flags & PF_WIDTH && p->width > (int)ft_numlen(number))
// 		pf_addspaces(p, p->width - (int)ft_numlen(number));
// 	pf_stradd(p, ft_itoa(number));
// 	p->flags = 0;
// }

void		pf_convert_char(t_pfinfo *p, int is_pourcent)
{
	const char	c = is_pourcent ? '%' : va_arg(p->va, int);

	if (p->flags & PF_MINUS)
	{
		pf_charadd(p, c);
		if (p->width > 1)
			pf_addspaces(p, p->width - 1);
		return ;
	}
	if (p->flags & PF_WIDTH && p->width > 1)
		pf_addspaces(p, p->width - 1);
	pf_charadd(p, c);
}

void		pf_convert_string(t_pfinfo *p)
{
	char	*str;

	str = va_arg(p->va, char *);
	if (!str)
		str = "(null)";
	if (!p->flags)
		return (pf_stradd(p, str));
	if (p->flags & PF_PRECIS)
		str = ft_strncpy(ft_calloc(p->precision + 1, sizeof(char)), str,
		p->precision);
	if (p->flags & PF_MINUS)
	{
		pf_stradd(p, str);
		if (p->flags & PF_WIDTH && p->width > (int)ft_strlen(str))
			pf_addspaces(p, p->width - (int)ft_strlen(str));
		return ;
	}
	if (p->flags & PF_WIDTH && p->width > (int)ft_strlen(str))
		pf_addspaces(p, p->width - (int)ft_strlen(str));
	pf_stradd(p, str);
}
