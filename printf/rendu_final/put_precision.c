#include "ft_printf.h"

void	put_precision(int **d, char *av, char t)
{
	int	i;

	i = 0;
	if (t == 'c')
		ft_putchar(av[0]);
	else if (d[3][1] < ft_strlen(av) && t == 's')
	{
		while (i < d[3][1])
			write(1, &av[i++], 1);
	}
	else if (d[3][1] > ft_strlen(av) && t != 's')
	{
		if ((t == 'd' || t == 'i') && av[0] == '-')
			ft_putchar('-');
		while (i++ < (d[3][1] - ft_strlen(av) + 1))
			ft_putchar('0');
		if (t == 'd' || t == 'i')
			i = 1;
		else
			i = 0;
		while (av[i])
			ft_putchar(av[i]);
	}
	else
		ft_putstr("Precision problem");
}
