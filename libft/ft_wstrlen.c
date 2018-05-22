/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 22:06:22 by femaury           #+#    #+#             */
/*   Updated: 2018/05/22 12:35:15 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(wchar_t *ws, int chars)
{
	int		loops;
	size_t	len;

	len = 0;
	loops = 0;
	if (chars <= 0)
	{
		while (*ws != L'\0')
		{
			len += ft_wcharlen(*ws);
			ws++;
		}
		return (len);
	}
	while (*ws != L'\0' && loops < chars)
	{
		len += ft_wcharlen(*ws);
		ws++;
		loops++;
	}
	return (len);
}
