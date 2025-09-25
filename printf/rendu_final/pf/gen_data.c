//#include "libprintft.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	printf("voici la longueur :%d\n", i);
	return (i);
}

int	is_flag(char c)
{
	if (c == 'c' || c == 's')
		return (1);
	else if (c == 'p')
		return (2);
	else if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (3);
	else if (c == '%')
		return (9);
	else if (c <= '9' && c >= '1')
		return (-7);
	else if (c == ' ')
		return (-1);
	else if (c == '0')
		return (-2);
	else if (c == '.')
		return (-3);
	else if (c == '-')
		return (-4);
	else if (c == '+')
		return (-5);
	else if (c == '#')
		return (-6);
	else
		return (0);
}

int	pos_flag(char *s)
{
	int	nof;
	int	f;

	nof = 0;
	f = 0;
	while (s[nof] && f < 2)
	{
		if (is_flag(s[nof]) < 0)
		{
			f++;
			nof++;
		}
		else
			nof++;
	}
	return (nof - 1);
}

int	is_ko(int *d)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!d)
		return (-1);
	while (d[i] != 9 && d[i] != '\0')
		i++;
	if (d[i] == '\0')
		return (2);
	i = 0;
	while ((d[i] < 1 || d[i] == 9) && flag < 2 && d[i + 1] != 9)
	{
		if (d[i - 1] > -5 && d[i - 1] < 0 && d[i] == -7)
			i++;
		else if (d[i] < 1 && d[i] != -9)
		{
			flag++;
			i++;
		}
		else
			i++;
	}
	printf("voici le ko :%d\n", flag);
	return (flag);
}

int	**dx(char *segment)	//seg_the_seg
{
	int	i;
	int	**data;

	i = 0;
	data = malloc(4 * sizeof(int *));
	if (!data)
		return (NULL);
	data[0] = malloc(2 * sizeof(int));
	if (!data[0])
		return (NULL);
	data[0][0] = pos_flag(segment);
	data[0][1] = segment[pos_flag(segment)];
	data[1] = malloc(ft_strlen(segment) * sizeof(int));
	if (!data[1])
		return (NULL);
	while (segment[i++])
		data[1][i - 1] = is_flag(segment[i - 1]);
	data[2] = malloc(sizeof(int));
	if (!data[2])
		return (NULL);
	data[2][0] = is_ko(data[1]);
	data[3] = malloc(sizeof(int));
	if (!data[3])
		return (NULL);
	return (data);
}
/*
int main()
{
    // Initialisation d'un segment pour tester
    char *segment = "%01sadca";
    int **data = dx(segment);
    if (!data)
    {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }
    // Libération de la mémoire allouée
    free(data[0]);
    free(data[1]);
    free(data[2]);
    free(data[3]);
    free(data);

    return 0;
}*/
