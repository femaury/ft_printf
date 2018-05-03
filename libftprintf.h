/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:01:47 by femaury           #+#    #+#             */
/*   Updated: 2018/05/03 18:40:52 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct	s_format
{
	unsigned int	flags: 5;
	unsigned int	lflags: 6;
	unsigned int	width;
	unsigned int	precision;
	unsigned char	type;
}				t_format;

typedef enum	e_flags
{
	F_SPACE = 1 << 0,
	F_HASH = 1 << 1,
	F_PLUS = 1 << 2,
	F_MINUS = 1 << 3,
	F_ZERO = 1 << 4,
}				t_flags;

typedef enum	e_lengthflags
{
	LF_CTOI = 1 << 0,
	LF_SHTOI = 1 << 1,
	LF_LONG = 1 << 2,
	LF_LLONG = 1 << 3,
	LF_IMAX = 1 << 4,
	LF_SIZE = 1 << 5,
}				t_lflags;

size_t			ft_strlen(const char *s);
void			ft_strdel(char **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_putstr(char const *s);
char			*ft_strnew(size_t size);
char			*ft_strnjoin(char const *s1, char const *s2, size_t len);

#endif
