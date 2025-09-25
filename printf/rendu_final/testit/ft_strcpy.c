/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:34:09 by aseite            #+#    #+#             */
/*   Updated: 2024/10/10 20:00:25 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy(char *s)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = malloc((ft_strlen(s) + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
#include <stdio.h>

int	main()
{
	const char	*s1 = "efg";
	const char	*s2 = "efg";
	size_t		n = 4;
	int		diff;
	
	diff = ft_strncmp(s1, s2, n);
	printf("%d \n", diff);
	return (0);
}*/
