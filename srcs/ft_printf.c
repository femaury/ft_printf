/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:00:35 by femaury           #+#    #+#             */
/*   Updated: 2018/05/12 18:24:40 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* ---------- LEGEND ---------- */
/*                              */
/*   pos: pos in format         */
/*   start: already read chars  */
/*                              */
/* ---------------------------- */

static void	ft_readformat(char *format, t_buffer *buff, va_list args)
{
	int		pos;
	int		start;

	pos = 0;
	start = 0;
	while (format[pos])
	{
		if (format[pos] == '%')
		{
//			printf("Calling fill with start: %d and pos: %d\n", start, pos);
			ft_fill_buffer(buff, format + start, pos - start +
					(format[pos + 1] == '%' ? 1 : 0));
			pos++;
			ft_parsing(format, buff, args, &pos);
//			printf("\n---- AFTER PARSING ----\n\nformat: %s\nbuff: %s\npos: %d\nstart: %d\n-----------------------\n", format, buff->str, pos, start);
			start = pos;
		}
		else
			pos++;
	}
//	printf("\n---- BEFORE LAST JOIN ----\n\nformat: %s\nbuff: %s\npos: %d\nstart: %d\n-------------------------\n", format, buff->str, pos, start);
	if (start != pos)
		ft_fill_buffer(buff, format + start, pos - start);
}

int			ft_printf(const char * restrict format, ...)
{
	va_list		args;
	t_buffer	buff;

	ft_strnclr(buff.str, BUFF_SIZE);
	buff.len = 0;
	buff.pos = 0;
	va_start(args, format);
	ft_readformat((char *)format, &buff, args);
	va_end(args);
	if (buff.str[0])
		write(1, buff.str, buff.pos);
	buff.len += buff.pos;
	return (buff.len);
}

