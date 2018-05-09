/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:46:54 by femaury           #+#    #+#             */
/*   Updated: 2018/05/09 21:14:35 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_get_c(char *buff, va_list args)
{
	char	c;
	char	*tofree;

	tofree = buff;
	c = (char)va_arg(args, int);
	buff = ft_strnjoin(buff, &c, 1);
	ft_strdel(&tofree);
	return (buff);
}

char	*ft_get_s(char *buff, va_list args)
{
	char	*str;
	char	*tofree;

	tofree = buff;
	str = va_arg(args, char *);
	buff = ft_strnjoin(buff, str, ft_strlen(str));
	ft_strdel(&tofree);
	return (buff);
}

char	*ft_get_arg(char *buff, va_list args, t_format fstring)
{
	if (fstring.type == 'c')
		buff = ft_get_c(buff, args);
	else if (fstring.type == 's')
		buff = ft_get_s(buff, args);
	return (buff);
}
