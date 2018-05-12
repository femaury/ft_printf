/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:20:21 by femaury           #+#    #+#             */
/*   Updated: 2018/05/12 21:33:50 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_prepend(t_buffer *buff, char *nb, t_format fstring)
{
	int		extra;

	if ((FLAGS & (F_PLUS | F_SPACE | F_HASH)) || nb[0] == '-')
	{
		extra = 1;
		if (nb[0] == '-')
			ft_pad_buffer(buff, '-', 1);
		else if (FLAGS & F_HASH)
		{
			if (fstring.type == 'o' || fstring.type == 'O')
				ft_pad_buffer(buff, '0', 1);
			else
			{
				extra = 2;
				ft_fill_buffer(buff, (fstring.type == 'X' ? "0X" : "0x"), 2);
			}
		}
		else
			ft_pad_buffer(buff, ((FLAGS & F_PLUS) ? '+' : ' '), 1);
		return (extra);
	}
	return (0);
}

static void ft_extend(t_buffer *buff, char *nb, size_t len, t_format fstring)
{
	int		extra;

	if (FLAGS & F_MINUS)
	{
		extra = ft_prepend(buff, nb, fstring);
		ft_fill_buffer(buff, nb + (nb[0] == '-' ? 1 : 0), len);
		ft_pad_buffer(buff, ' ', fstring.width - len - extra);
	}
	else
	{
		extra = ft_prepend(buff, nb, fstring);
		ft_pad_buffer(buff, ((FLAGS & F_ZERO) || (fstring.prec > len)
					? '0' : ' '), fstring.width - len - extra);
		ft_fill_buffer(buff, nb + (nb[0] == '-' ? 1 : 0), len);
	}
}

void		ft_get_int(t_buffer *buff, va_list args, t_format fstring, int base)
{
	size_t	nblen;
	char	*nb;

	if (fstring.type == 'd' || fstring.type == 'i' || fstring.type == 'D')
		nb = ft_itoa_base(va_arg(args, int), base);
	else
	{
		nb = ft_uitoa_base(va_arg(args, unsigned int), base);
		if (ft_islower(fstring.type))
			ft_setlowcase(nb);
	}
	nblen = ft_strlen(nb);
	if (fstring.hasprec && !fstring.prec)
		return ;
	fstring.width = (fstring.prec > nblen ? fstring.prec : fstring.width);
	if (fstring.width > nblen)
		ft_extend(buff, nb, nblen, fstring);
	else
	{
		ft_prepend(buff, nb, fstring);
		ft_fill_buffer(buff, nb + (nb[0] == '-' ? 1 : 0), nblen);
	}
}
