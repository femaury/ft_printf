/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:45:30 by femaury           #+#    #+#             */
/*   Updated: 2018/05/14 16:05:44 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_fill_buffer(t_buffer *buff, char *str, size_t len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		if (buff->pos == BUFF_SIZE)
		{
			write(1, buff->str, BUFF_SIZE);
			ft_strnclr(buff->str, BUFF_SIZE);
			buff->len += buff->pos;
			buff->pos = 0;
		}
		buff->str[buff->pos++] = str[i++];
	}
}
