/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 18:12:12 by femaury           #+#    #+#             */
/*   Updated: 2018/05/10 14:46:25 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define EQU_FLAGS(c) c == '-' || c == '+' || c == ' ' || c == '0' || c == '#'
#define EQU_LFLAGS(c) c == 'h' || c == 'l' || c == 'j' || c == 'z'

static const char *ft_parsing_flags(const char * restrict format, t_format *fstring,
		int i[4])
{
	while (EQU_FLAGS(*format))
	{
		if (*format == ' ')
			fstring->flags |= F_SPACE;
		else if (*format == '#')
			fstring->flags |= F_HASH;
		else if (*format == '+')
			fstring->flags |= F_PLUS;
		else if (*format == '-')
			fstring->flags |= F_MINUS;
		else if (*format == '0')
			fstring->flags |= F_ZERO;
		i[3]++;
		format++;
	}
	return (format);
}

static const char *ft_parsing_lenflags(const char * restrict format, t_format *fstring,
		int i[4])
{
	if (EQU_LFLAGS(*format))
	{
		if (*format == 'h' && *(format + 1) == 'h')
		{
			i[3]++;
			format++;
			fstring->lflags |= LF_CTOI;
		}
		else if (*format == 'h')
			fstring->lflags |= LF_SHTOI;
		else if (*format == 'l' && *(format + 1) == 'l')
		{
			i[3]++;
			format++;
			fstring->lflags |= LF_LLONG;
		}
		else if (*format == 'l')
			fstring->lflags |= LF_LONG;
		else if (*format == 'j')
			fstring->lflags |= LF_IMAX;
		else if (*format == 'z')
			fstring->lflags |= LF_SIZE;
		format++;
		i[3]++;
	}
	return (format);
}

static const char *ft_parsing_digits(const char * restrict format, t_format *fstring,
		int i[4])
{
	if (ft_isdigit(*format))
		fstring->width = ft_atoi(format);
	while (ft_isdigit(*format))
	{
		i[3]++;
		format++;
	}
	if (*format == '.')
	{
		fstring->hasprec = 1;
		fstring->prec = ft_atoi(format + 1);
		format++;
		i[3]++;
	}
	while (ft_isdigit(*format))
	{
		i[3]++;
		format++;
	}
	return (format);
}

char				*ft_parsing(const char * restrict format, char *buff, va_list args, int i[4])
{
	t_format	fstring;

	fstring.flags = 0;
	fstring.lflags = 0;
	fstring.width = 0;
	fstring.hasprec = 0;
	fstring.prec = 0;
	fstring.type = 0;
	format = ft_parsing_flags(format, &fstring, i);
	format = ft_parsing_digits(format, &fstring, i);
	format = ft_parsing_lenflags(format, &fstring, i);
	fstring.type = *format;
	i[3]++;
	return (ft_get_arg(buff, args, fstring));
}
