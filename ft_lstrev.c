/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 15:58:21 by femaury           #+#    #+#             */
/*   Updated: 2018/04/30 19:10:16 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_lstrev(t_list **alst)
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;
	int		size;

	prev = NULL;
	curr = *alst;
	size = 0;
	while (curr)
	{
		size += (int)curr->content_size;
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*alst = prev;
	return (size);
}
