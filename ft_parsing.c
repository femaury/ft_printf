/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 18:12:12 by femaury           #+#    #+#             */
/*   Updated: 2018/04/30 18:59:25 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#define EQU_FLAGS(c) c == '-' || c == '+' || c == ' ' || c == '0' || c == '#'
#define EQU_LENFLAGS(c) c == 'h' || c == 'l' || c == 'j' || c == 'z'
#define EQU_TYPES(c) c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||\
						c == 'i' || c == 'o' || c == 'O' || c == 'u' ||\
						c == 'U' || c == 'x' || c == 'X' || c == 'c' ||\
						c == 'C'

static void	ft_parsing_flags(const char * restrict format, int flags[5],
		int i[3])
{
	while (format[i[0]])
	{
		if (EQU_FLAGS(format[i[0]]))
		{
		}
		else if (EQU_LENFLAGS(format[i[0]]))
		{
		}
		else if (ft_isdigit(format[i[0]]))
		{
		}
		else if (format[i[0]] == '.')
		{
		}
		else if (EQU_TYPES(format[i[0]]))
		{
		}
		else
			exit (1);
		i++;
	}
}

void		ft_parsing(const char * restrict format, t_list *head, va_list args, int i[3])
{
	int		flags[5];

	ft_parsing_flags(format, flags, i);
}
