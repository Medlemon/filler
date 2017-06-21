/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_right_b_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 22:38:47 by jerasmus          #+#    #+#             */
/*   Updated: 2017/06/20 22:38:53 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_tr_wall(t_state *s)
{
	s->curb_y = 0;
	while (s->curb_y < s->fnl_by)
	{
		s->curb_x = s->fnl_bx;
		while (s->curb_x >= 0)
		{
			if (ft_isvalid(s) == 1 && s->played == 0)
			{
				ft_printoutput(s);
				s->played = 1;
			}
			s->curb_x--;
		}
		s->curb_y++;
	}
}

void	ft_bl_wall(t_state *s)
{
	s->curb_y = s->fnl_by;
	while (s->curb_y >= 0)
	{
		s->curb_x = 0;
		while (s->curb_x < s->fnl_bx - s->fnl_px)
		{
			if (ft_isvalid(s) == 1 && s->played == 0)
			{
				ft_printoutput(s);
				s->played = 1;
			}
			s->curb_x++;
		}
		s->curb_y--;
	}
}

void	ft_tr_bl_wall(t_state *s)
{
	if (ft_check_top_wall(s) == 0 && ft_check_right_wall(s) == 0)
		ft_tr_wall(s);
	else
		ft_bl_wall(s);
}
