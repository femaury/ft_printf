/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:00:35 by femaury           #+#    #+#             */
/*   Updated: 2018/05/21 16:51:44 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
			ftp_fill_buffer(buff, format + start, pos - start +
					(format[pos + 1] == '%' ? 1 : 0));
			pos++;
			ftp_parsing(format, buff, args, &pos);
			start = pos;
		}
		else
			pos++;
	}
	if (start != pos)
		ftp_fill_buffer(buff, format + start, pos - start);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list		args;
	t_buffer	buff;

	ft_strnclr(buff.str, BUFF_SIZE);
	buff.len = 0;
	buff.pos = 0;
	va_start(args, format);
	ft_readformat((char *)format, &buff, args);
	va_end(args);
	if (buff.pos)
		write(1, buff.str, buff.pos);
	buff.len += buff.pos;
	return (buff.len);
}
