/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:01:47 by femaury           #+#    #+#             */
/*   Updated: 2018/04/30 19:04:00 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
int				ft_lstrev(t_list **alst);
void			ft_putlst(t_list *lst);
void			ft_lstdel(t_list **alst);
void			ft_memdel(void **ap);

#endif
