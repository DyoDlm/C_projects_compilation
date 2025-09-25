#include "ft_printf.h"

static int	what_spe(int **data)
{
	int	i;

	i = 0;
	while (data[1][i])
	{
		if (data[1][i] != -7 && data[1][i] < 0)
			return (data[1][i]);
		else
			i++;
	}
	return (0);
}

static int	pos_spe(int **data)
{
	int	i;

	i = 0;
	while (data[1][i])
	{
		if (data[1][i] != -7 && data[1][i] < 0)
			return (i);
		else
			i++;
	}
	return (0);
}

static int	sum_digits(char *s, int *d)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (d[i] && (d[i] == 9 || (d[i] < 0 && d[i] != -7)))
		i++;
	while (s[i] <= '9' && s[i] >= '0')
		res = (10 * res) + (s[i++] - '0');
	return (res);
}

int	**flag_rules(char *seg, int **data)
{
	data[3] = malloc(5 * sizeof(int *));
	if (!data)
		return (NULL);
	data[3][0] = data[2][0];
	if (data[3][0] == 1)
		data[3][1] = sum_digits(seg, data[1]); 
	else
		data[3][1] = 0;
	data[3][2] = what_spe(data);
	data[3][3] = pos_spe(data);
	data[3][4] = data[0][1];
	data[3][5] = data[0][0];
	if (data[3][2] == 0 && data[3][4] == 37)
                data[3][0] = 2;
	return (data);
}
