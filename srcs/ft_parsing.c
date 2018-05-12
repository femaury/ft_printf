/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:12:12 by femaury           #+#    #+#             */
/*   Updated: 2018/05/12 18:20:29 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_parsing_flags(char *format, t_format *fstring, int *pos)
{
	while (format[*pos] == '-' || format[*pos] == '+' || format[*pos] == ' ' ||
			format[*pos] == '0' || format[*pos] == '#')
	{
		if (format[*pos] == ' ')
			fstring->flags |= F_SPACE;
		else if (format[*pos] == '#')
			fstring->flags |= F_HASH;
		else if (format[*pos] == '+')
			fstring->flags |= F_PLUS;
		else if (format[*pos] == '-')
			fstring->flags |= F_MINUS;
		else if (format[*pos] == '0')
			fstring->flags |= F_ZERO;
		*pos += 1;
	}
}

static void	ft_parsing_lenflags(char *format, t_format *fstring, int *pos)
{
	if (format[*pos] == 'h' && format[*pos + 1] == 'h')
	{
		*pos += 1;
		fstring->lflags |= LF_CTOI;
	}
	else if (format[*pos] == 'h')
		fstring->lflags |= LF_SHTOI;
	else if (format[*pos] == 'l' && format[*pos + 1] == 'l')
	{
		*pos += 1;
		fstring->lflags |= LF_LLONG;
	}
	else if (format[*pos] == 'l')
		fstring->lflags |= LF_LONG;
	else if (format[*pos] == 'j')
		fstring->lflags |= LF_IMAX;
	else if (format[*pos] == 'z')
		fstring->lflags |= LF_SIZE;
	if (format[*pos] == 'h' || format[*pos] == 'l' || format[*pos] == 'j' ||
			format[*pos] == 'z')
		*pos += 1;
}

static void	ft_parsing_digits(char *format, t_format *fstring, int *pos)
{
	if (ft_isdigit(format[*pos]))
		fstring->width = ft_atoi(format + *pos);
	while (ft_isdigit(format[*pos]))
		*pos += 1;
	if (format[*pos] == '.')
	{
		*pos += 1;
		fstring->hasprec = 1;
		fstring->prec = ft_atoi(format + *pos);
	}
	while (ft_isdigit(format[*pos]))
		*pos += 1;
}

void		ft_parsing(char *format, t_buffer *buff, va_list args, int *pos)
{
	t_format	fstring;

	if (format[*pos] && format[*pos] != '%')
	{
		fstring.flags = 0;
		fstring.lflags = 0;
		fstring.width = 0;
		fstring.hasprec = 0;
		fstring.prec = 0;
		fstring.type = 0;
		ft_parsing_flags(format, &fstring, pos);
		ft_parsing_digits(format, &fstring, pos);
		ft_parsing_lenflags(format, &fstring, pos);
		fstring.type = format[*pos];
		*pos += 1;
		ft_get_arg(buff, args, fstring);
	}
	else if (format[*pos] == '%')
		*pos += 1;
}
