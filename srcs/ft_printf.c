/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:00:35 by femaury           #+#    #+#             */
/*   Updated: 2018/05/11 19:34:58 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* ---------- LEGEND ---------- */
/*                              */
/*   i[0]: pos in format        */
/*   i[1]: already read chars   */
/*   i[2]: chars not to print   */
/*   i[3]: flag chars after %   */
/*                              */
/* -----------------------------*/

static char	*ft_join_strings(int i[4], int size, char buff)
{
	char	*tofree;

	tofree = buff;
	buff = ft_strnjoin(buff, format - (i[0] - i[1] - (i[2] ? 1 - i[2] : 0)),
				(size_t)size);
	if (buff != tofree)
		ft_strdel(&tofree);
	return (buff);
}

static char	*ft_readformat(const char * restrict format, char *buff,
		va_list args, int i[4])
{
	int		check;
	char	*tofree;

	while (*format)
	{
		if (*format == '%')
		{
			buff = ft_join_strings((i, *(format + 1) == '%'
							? i[0] - i[1] - (IF_I2) + 1
							: i[0] - i[1] - (IF_I2)), buff);
			format++;
			buff = ft_parsing(format, buff, args, i);
			format += i[3] ? i[3] - 1 : 0;
			i[2] += i[3];
//			printf("\n---- AFTER PARSING ----\n\nformat: %s\nbuff: %s\ni[0]: %d\ni[1]: %d\ni[2]: %d\ni[3]: %d\n-----------------------\n", format, buff, i[0], i[1], i[2], i[3]);
			if (*(format) == '%')
				i[2]++;
			i[1] = i[0] + i[2];
			check = i[0];
		}
		format++;
		i[0]++;
	}
//	printf("\n---- BEFORE LAST JOIN ----\n\nformat: %s\nbuff: %s\ni[0]: %d\ni[1]: %d\ni[2]: %d\ni[3]: %d\ncheck: %d\n-------------------------\n", format, buff, i[0], i[1], i[2], i[3], check);
	if (check != i[0] - 1)
		JOIN_STR((i[0] - i[1] - (IF_I2)), (i[0] - i[1] - (IF_I2)))
	return (buff);
}

int			ft_printf(const char * restrict format, ...)
{
	va_list	args;
	char	*buff;
	int		i[4];
	int		len;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	buff = ft_strnew(0, '\0');
	va_start(args, format);
	buff = ft_readformat(format, buff, args, i);
	va_end(args);
	len = ft_strlen(buff);
	ft_putstr(buff);
	ft_strdel(&buff);
	return (len);
}

