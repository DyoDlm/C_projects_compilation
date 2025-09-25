#include "ft_printf.h"

static int	look_flags_ok(char **segments, int start)
{
	int	**data;

	data = dx(segments[start]);
	if (data[3][0] == 0)
	{
		ft_putstr(segments[start]);
		return (0);
	}
	return (1);
}

static int	ft_shoot(char **segs, char *av, char type, int start)
{
	int	**data;

	data = dx(segs[start]);
	if (data[3][2] == -1)
		put_space(data, av, type);
	else if (data[3][2] == -2)
		put_zero(data, av, type);
	else if (data[3][2] == -3)
		put_precision(data, av, type);
	else if (data[3][2] == -4)
		put_minus(data, av, type);
	else if (data[3][2] == -5)
		put_plus(data, av, type);
	else if (data[3][2] == -6)
		put_sharp(data, av, type);
	return (data[3][5]);
}

static void	put_final_string(int pos, char *str)
{
	int	i;

	i = 0;
	while (str[pos + i])
		write(1, &str[pos + i++], 1);
}

void	putseg(char **segs, char **av, char *av_t)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	j = 0;
	while (segs[i])
	{
		while (look_flags_ok(segs, i) == 0)
			i++;
		pos = ft_shoot(segs, av[j], av_t[j], i);
		put_final_string(pos, segs[i]);
		i++;
		j++;
	}
}
