/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:46:54 by femaury           #+#    #+#             */
/*   Updated: 2018/05/12 21:08:46 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_get_c(t_buffer *buff, va_list args, t_format fstring)
{
	char	c;

	c = (unsigned char)va_arg(args, int);
	if (fstring.width > 1)
	{
		if (fstring.flags & F_MINUS)
		{
			ft_fill_buffer(buff, &c, 1);
			ft_pad_buffer(buff, ' ', fstring.width - 1);
		}
		else
		{
			ft_pad_buffer(buff, ' ', fstring.width - 1);
			ft_fill_buffer(buff, &c, 1);
		}
	}
	else
		ft_fill_buffer(buff, &c, 1);
}

static void	ft_get_s(t_buffer *buff, va_list args, t_format fstring)
{
	size_t	strlen;
	char	*str;

	if (fstring.hasprec && !fstring.prec)
		return ;
	str = va_arg(args, char *);
	strlen = ft_strlen(str);
	if (fstring.width > strlen)
	{
		if (fstring.flags & F_MINUS)
		{
			ft_fill_buffer(buff, str, strlen);
			ft_pad_buffer(buff, ' ', fstring.width - strlen);
		}
		else
		{
			ft_pad_buffer(buff, ' ', fstring.width - strlen);
			ft_fill_buffer(buff, str, strlen);
		}
	}
	else
		ft_fill_buffer(buff, str, strlen);
}

void		ft_get_arg(t_buffer *buff, va_list args, t_format fstring)
{
	if (fstring.type == 'c')
		ft_get_c(buff, args, fstring);
	else if (fstring.type == 's')
		ft_get_s(buff, args, fstring);
	else if (fstring.type == 'd' || fstring.type == 'D' || fstring.type == 'i')
		ft_get_int(buff, args, fstring, 10);
	else if (fstring.type == 'u' || fstring.type == 'U')
		ft_get_int(buff, args, fstring, 10);
	else if (fstring.type == 'x' || fstring.type == 'X')
		ft_get_int(buff, args, fstring, 16);
	else if (fstring.type == 'o' || fstring.type == 'O')
		ft_get_int(buff, args, fstring, 8);
}
