/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 17:41:19 by femaury           #+#    #+#             */
/*   Updated: 2018/05/14 16:20:24 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_get_c(t_buffer *buff, va_list args, t_format fstr)
{
	char	c;

	c = (unsigned char)va_arg(args, int);
	if (WIDTH > 1)
	{
		if (FLAGS & F_MINUS)
		{
			ft_pad_buffer(buff, c, 1, 0);
			ft_pad_buffer(buff, ' ', WIDTH - 1, 0);
		}
		else
		{
			ft_pad_buffer(buff, ' ', WIDTH - 1, 0);
			ft_pad_buffer(buff, c, 1, 0);
		}
	}
	else
		ft_pad_buffer(buff, c, 1, 0);
}

static void	ft_get_s(t_buffer *buff, va_list args, t_format fstr)
{
	size_t	strlen;
	char	*str;

	if (fstr.hasprec && !PREC && !WIDTH)
		return ;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	strlen = (fstr.hasprec && PREC < strlen ? PREC : strlen);
	if (WIDTH > strlen)
	{
		if (FLAGS & F_MINUS)
		{
			ft_fill_buffer(buff, str, strlen);
			ft_pad_buffer(buff, ' ', WIDTH - strlen, 0);
		}
		else
		{
			ft_pad_buffer(buff, ' ', WIDTH - strlen, 0);
			ft_fill_buffer(buff, str, strlen);
		}
	}
	else
		ft_fill_buffer(buff, str, strlen);
}

void		ft_get_str(t_buffer *buff, va_list args, t_format fstr)
{
	if (TYPE == 'c')
		ft_get_c(buff, args, fstr);
	else if (TYPE == 's')
		ft_get_s(buff, args, fstr);
}
