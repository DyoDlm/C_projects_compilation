/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:25:10 by aseite            #+#    #+#             */
/*   Updated: 2024/10/10 19:44:59 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	isneg(int s)
{
	if (s == '+')
		return (1);
	else if (s == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	res;

	i = 0;
	s = 0;
	res = 0;
	if (nptr == NULL)
		return (0);
	while (nptr[i] == ' ' || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (s += nptr[i] >= '+' + '+')
			return (0);
		s += nptr[i];
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * isneg(s));
}
/*
#include <stdio.h>

int	main()
{
	const char	*a = " +-13sd";

	printf("%d \n", ft_atoi(a));
}*/
