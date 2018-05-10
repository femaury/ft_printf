/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:22:40 by femaury           #+#    #+#             */
/*   Updated: 2018/05/10 14:47:16 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{
	int res;

//	printf("Count: %d\n", ft_printf("Je test mon printf %s big test %s\n", "avec un", "de malade"));
//	ft_printf("Je test mon printf v2\n");
//	ft_printf("%%\n");
//	ft_printf("Je test mon printf avec un char: %c", 'c');
//	ft_printf("\n");
	res = ft_printf("%s\n", "test");
	printf("%d\n", res);
	res = printf("%s\n", "test");
	printf("%d\n", res);
	return (0);
}
