/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:39:40 by nboute            #+#    #+#             */
/*   Updated: 2016/12/02 14:40:38 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

enum conv
{
	h,
	hh,
	l,
	ll,
	j,
	z,
};


char	*ft_pf_spe_d(char*, void*, enum conv);
char	*ft_pf_spe_oux(char*, void*, enum conv);
char	*ft_pf_spe_c(char*, void*, enum conv);
char	*ft_pf_spe_p(char*, void*, enum conv);
char	*ft_pf_spe_s(char*, void*, enum conv);

typedef struct	s_spe
{
	char		c;
	char		*(*fct)(char*, void*, enum conv);
}
				t_spe;

t_spe	g_spetab[] =
{
	{'d', &ft_pf_spe_d},
	{'o', &ft_pf_spe_oux},
	{'u', &ft_pf_spe_oux},
	{'x', &ft_pf_spe_oux},
	{'c', &ft_pf_spe_c},
	{'p', &ft_pf_spe_p},
	{'s', &ft_pf_spe_s}
};

#endif
