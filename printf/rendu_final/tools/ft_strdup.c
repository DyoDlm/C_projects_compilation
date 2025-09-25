/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:32:30 by aseite            #+#    #+#             */
/*   Updated: 2024/10/10 19:56:03 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
//#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		len;

	len = 0;
	while (s[len])
		len++;
	dst = malloc((len + 1) * sizeof(char *));
	if (dst == NULL)
		return (0);
	len = 0;
	while (s[len])
	{
		dst[len] = s[len];
		len++;
	}
	dst[len] = '\0';
	return (dst);
}
/*
int	main()
{
	char	*s = "HEYY KOMRAD !";

	printf("%s \n", ft_strdup(s));
	return (0);
}*/
