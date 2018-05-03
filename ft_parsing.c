/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 18:12:12 by femaury           #+#    #+#             */
/*   Updated: 2018/05/03 18:40:48 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define EQU_FLAGS(c) c == '-' || c == '+' || c == ' ' || c == '0' || c == '#'
#define EQU_LENFLAGS(c) c == 'h' || c == 'l' || c == 'j' || c == 'z'
#define EQU_TYPES(c) c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || \
c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || \
c == 'X' || c == 'c' || c == 'C'

static void	ft_parsing_flags(const char * restrict format, t_format fstring,
		int i[2])
{
	while (EQU_FLAGS(format[i[0]]))
	{
		else if (format[i[0]] == ' ')
			fstring.flags |= F_SPACE;
		else if (format[i[0]] == '#')
			fstring.flags |= F_HASH;
		else if (format[i[0]] == '+')
			fstring.flags |= F_PLUS;
		else if (format[i[0]] == '-')
			fstring.flags |= F_MINUS;
		else if (format[i[0]] == '0')
			fstring.flags |= F_ZERO;
		i[0]++;
	}
}

static void	ft_parsing_lenflags(const char * restrict format,
		t_format fstring, int i[2])
{
	if (format[i[0]] == 'h' && format[i[0] + 1] == 'h')
		fstring.lflags |= LF_CTOI;
	else if (format[i[0]] == 'h')
		fstring.lflags |= LF_SHTOI;
	else if (format[i[0]] == 'l' && format[i[0] + 1] == 'l')
		fstring.lflags |= LF_LLONG;
	else if (format[i[0]] == 'l')
		fstring.lflags |= LF_LONG;
	else if (format[i[0]] == 'j')
		fstring.lflags |= LF_IMAX;
	else if (format[i[0]] == 'z')
		fstring.lflags |= LF_SIZE;
	i[0]++;
}

static void	ft_parsing_digits(const char * restrict format, t_format fstring,
		int i[2])
{
	if (ft_isdigit(format[i[0]]))
		fstring.width = ft_atoi(format[i[0]]);
	while (ft_isdigit(format[i[0]]) && format[i[0]] != '.')
		i[0]++;
	if (format[i[0]] == '.')
		fstring.precision = ft_atoi(format[++i[0]]);
}

void		ft_parsing(const char * restrict format, char *buff, va_list args, int i[2])
{
	t_format	fstring;

	ft_parsing_flags(format, fstring, i);
	ft_parsing_digits(format, fstring, i);
	ft_parsing_lenflags(format, fstring, i);
	fstring.type = format[i[0]++];
	ft_get_arg(buff, args, fstring, i);
}
