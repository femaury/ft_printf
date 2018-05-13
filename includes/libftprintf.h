/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femaury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 12:01:47 by femaury           #+#    #+#             */
/*   Updated: 2018/05/13 17:47:26 by femaury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>

# define BUFF_SIZE 64
# define FLAGS fstr.flags
# define LFLAGS fstr.lflags
# define WIDTH fstr.width
# define PREC fstr.prec
# define TYPE fstr.type

typedef struct	s_format
{
	unsigned int	flags: 5;
	unsigned int	lflags: 6;
	unsigned int	width;
	unsigned int	hasprec: 1;
	unsigned int	prec;
	unsigned char	type;
}				t_format;

typedef struct	s_buffer
{
	char			str[BUFF_SIZE];
	unsigned int	len;
	unsigned int	pos;
}				t_buffer;

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

int				ft_printf(const char * restrict format, ...);
void			ft_parsing(char *format, t_buffer *buff, va_list args, int *pos);
void			ft_get_arg(t_buffer *buff, va_list args, t_format fstring);
void			ft_get_str(t_buffer *buff, va_list args, t_format fstring);
void			ft_get_int(t_buffer *buff, va_list args, t_format fstring,
		int base);
void			ft_fill_buffer(t_buffer *buff, char *str, size_t len);
void			ft_pad_buffer(t_buffer *buff, char pad, size_t len);

size_t			ft_strlen(const char *s);
void			ft_strdel(char **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_putstr(char const *s);
void			ft_strnclr(char *s, size_t len);
void			ft_setlowcase(char *s);
char			*ft_strnew(size_t size, unsigned char c);
char			*ft_strnjoin(char const *s1, char const *s2, size_t len);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_itoa_base(int n, int base);
char			*ft_uitoa_base(unsigned int n, int base);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_islower(int c);

#endif
