/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:20:21 by femaury           #+#    #+#             */
/*   Updated: 2018/05/14 19:03:24 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_set_extra(char *nb, t_format fstr)
{
	int		extra;

	if ((FLAGS & (F_PLUS | F_SPACE | F_HASH)) || nb[0] == '-')
	{
		extra = 1;
		if ((FLAGS & F_HASH) && nb[0] != '0')
			if (!(TYPE == 'o') && !(TYPE == 'O'))
				extra = 2;
		return (PREC > WIDTH ? (0) : (extra));
	}
	return (0);
}

static void	ft_prepend(t_buffer *buff, char *nb, size_t len, t_format fstr)
{
	if ((FLAGS & (F_PLUS | F_SPACE | F_HASH)) || nb[0] == '-')
	{
		if (nb[0] == '-')
			ft_pad_buffer(buff, '-', 1, 0);
		else if ((FLAGS & F_HASH) && nb[0] != '0')
		{
			if (TYPE == 'o' || TYPE == 'O')
				ft_pad_buffer(buff, '0', 1, 0);
			else
			{
				ft_fill_buffer(buff, (TYPE == 'X' ? "0X" : "0x"), 2);
				if (TYPE == 'p')
					ft_fill_buffer(buff, "7fffffffffff", 12 - len);
			}
		}
		else
			ft_pad_buffer(buff, ((FLAGS & F_PLUS) ? '+' : ' '), 1, 0);
	}
}

static void	ft_extend2(t_buffer *buff, char *nb, size_t len, t_format fstr)
{
	int		extra;

	extra = ft_set_extra(nb, fstr);
	if ((FLAGS & F_ZERO) || PREC)
	{
		if (PREC && PREC < WIDTH - extra)
			ft_pad_buffer(buff, ' ', WIDTH - PREC - extra, 4);
		ft_prepend(buff, nb, len, fstr);
		ft_pad_buffer(buff, ((FLAGS & F_ZERO) || PREC > len ? '0' : ' '),
				(PREC > WIDTH - extra ? PREC : WIDTH - PREC) - len -
				(nb[0] == '-' || (FLAGS & F_ZERO) ? 1 : 0), 3);
		ft_fill_buffer(buff, nb + (nb[0] == '-' ? 1 : 0), len);
	}
	else
	{
		ft_pad_buffer(buff, ' ', WIDTH - len - extra, 2);
		ft_prepend(buff, nb, len, fstr);
		ft_fill_buffer(buff, nb + (nb[0] == '-' ? 1 : 0), len);
	}
}

static void	ft_extend(t_buffer *buff, char *nb, size_t len, t_format fstr)
{
	int		extra;

	len -= (nb[0] == '-' ? 1 : 0);
	extra = ft_set_extra(nb, fstr);
	if (WIDTH > len + extra)
	{
		if (FLAGS & F_MINUS)
		{
			ft_prepend(buff, nb, len, fstr);
			if (PREC > len && PREC < WIDTH)
				ft_pad_buffer(buff, '0', PREC - len, 5);
			ft_fill_buffer(buff, nb + (nb[0] == '-' ? 1 : 0), len);
			ft_pad_buffer(buff, ' ', WIDTH - extra - (PREC < len ? PREC : len), 1);
		}
		else
			ft_extend2(buff, nb, len, fstr);
	}
	else
	{
		ft_prepend(buff, nb, len, fstr);
		ft_fill_buffer(buff, nb + (nb[0] == '-' ? 1 : 0), len);
	}
}

void		ft_get_int(t_buffer *buff, char *nb, t_format fstr)
{
	if (TYPE == 'p')
	{
		FLAGS |= F_HASH;
		ft_setlowcase(nb);
	}
	else if (TYPE == 'x')
		ft_setlowcase(nb);
	WIDTH = (PREC > WIDTH ? PREC : WIDTH);
	ft_extend(buff, nb, ft_strlen(nb), fstr);
	ft_strdel(&nb);
}
