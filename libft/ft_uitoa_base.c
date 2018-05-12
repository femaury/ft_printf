/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:09:39 by femaury           #+#    #+#             */
/*   Updated: 2018/05/12 20:03:40 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_power(long n, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (n * ft_power(n, power - 1));
}

char		*ft_uitoa_base(unsigned int n, int base)
{
	int		ilen;
	char	*str;
	long	nb;

	nb = (long)n;
	if (base < 2 || base > 16)
		return (NULL);
	ilen = 1;
	while (nb > ft_power((long)base, ilen) - 1)
		ilen++;
	if (!(str = (char *)ft_memalloc(ilen + 1)))
		return (NULL);
	while (ilen--)
	{
		str[ilen] = (nb % base) + (nb % base > 9 ? '7' : '0');
		nb /= base;
	}
	return (str);
}
