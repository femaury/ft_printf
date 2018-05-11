/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:20:21 by femaury           #+#    #+#             */
/*   Updated: 2018/05/11 17:13:21 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_add_spaceplus(char *str, char *nb, t_format fstring)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != nb[i])
		i++;
	if (fstring.flags & F_PLUS)
		str[--i] = '+';
	else
		str[--i] = ' ';
	return (str);
}

static char	*ft_get_d(char *buff, va_list args, t_format fstring)
{
	size_t	nblen;
	char	*nb;
	char	*str;
	char	*tofree;
	int		freestr;

	freestr = 0;
	nb = ft_itoa_base(va_arg(args, int), 10);
	nblen = ft_strlen(nb);
	if (fstring.hasprec && !fstring.prec)
		return (buff);
	if (fstring.width > nblen)
	{
		if (!(str = (char *)ft_strnew(fstring.width, ((fstring.flags & F_ZERO) &&
							!(fstring.flags & F_MINUS)) ? 0 : ' ')))
			return (NULL);
		freestr = 1;
		if (!(fstring.flags & F_MINUS))
			ft_strncpy(str + (fstring.width - fstring.prec), nb,
					fstring.prec ? fstring.prec : nblen);
		else
			ft_strncpy(str, nb, fstring.prec ? fstring.prec : nblen);
		if (((fstring.flags & F_PLUS) || (fstring.flags & F_SPACE)) && nb[0] != '-')
			str = ft_add_spaceplus(str, nb, fstring);
	}
	else
		str = nb;
	tofree = buff;
	buff = ft_strnjoin(buff, str, ft_strlen(str));
//	ft_strdel(&tofree);
	if (freestr)
		ft_strdel(&str);
	return (buff);
}

char		*ft_get_arg2(char *buff, va_list args, t_format fstring)
{
	if (fstring.type == 'd')
		return (ft_get_d(buff, args, fstring));
	return (buff);
}
