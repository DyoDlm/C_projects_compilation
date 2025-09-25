#include "libprintft.h"

static int	getlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	put_point_precision(int **d, char *seg, void *av)
{
	int	i;

	i = 1;
	if (d[1] > absolute_len(av) && (seg[d[3]] == 'c' || seg[d[3]] == 's'))
		ft_putstr_base(av, seg[d[3]]);
	else if (d[1] > absolute_len(av) && seg[d[3]] != 'p')
	{
		if (av < 0)
			write(1, "-", 1);
		while (i++ < (absolute_len(d, av) + 1))
			write(1, "0", 1);
		ft_putnbr_base(av, d);
		i = 1;
	}
	else if (d[1] < getlen(av) && (seg[d[3]] == 'c' || seg[d[3]] == 's'))
	{
		write(1, &av[0], 1);
		while (seg[d[3]] == 's' && i++ < (d[1] + 1))
			write(1, &av[i], 1);
	}
	else if (seg[d[3]] == 'p' && i == 1000)
		ft_putnbr_base(d, av);
	else
		write(1, "%", 1);
}
