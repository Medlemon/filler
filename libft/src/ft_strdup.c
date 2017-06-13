/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 12:10:44 by jerasmus          #+#    #+#             */
/*   Updated: 2016/12/05 08:37:18 by jerasmus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)ft_memalloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	ft_strcpy(s2, s1);
	if (ft_strlen(s2) == 0)
		return (NULL);
	return (s2);
}
