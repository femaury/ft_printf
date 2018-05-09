/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:00:35 by femaury           #+#    #+#             */
/*   Updated: 2018/05/09 21:14:07 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>

static char	*ft_readformat(const char * restrict format, char *buff,
		va_list args, int i[4])
{
	int		check;
	char	*tofree;

	(void)args;
	while (*format)
	{
		if (*format == '%')
		{
			JOIN_STR((i[0] - i[1] - (IF_I2)), (*(format + 1) == '%'
						? (i[0] - i[1] - (IF_I2) + 1)
						: (i[0] - i[1] - (IF_I2))))
			format++;
			if (*format && *format != '%')
				buff = ft_parsing(format, buff, args, i);
			if (*(format) == '%')
				i[2]++;
			i[1] = i[0] + i[2];
			check = i[0];
		}
		format++;
		i[0]++;
	}
	if (check != i[0] - 1)
		JOIN_STR((i[0] - i[1] - (IF_I2)), (i[0] - i[1] - (IF_I2)))
	return (buff);
}

int			ft_printf(const char * restrict format, ...)
{
	va_list	args;
	char	*buff;
	int		i[4];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	buff = ft_strnew(0);
	va_start(args, format);
	buff = ft_readformat(format, buff, args, i);
	va_end(args);
	i[3] = ft_strlen(buff);
	ft_putstr(buff);
	ft_strdel(&buff);
	return (i[3]);
}

int		main(void)
{
	printf("Count: %d\n", ft_printf("Je test mon printf %s big test %s\n", "avec un", "de malade"));
	ft_printf("Je test mon printf v2\n");
	ft_printf("%%\n");
	ft_printf("Je test mon printf avec un char: %c", 'c');
	ft_printf("\n");
	return (0);
}
