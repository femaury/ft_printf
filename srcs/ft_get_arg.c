/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:46:54 by femaury           #+#    #+#             */
/*   Updated: 2018/05/13 17:48:08 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_get_arg(t_buffer *buff, va_list args, t_format fstr)
{
	if (TYPE == 'c' || TYPE == 's')
		ft_get_str(buff, args, fstr);
	else if (TYPE == 'd' || TYPE == 'D' || TYPE == 'i')
		ft_get_int(buff, args, fstr, 10);
	else if (TYPE == 'u' || TYPE == 'U')
		ft_get_int(buff, args, fstr, 10);
	else if (TYPE == 'x' || TYPE == 'X')
		ft_get_int(buff, args, fstr, 16);
	else if (TYPE == 'o' || TYPE == 'O')
		ft_get_int(buff, args, fstr, 8);
	else if (TYPE == 'p')
		ft_get_int(buff, args, fstr, 16);
}
