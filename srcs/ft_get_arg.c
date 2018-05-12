/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:46:54 by femaury           #+#    #+#             */
/*   Updated: 2018/05/12 17:58:10 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_get_c(t_buffer *buff, va_list args, t_format fstring)
{
	char	c;

	c = (unsigned char)va_arg(args, int);
	if (buff)
	{
	}
	if (fstring.width > 1)
	{
	}
	else
	{
	}
}

static void	ft_get_s(t_buffer *buff, va_list args, t_format fstring)
{
	size_t	strlen;
	char	*str;

	if (fstring.hasprec && !fstring.prec)
		return ;
	str = va_arg(args, char *);
	strlen = ft_strlen(str);
	if (buff)
	{
	}
	if (fstring.width > strlen)
	{
	}
	else
	{
	}
}

void		ft_get_arg(t_buffer *buff, va_list args, t_format fstring)
{
	if (fstring.type == 'c')
		ft_get_c(buff, args, fstring);
	if (fstring.type == 's')
		ft_get_s(buff, args, fstring);
	ft_get_arg2(buff, args, fstring);
}
