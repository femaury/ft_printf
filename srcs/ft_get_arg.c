/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:46:54 by femaury           #+#    #+#             */
/*   Updated: 2018/05/11 16:40:06 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_get_c(char *buff, va_list args, t_format fstring)
{
	char	c;
	char	*str;
	char	*tofree;

	tofree = buff;
	c = (unsigned char)va_arg(args, int);
	if (fstring.width > 1)
	{
		if (!(str = (char *)ft_strnew(fstring.width, ' ')))
			return (NULL);
		if (!(fstring.flags & F_MINUS))
			str[fstring.width - 1] = c;
		else
			str[0] = c;
	}
	else
		str = ft_strnew(1, c);
	buff = ft_strnjoin(buff, str, ft_strlen(str));
	ft_strdel(&str);
	ft_strdel(&tofree);
	return (buff);
}

static void	ft_get_sext(char *str, char **str2, t_format fstring, int *freestr2)
{
	size_t	strlen;

	strlen = ft_strlen(str);
	if (!(*str2 = (char *)ft_strnew(fstring.width, ' ')))
		return ;
	*freestr2 = 1;
	if (!(fstring.flags & F_MINUS))
		ft_strncpy(*str2 + (fstring.width - fstring.prec), str,
				(fstring.prec ? fstring.prec : strlen));
	else
		ft_strncpy(*str2, str, (fstring.prec ? fstring.prec : strlen));
}

static char	*ft_get_s(char *buff, va_list args, t_format fstring)
{
	size_t	strlen;
	char	*str;
	char	*str2;
	char	*tofree;
	int		freestr2;

	if (fstring.hasprec && !fstring.prec)
		return (buff);
	tofree = buff;
	freestr2 = 0;
	str = va_arg(args, char *);
	strlen = ft_strlen(str);
	if (fstring.width > strlen)
		ft_get_sext(str, &str2, fstring, &freestr2);
	else
		str2 = str;
	buff = ft_strnjoin(buff, str2, ft_strlen(str2));
	if (freestr2)
		ft_strdel(&str2);
	ft_strdel(&tofree);
	return (buff);
}

char		*ft_get_arg(char *buff, va_list args, t_format fstring)
{
	if (fstring.type == 'c')
		return (ft_get_c(buff, args, fstring));
	if (fstring.type == 's')
		return (ft_get_s(buff, args, fstring));
	return (ft_get_arg2(buff, args, fstring));
}
