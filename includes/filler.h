/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:12:27 by jerasmus          #+#    #+#             */
/*   Updated: 2017/06/12 11:18:20 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct      s_state
{
    char            **board;
    char            **piece;
	char            xoro;
	char            enxoro;
    int             fnl_bx;
    int             fnl_by;
    int             fnl_px;
    int             fnl_py;
    int             curm_x;
    int             curm_y;
    int             curb_x;
    int             curb_y;
}                   t_state;

#endif
