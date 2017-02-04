/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:39:40 by nboute            #+#    #+#             */
/*   Updated: 2017/02/04 21:49:28 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define MAX_BUFFER 1024

/*
**	flg_1: '-'
**	flg_2: '+' || ' '
**	flg_3: '#'
**	flg_4: '0' || ' '
*/

typedef struct	s_info
{
	int			flg_1;
	char		*flg_2;
	int			flg_3;
	char		flg_4;
	size_t		width;
	int			pre;
	char		len[2];
	char		c;
	size_t		slen;
	short		err;
}				t_info;

char			*ft_pf_spe_di(t_info *data, va_list l);
char			*ft_pf_spe_oux(t_info *data, va_list l);
char			*ft_pf_spe_c(t_info *data, va_list l);
char			*ft_pf_spe_p(t_info *data, va_list l);
char			*ft_pf_spe_s(t_info *data, va_list l);

typedef struct	s_spe
{
	char		c;
	char		*(*fct)(struct s_info *list, va_list l);
}				t_spe;

char			*ft_wide(wchar_t *str, t_info *data);
char			*ft_wide_p2(unsigned int c);
char			*ft_wide_p3(unsigned int c);
char			*ft_cpynchar(char *str, size_t n, int c);
char			*ft_getnull(void);
char			*ft_width(char *str, t_info *data);
char			*ft_flags(char *str, t_info *data);
char			*ft_flags_p2(char *str, t_info *data, size_t blen);
char			*ft_pre(char *str, t_info *data);
char			*ft_pre_str(char *str, t_info *data);
char			*ft_pre_num(char *str, t_info *data, size_t n, size_t base);
int				ft_printf(const char *frt, ...);
t_info			*ft_getpflen(const char *str, t_info *data, size_t *i);
t_info			*ft_getpflen_p2(const char *str, t_info *data, size_t *i);
char			*ft_getformatf(const char *str, size_t *i, t_info *data,
		va_list a);

char			*ft_getpwls(const char *str, t_info *data, size_t *i,
		va_list a);
int				ft_spe_exists(char c);
void			ft_write_buffer(const char *str, size_t n);
int				ft_writef(const char *str, size_t *i, va_list a);
char			*ft_getformatf(const char *str, size_t *i, t_info *data,
		va_list a);

#endif
