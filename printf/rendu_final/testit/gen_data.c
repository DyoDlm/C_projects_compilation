#include "ft_printf.h"

static int	fi(char c)
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

static int	pos_flag(char *s)
{
	int	nof;
	int	f;
	int	q;

	nof = 0;
	f = 0;
	q = 0;
	while (s[nof] && f < 2)
	{
		if (fi(s[nof]) < 0 && fi(s[nof]) != -7)
		{
			f++;
			q++;
		}
		else if (fi(s[nof]) == 9 || fi(s[nof]) == 0 || fi(s[nof]) > 0)
			f++;
		while (q == 1 && (fi(s[nof + 1]) == -7 || fi(s[nof + 1]) == -2))
			nof++;
		nof++;
	}
	if (q == 1)
		return (nof);
	else
		return (nof - 1);
}

static int	is_ko(int *d)
{
	int	i;
	int	flag;
	int	sf;

	i = 0;
	flag = 0;
	sf = 0;
	if (d[i] == '\0' || d[i] != 9 || d[i + 1] == 0 || d[i + 1] == -7)
		return (2);
	if (d[1] < 0 && d[1] > -5)
		sf = d[1];
	if (sf == -2)
		flag++;
	while ((d[i] < 1 || d[i] == 9) && flag < 2 && d[i + 1] != 9)
	{
		if ((d[i] == -7 || d[i] == -2)  && sf > -5 && sf < 0)
			i++;
		else if (d[i] < 1 && d[i] > -7 && d[i] != 9)
		{
			flag++;
			i++;
		}
		else
			i++;
	}
	return (flag);
}

int	**dx(char *segment)
{
	int	i;
	int	**data;

	i = 0;
	data = malloc(4 * sizeof(int *));
	if (!data)
		return (NULL);
	data[0] = malloc(2 * sizeof(int));
	if (free_data0(data[0], data) == -1)
		return (NULL);
	data[0][0] = pos_flag(segment);
	data[0][1] = segment[pos_flag(segment)];
	data[1] = malloc((1 + ft_strlen(segment)) * sizeof(int));
	if (free_data1(data[1], data[0], data) == -1)
		return (NULL);
	while (segment[i++])
		data[1][i - 1] = fi(segment[i - 1]);
	data[2] = malloc(sizeof(int));
	if (free_data2(data[2], data[1], data[0], data) == -1)
		return (NULL);
	data[2][0] = is_ko(data[1]);
	data[3] = malloc(5 * sizeof(int));
	if (free_data3(data[3], data[2], data[1], data[0], data) == -1)
		return (NULL);
	return (data);
}
