//#include "libprintft.h"
#include <stdlib.h>

static int	count_mod(const char *s)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	while (s[i])
	{
		if (s[i] == '%')
			ct++;
		i++;
	}
	return (ct);
}

static int	getlen(char *seg, int f)
{
	int	i;
	int	nlen;

	i = 1;
	nlen = 0;
	while (seg[i + nlen] && f > 0)
	{
		if (seg[i + nlen] == '%')
			f--;
		if (f == 1)
			nlen++;
		else
			i++;
	}
	return (nlen);
}

char	**ss(char *seg)
{
	int	i;
	int	j;
	char	**d;
	int	f;
	int	k;

	i = 0;
	j = 0;
	d = malloc((2 + count_mod(seg)) * sizeof(char *));
	while (seg[i])
	{
		k = f;
		d[j] = malloc((1 + getlen(seg, j)) * sizeof(char)); 
		while (seg[i] && f < 1)
		{
			if (seg[i] && seg[i + 1] == '%')
				f++;
			d[j][k++] = seg[i++];
		}
		d[j][k] = '\0';
		f = 0;
		j++;
	}
	d[j] = NULL;
	return (d);
}
/*
#include <stdio.h>

int	main()
{
	char	*s = "%#s oo%+s oo";
	char	**i;
	int	k;

	i = ss(s);
	k = 0;
	if (i == NULL)
	{
		printf("Memory allocation failed!\n");
        	return (1);
    	}
	while (i[k] != NULL)
	{
		printf("%s\n", i[k]);
		free(i[k]);
		k++;
	}
	free(i);
	return (0);
}*/
