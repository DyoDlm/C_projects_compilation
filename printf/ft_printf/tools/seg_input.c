#include "ft_printf.h"
#include <stdio.h>

static int      getlen(const char *seg, int f)
{
        int     i;
        int     nlen;

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

char	**seg_input(const char *seg)
{
	int	i;
	int	j;
	char	**d;
	int	f;
	int	k;

	i = 0;
	j = 0;
	f = 0;
	d = malloc((1 + count_mod(seg)) * sizeof(char *));
	if (!d)
		return (NULL);
	while (seg[i])
	{
		k = 0;
		d[j] = malloc((1 + getlen(seg, j)) * sizeof(char));
		if (!d[j])
			return (NULL);
		while (seg[i] && f < 1)
		{
			d[j][k++] = seg[i++];
			if (seg[i] == '%' && seg[i + 1] != '\0')
			f++;
		}
		d[j++][k] = '\0';
		f = 0;
		printf("segment in ss :%s\n", d[j]);
	}
	d[j] = NULL;
	printf("segment after null attribution :%s\n", d[j]);
	printf("%d\n", j);
	return (d);
}
