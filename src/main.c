/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:05:02 by jerasmus          #+#    #+#             */
/*   Updated: 2017/06/12 17:24:24 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void 				ft_init(t_state *s)
{
	s->board = NULL;
	s->piece = NULL;
	s->fnl_bx = 0;
	s->fnl_by = 0;
	s->fnl_px = 0;
	s->fnl_py = 0;
	s->curm_x = 0;
	s->curm_y = 0;
	s->curb_x = 0;
	s->curb_y = 0;
}

void				ft_free(char ***str)
{
	int 			i;

	i = 0;
	while (*str[i])
	{
		free(*str[i]);
		i++;
	}
	free(*str);
}

void				ft_xoro(t_state *s)
{
	char 			*str;
	char 			**splitstr;

	get_next_line(0, &str);
	splitstr = ft_strsplit(str, ' ');
	if (ft_strcmp(splitstr[2], "p1") == 0)
	{
		s->xoro = 'o';
		s->enxoro = 'x';
	}
	else
	{
		s->xoro = 'x';
		s->enxoro = 'o';
	}
	free(str);
	//ft_free(&splitstr); // ERROR: Pointer being freed was not allocated
}

void				ft_get_board(t_state *s)
{
	char 			*str;
	char 			**splitstr;
	int 			i;

	i = 0;
	get_next_line(0, &str);
	if (str != NULL)
	{
		splitstr = ft_strsplit(str, ' ');
		s->fnl_by = ft_atoi(splitstr[1]);
		s->fnl_bx = ft_atoi(splitstr[2]);
		splitstr = (char **)ft_memalloc(sizeof(char *) * (s->fnl_by + 1));
		while (i < s->fnl_by)
		{
			splitstr[i] = (char *)ft_memalloc(sizeof(char) * (s->fnl_bx + 1));
			i++;
		}
		i = 0;
		while (get_next_line(0, &str))
		{
			splitstr = ft_strsplit(str, ' ');
			s->board[i] = splitstr[1];
			i++;
			if (i == s->fnl_by)
				break;
		}
	}
}

void				ft_get_piece(t_state *s)
{
	char 			*str;
	char 			**splitstr;
	int 			i;

	i = 0;
	get_next_line(0, &str);
	if (str != NULL)
	{
		splitstr = ft_strsplit(str, ' ');
		s->fnl_py = ft_atoi(splitstr[1]);
		s->fnl_px = ft_atoi(splitstr[2]);
		splitstr = (char **)ft_memalloc(sizeof(char *) * (s->fnl_py + 1));
		while (i < s->fnl_py)
		{
			splitstr[i] = (char *)ft_memalloc(sizeof(char) * (s->fnl_px + 1));
			i++;
		}
		i = 0;
		while (get_next_line(0, &str))
		{
			s->piece[i] = str;
			i++;
			if (i == s->fnl_py)
				break;
		}
	}
}

void 				ft_input(t_state *s)
{
	ft_xoro(s);
	ft_get_board(s);
	ft_get_piece(s);
	s->fnl_by--;
	s->fnl_bx--;
	s->fnl_py--;
	s->fnl_px--;
}


int					main()
{
	t_state			s;
	ft_init(&s);
	ft_input(&s);

	/*char			*str;
	FILE			*f = fopen("log.txt", "w");
	int				i;
	int				j;
	char			**arr;
	int				max;

	i = 0;
	max = 100;
	j = 0;
	while (get_next_line(0, &str) != 0 && j <= max)
	{
		if (i == 1)
		{
			arr = ft_strsplit(str, ' ');
			max = ft_atoi(arr[1]);
			j = -1;
		}
		j++;
		i++;
		fprintf(f, "%s\n", str);
	}
	get_next_line(0, &str);
	fprintf(f, "%s\n", str);
	arr = ft_strsplit(str, ' ');
	max = ft_atoi(arr[1]);
	i = 0;
	while (i <= max)
	{
		get_next_line(0, &str);
		fprintf(f, "%s\n", str);
		i++;
	}
	fclose(f);*/

	return (0);
}
