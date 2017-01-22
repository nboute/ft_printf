/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spetab.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboute <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:31:47 by nboute            #+#    #+#             */
/*   Updated: 2017/01/13 12:50:12 by nboute           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPETAB_H
# define FT_SPETAB_H

# include "ft_printf.h"

t_spe	g_spetab[] =
{
	{'d', &ft_pf_spe_di},
	{'i', &ft_pf_spe_di},
	{'o', &ft_pf_spe_oux},
	{'u', &ft_pf_spe_oux},
	{'x', &ft_pf_spe_oux},
	{'c', &ft_pf_spe_c},
	{'p', &ft_pf_spe_p},
	{'%', &ft_pf_spe_p},
	{'s', &ft_pf_spe_s},
	{'\0', NULL}
};

#endif
