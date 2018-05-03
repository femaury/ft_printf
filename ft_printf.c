/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:00:35 by femaury           #+#    #+#             */
/*   Updated: 2018/05/03 14:42:08 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>

static char	*ft_readformat(const char * restrict format, char *buff,
		va_list args, int i[2])
{
	char	*tofree;

	(void)args;
	while (*format)
	{
		if (*format == '%')
		{
			tofree = buff;
			buff = ft_strnjoin(buff, format - i[0],
					(*(format + 1) == '%' ? (size_t)(i[0] + 1) : (size_t)i[0]));
			ft_strdel(&tofree);
			format++;
//			if (*format != '%' && *(format + 1))
//				ft_parsing(format + 1, buff, args, i)
		}
		format++;
		i[0]++;
	}
	return (buff);
}

int			ft_printf(const char * restrict format, ...)
{
	va_list	args;
	char	*buff;
	int		i[2];

	i[0] = 0;
	buff = ft_strnew(0);
	va_start(args, format);
	buff = ft_readformat(format, buff, args, i);
	va_end(args);
	i[1] = ft_strlen(buff);
	ft_putstr(buff);
	ft_strdel(&buff);
	return (i[1]);
}

int		main(void)
{
	printf("\n%d\n", ft_printf("Je test mon printf %%\n"));
	return (0);
}
