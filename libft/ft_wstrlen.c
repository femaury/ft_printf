/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 22:06:22 by femaury           #+#    #+#             */
/*   Updated: 2018/05/21 22:15:15 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(wchar_t *ws)
{
	size_t len;

	len = 0;
	while (*ws != L'\0')
	{
		len += ft_wcharlen(*ws);
		ws++;
	}
	return (len);
}
