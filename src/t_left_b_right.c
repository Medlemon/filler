/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_left_b_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 22:38:25 by jerasmus          #+#    #+#             */
/*   Updated: 2017/06/20 22:38:30 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_longest(t_state *s)
{
	int		i;
	int		j;

	i = 0;
	s->longest = (size_t)s->fnl_px;
	while (s->piece[i])
	{
		j = 0;
		while (j < s->fnl_px)
		{
			if (s->piece[i][j] == '*')
			{
				if (j < (int)s->longest)
					s->longest = (size_t)j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_tl_wall(t_state *s)
{
	s->curb_y = 0;
	while (s->curb_y < s->fnl_by)
	{
		s->curb_x = 0;
		while (s->curb_x <= s->fnl_bx)
		{
			if (ft_isvalid(s) == 1 && s->played == 0)
			{
				ft_printoutput(s);
				s->played = 1;
			}
			s->curb_x++;
		}
		s->curb_y = s->curb_y + 1;
	}
}

void	ft_br_wall(t_state *s)
{
	s->curb_y = s->fnl_by;
	while (s->curb_y >= 0)
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
		s->curb_y--;
	}
}

void	ft_tl_br_wall(t_state *s)
{
	if (ft_check_top_wall(s) == 0 && ft_check_left_wall(s) == 0)
		ft_tl_wall(s);
	else
		ft_br_wall(s);
}
