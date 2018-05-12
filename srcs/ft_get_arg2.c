/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:20:21 by femaury           #+#    #+#             */
/*   Updated: 2018/05/12 17:59:12 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_get_d(t_buffer *buff, va_list args, t_format fstring)
{
	size_t	nblen;
	char	*nb;

	nb = ft_itoa_base(va_arg(args, int), 10);
	nblen = ft_strlen(nb);
	if (fstring.hasprec && !fstring.prec)
		return ;
	if (buff)
	{
	}
	if (fstring.width > nblen)
	{
	}
	else
	{
	}
}

void		ft_get_arg2(t_buffer *buff, va_list args, t_format fstring)
{
	if (fstring.type == 'd')
		ft_get_d(buff, args, fstring);
}
