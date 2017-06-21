/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 22:28:50 by jerasmus          #+#    #+#             */
/*   Updated: 2017/06/20 22:29:11 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_en_which_sector(t_state *s)
{
	if (s->curb_y <= s->fnl_by / 2)
	{
		if (s->curb_x <= s->fnl_bx / 2)
			s->en_start_sector = 1;
		else
			s->en_start_sector = 2;
	}
	else
	{
		if (s->curb_x <= s->fnl_bx / 2)
			s->en_start_sector = 3;
		else
			s->en_start_sector = 4;
	}
}

void	ft_which_sector(t_state *s)
{
	if (s->curb_y <= s->fnl_by / 2)
	{
		if (s->curb_x <= s->fnl_bx / 2)
			s->start_sector = 1;
		else
			s->start_sector = 2;
	}
	else
	{
		if (s->curb_x <= s->fnl_bx / 2)
			s->start_sector = 3;
		else
			s->start_sector = 4;
	}
}

void	ft_en_start_sector(t_state *s)
{
	int		found;

	found = 0;
	s->curb_y = 0;
	while (!found && s->curb_y <= s->fnl_by)
	{
		s->curb_x = 0;
		while (!found && s->curb_x <= s->fnl_bx)
		{
			if (ft_tolower(s->board[s->curb_y][s->curb_x]) == s->enxoro)
			{
				found = 1;
				ft_en_which_sector(s);
			}
			s->curb_x++;
		}
		s->curb_y++;
	}
	s->curb_y = 0;
	s->curb_x = 0;
}

void	ft_start_sector(t_state *s)
{
	int		found;

	found = 0;
	s->curb_y = 0;
	while (!found && s->curb_y <= s->fnl_by)
	{
		s->curb_x = 0;
		while (!found && s->curb_x <= s->fnl_bx)
		{
			if (ft_tolower(s->board[s->curb_y][s->curb_x]) == s->xoro)
			{
				found = 1;
				ft_which_sector(s);
			}
			s->curb_x++;
		}
		s->curb_y++;
	}
	s->curb_y = 0;
	s->curb_x = 0;
}
