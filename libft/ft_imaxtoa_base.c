/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:09:39 by femaury           #+#    #+#             */
/*   Updated: 2018/05/14 13:29:02 by femaury          ###   ########.fr       */
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

char		*ft_imaxtoa_base(intmax_t n, int base)
{
	int			ilen;
	int			sign;
	char		*str;
	intmax_t	nb;

	if (base < 2 || base > 16)
		return (NULL);
	sign = 0;
	nb = (n < 0 ? -n : n);
	ilen = 1;
	if (n < 0)
		sign = 1;
	while (nb > (intmax_t)(ft_power(base, ilen) - 1))
		ilen++;
	if (!(str = (char *)ft_memalloc(ilen + sign + 1)))
		return (NULL);
	if (sign)
		str[0] = '-';
	while (ilen--)
	{
		str[ilen + sign] = (nb % base) + (nb % base > 9 ? '7' : '0');
		nb /= base;
	}
	return (str);
}
