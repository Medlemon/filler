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

#include "filler.h"

int					main()
{
	char			*str;
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
	fclose(f);
	return (0);
}
