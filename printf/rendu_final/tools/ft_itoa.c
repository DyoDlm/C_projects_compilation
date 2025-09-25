/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseite <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:27:02 by aseite            #+#    #+#             */
/*   Updated: 2024/10/10 19:50:01 by aseite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	gl(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count + 1);
}

static void	helper(int nb, char *str, int *index)
{
	if (nb == 0)
		str[(*index)++] = '0';
	if (nb >= 10)
		helper(nb / 10, str, index);
	str[(*index)++] = (nb % 10) + '0';
}

char	*ft_itoa(int n)
{
	int		l;
	char	*c;
	int	index;

	l = gl(n);
	index = 0;
	c = malloc((l + 1) * sizeof(char));
	if (!c)
		return (NULL);
	if (n == -2147483648)
	{
		c[index++] = '-';
		c[index++] = '2';
		n += 2000000000;
		n = -n;
	}
	else if (n < 0)
	{
		c[index++] = '-';
		n = -n;
	}
	helper(n, c, &index);
	c[index] = '\0';
	return (c);
}
/*
#include <stdio.h>

int	main()
{
	int	n = -1224;

	printf("%s \n", ft_itoa(n));
	return (0);
}*/
