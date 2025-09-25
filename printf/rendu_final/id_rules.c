#include <stdlib.h>
#include <stdio.h>

int	**dx(char *segment);

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
	while (d[i] && (d[i] == 9 || d[i] < 0))
		i++;
	while (s[d[i]] < '9' && s[d[i]] >= '0')
		res = res + (s[d[i++]] - '0');
	return (res);
}

int	**flag_rules(char *seg, int **data)
{
	data[3][0] = data[2][0];// Flags actifs ou non (if 0 is not)	
	printf("Flag actifs (1: oui | 0: non)%i\n", data[3][0]);
	if (data[3][0] == 1)
		data[3][1] = sum_digits(seg, data[1]);// Somme de nombre 
	else
		data[3][1] = 0;
	printf("Somme des nombres :%i\n", data[3][1]);
	data[3][2] = what_spe(data);// Special Flag (if 0 is not)
	printf("The special flag :%i\n", data[3][2]);
	data[3][3] = pos_spe(data);// La position de FS
	printf("Position of special flag :%i\n", data[3][3]);
	data[3][4] = data[0][1];// Le Type normal (if 0 is not)
	printf("The basic flag :%i\n", data[3][4]);
	data[3][5] = data[0][0];// La position (if 0 is not)
	printf("Pos of basic flag :%i\n", data[3][5]);
	return (data);
}
/*
int	main()
{
	char	*seg = "% 12sabc"; 
	int	**data = dx(seg);
	int	i = 0;

	if (!data)
	{
		printf("STOP");
		return (1);
	}
	printf("\n");
	printf("The segment :%s\n", seg);
	flag_rules(seg, data);
	while (i < 4)
		free(data[i++]);
	return (0);
}*/
