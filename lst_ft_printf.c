/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:00:35 by femaury           #+#    #+#             */
/*   Updated: 2018/05/03 13:26:20 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_list	*ft_printflist(const char * restrict format, t_list *head,
		va_list args, int i[2])
{
	(void)args;
	while (format[i[0]])
	{
		if (format[i[0]] == '%' && format[i[0] + 1] == '%')
		{
			if (!head)
				head = ft_lstnew(&format[i[0]++], 1);
			else
				ft_lstadd(&head, ft_lstnew(&format[i[0]++], 1));
		}
//		else if (format[i[0]] == '%')
//		{
//			i[0]++;
//			ft_parsing(const char * restrict format, t_list *head,
//					va_list args, int i[2]);
//		}
		else
		{
			if (!head)
				head = ft_lstnew(&format[i[0]], 1);
			else
				ft_lstadd(&head, ft_lstnew(&format[i[0]], 1));
		}
		i[0]++;
	}
	return (head);
}

int			ft_printf(const char * restrict format, ...)
{
	va_list	args;
	t_clist	*head;
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	head = NULL;
	va_start(args, format);
	head = ft_printflist(format, head, args, i);
	va_end(args);
	i[2] = ft_lstrev(&head);
	ft_putlst(head);
	ft_lstdel(&head);
	return (i[2] - 1);
}

int		main(void)
{
	printf("%d\n", ft_printf("Je test mon printf %%\n");
	return (0);
}
