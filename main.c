/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:22:40 by femaury           #+#    #+#             */
/*   Updated: 2018/05/14 14:07:41 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>
#include <locale.h>

int		main(void)
{
//	setlocale(LC_ALL, "");
	void	*p;
	void	*p2;
	int res;
	char str[10] = "0123456789";
	char c;

	c = '@';
	res = 4362;
	p = &res;
	p2 = &str;
	res = ft_printf("Je test mon%1.0sprintf %s big test %10.5s\n", "nonono", "avec un", "de malade");
	printf("%d\n", res);
	res = printf("Je test mon%1.0sprintf %s big test %10.5s\n", "nonono", "avec un", "de malade");
	printf("%d\n\n", res);
	fflush(NULL);
	res = ft_printf("Je test mo%-2cprintf avec un char: %c\n", 'n', c);
	printf("%d\n", res);
	res = printf("Je test mo%-2cprintf avec un char: %c\n", 'n', c);
	printf("%d\n\n", res);
	fflush(NULL);
	res = ft_printf("le big test%2c%c avec %.3d %-6set un %% MAKE IT %s", '4', '2', 2, "types", "RAIN\n");
	printf("%d\n", res);
	res = printf("le big test%2c%c avec %.3d %-6set un %% MAKE IT %s", '4', '2', 2, "types", "RAIN\n");
	printf("%d\n\n", res);
	fflush(NULL);
	res = ft_printf("%#10.5x\n", 45728);
	printf("%d\n", res);
	res = printf("%#10.5x\n", 45728);
	printf("%d\n\n", res);
	fflush(NULL);
	res = ft_printf("%p %p\n", p, p2);
	printf("%d\n", res);
	res = printf("%p %p\n", p, p2);
	printf("%d\n\n", res);
	fflush(NULL);
//	c = 0xe1;
//	write(1, &c, 1);
//	c = 0x88;
//	write(1, &c, 1);
//	c = 0xb4;
//	write(1, &c, 1);
//	c = 0x0a;
//	write(1, &c, 1);	
	return (0);
}
