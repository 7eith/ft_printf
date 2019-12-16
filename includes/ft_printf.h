/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 17:36:58 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 14:31:16 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

# define PF_TYPES 		"cspdiuxX%"
# define PF_FLAGS		"-0+ "

# define DEC_BASE 		"0123456789"
# define LOW_HEXA 		"0123456789abcdef"
# define UP_HEXA 		"0123456789ABCDEF"
# define OCTAL_BASE 	"01234567"
# define BIN_BASE		"01"

# define PF_MINUS		(1 << 0)
# define PF_ZERO		(1 << 1)
# define PF_STAR		(1 << 2)
# define PF_PRECIS		(1 << 3)
# define PF_WIDTH		(1 << 4)

/*
** Bonus
*/

# define PF_PLUS		(1 << 5)
# define PF_SPACE		(1 << 6)
# define PF_HASH		(1 << 7)

/*
**	flags:			encoded with bitwise check define at top
**	width:			if has width
**	precision:		precision, if s print only number in precision
**	type:			conversion type (c|s|d|...)
**	content:		chained list contains all part of content
**	count:			position in format
**	format:			format input
**	va:				va_list containing flags input
*/

typedef	struct			s_pfinfo
{
	unsigned char		flags;
	int					width;
	int					precision;
	int					type;
	struct s_pfcontent	*content;
	size_t				count;
	char				*format;
	va_list				va;
}						t_pfinfo;

typedef struct			s_pfcontent
{
	size_t				size;
	char				*content;
	struct s_pfcontent	*next;
}						t_pfcontent;

int						ft_printf (const char *format, ...) __attribute__((format(printf,1,2)));
int						ft_print(t_pfcontent *content);

void					parse(t_pfinfo *pf_infos);

void					convert(t_pfinfo *p);

/*
**	srcs/pf_converter.c
*/

void					pf_convert_char(t_pfinfo *p, int is_pourcent);
void					pf_convert_string(t_pfinfo *p);
void					pf_convert_decimal(t_pfinfo *p);

/*
**	srcs/pf_content.c
*/

void					pf_charadd(t_pfinfo *p, int c);
void					pf_stradd(t_pfinfo *p, char *str);

/*
**	srcs/pf_utilities.c
*/

char					*pf_create_zero_string(int width);
char					*pf_create_zero_string(int width);
void					pf_addspaces(t_pfinfo *p, int width);
void					pf_addzeros(t_pfinfo *p, int width);

char					*ft_strreplace(const char *str, char *target, char *substitute);

#endif
