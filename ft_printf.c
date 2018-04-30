/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:00:35 by femaury           #+#    #+#             */
/*   Updated: 2018/04/30 17:04:11 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char * restrict format, ...)
{
	va_list	args;
	t_list	*head;
	int		i;
	int		j;

	i = 0;
	j = 0;
	head = NULL;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				if (!head)
					head = ft_lstnew(&format[i++], 1);
				else
					ft_lstadd(&head, ft_lstnew(&format[i++], 1));
			}
		}
		else
		{
			if (!head)
				head = ft_lstnew(&format[i], 1);
			else
				ft_lstadd(&head, ft_lstnew(&format[i], 1));
		}
		i++;
	}
	va_end(args);
	ft_lstrev(&head);
	ft_putlst(head);
	ft_lstdel(&head);
	return (i + j);
}

int		main(void)
{
	ft_printf("Je test %mon printf %%\n");
	return (0);
}
