/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:46:54 by femaury           #+#    #+#             */
/*   Updated: 2018/05/14 15:24:55 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_set_base(t_format fstr)
{
	if (TYPE == 'x' || TYPE == 'X' || TYPE == 'p')
		return (16);
	if (TYPE == 'o' || TYPE == 'O')
		return (8);
	return (10);
}

static void	ft_get_unsigned(t_buffer *buff, va_list args, t_format fstr, int b)
{
	uintmax_t	nb;

	if (LFLAGS & (LF_LONG | LF_LLONG))
		nb = (uintmax_t)((LFLAGS & LF_LLONG) ? va_arg(args, unsigned long long)
				: va_arg(args, unsigned long));
	else if (LFLAGS & (LF_CTOI | LF_SHTOI))
		nb = (uintmax_t)((LFLAGS & LF_CTOI) ? (unsigned char)(va_arg(args, int))
				: (unsigned short)(va_arg(args, int)));
	else if (LFLAGS & (LF_IMAX | LF_SIZE))
		nb = (uintmax_t)((LFLAGS & LF_IMAX) ? va_arg(args, uintmax_t)
				: va_arg(args, size_t));
	else if (TYPE == 'p')
		nb = (uintmax_t)(va_arg(args, void *));
	else
		nb = (uintmax_t)(va_arg(args, unsigned int));
	ft_get_int(buff, ft_uimaxtoa_base(nb, b), fstr);
}

void		ft_get_arg(t_buffer *buff, va_list args, t_format fstr)
{
	int			base;
	intmax_t	nb;

	nb = 0;
	base = ft_set_base(fstr);
	if (TYPE == 'c' || TYPE == 's')
		ft_get_str(buff, args, fstr);
	else if (TYPE == 'i' || TYPE == 'd' || TYPE == 'D')
	{
		if (LFLAGS & (LF_LONG | LF_LLONG))
			nb = (intmax_t)((LFLAGS & LF_LLONG) ? va_arg(args, long long)
					: va_arg(args, long));
		else if (LFLAGS & (LF_CTOI | LF_SHTOI))
			nb = (intmax_t)((LFLAGS & LF_CTOI) ? (char)(va_arg(args, int))
					: (short)(va_arg(args, int)));
		else if (LFLAGS & (LF_IMAX | LF_SIZE))
			nb = (intmax_t)((LFLAGS & LF_IMAX) ? va_arg(args, intmax_t)
					: va_arg(args, size_t));
		else
			nb = (intmax_t)(va_arg(args, int));
		ft_get_int(buff, ft_imaxtoa_base(nb, 10), fstr);
	}
	else if (TYPE == 'u' || TYPE == 'U' || TYPE == 'o' || TYPE == 'O'
			|| TYPE == 'x' || TYPE == 'X' || TYPE == 'p')
		ft_get_unsigned(buff, args, fstr, base);
}
