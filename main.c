/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:22:40 by femaury           #+#    #+#             */
/*   Updated: 2018/05/12 21:27:01 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>

int		main(void)
{
	int res;

//	printf("Count: %d\n", ft_printf("Je test mon printf %s big test %s\n", "avec un", "de malade"));
//	ft_printf("Je test %% mon printf v2\n");
//	ft_printf("%%\n");
//	ft_printf("Je test mon printf avec un char: %c", 'c');
//	ft_printf("\n");
//	res = ft_printf("le big test%2c%c avec %.3d %-6set un %% MAKE IT %s", '4', '2', 2, "types", "RAIN\n");
//	printf("%d\n", res);
//	res = printf("le big test%2c%c avec %.3d %-6set un %% MAKE IT %s", '4', '2', 2, "types", "RAIN\n");
//	printf("%d\n", res);
	res = ft_printf("%#05x\n", 10);
	printf("%d\n", res);
	res = printf("%#05x\n", 10);
	printf("%d\n", res);
	return (0);
}
