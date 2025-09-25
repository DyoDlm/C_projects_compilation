#include <stdlib.h>

int	what_spe(int **data)
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

int	pos_spe(int **data)
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

int	sum_digits(char *s, int **d)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (d[1][i])
	{
		if (d[1][i] >= 0 || d[1][i] < -4 || d[1][i] == -7 )
			i++;
		else
			return (res);
	}
	i = 0;
	while (d[1][i])
	{
		if (d[1][i] == -7)
			res = res + d[1][i];
		else
			i++;
	}
	return (res);
}

int	**flag_rules(char *seg, int **data)
{
	data[3] = malloc(5 * sizeof(int *));
	if (!data[3])
		return (NULL);
	data[3][0] = data[2][0];// Flags actifs ou non (if 0 is not)
	data[3][1] = sum_digits(seg, data);// Somme de nombre 
	data[3][2] = what_spe(data);// Special Flag (if 0 is not)
	data[3][3] = pos_spe(data);// La position de FS
	data[3][4] = data[0][1];// Le Type normal (if 0 is not)
	data[3][5] = data[0][0];// La position (if 0 is not)
	return (data);
}

int	main()
{
	
