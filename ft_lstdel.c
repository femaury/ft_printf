/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:21:49 by femaury           #+#    #+#             */
/*   Updated: 2018/04/30 17:11:41 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_lstdel(t_list **alst)
{
	t_list	*next;

	while (*alst)
	{
		next = (*alst)->next;
		ft_memdel(&(*alst)->content);
		ft_memdel((void **)alst);
		*alst = next;
	}
}
