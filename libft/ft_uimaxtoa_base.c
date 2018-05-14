/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:09:39 by femaury           #+#    #+#             */
/*   Updated: 2018/05/14 11:59:28 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(int n, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (n * ft_power(n, power - 1));
}

char		*ft_uimaxtoa_base(uintmax_t n, int base)
{
	int		ilen;
	char	*str;

	if (base < 2 || base > 16)
		return (NULL);
	ilen = 1;
	while (n > (uintmax_t)(ft_power(base, ilen) - 1))
		ilen++;
	if (!(str = (char *)ft_memalloc(ilen + 1)))
		return (NULL);
	while (ilen--)
	{
		str[ilen] = (n % base) + (n % base > 9 ? '7' : '0');
		n /= base;
	}
	return (str);
}
