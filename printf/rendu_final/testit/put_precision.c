#include "ft_printf.h"

static void	compact(int n, char *s)
{
	int	i;

	i = 0;
	while (i < n)
		write(1, &s[i++], 1);
}

static void	stretch(int n, char *s)
{
	int	i;
	int	len;

	i = 0;
	len = n - ft_strlen(s);
	while (i < len)
	{
		ft_putchar('0');
		i++;
	}
	ft_putstr(s);
}

void	put_precision(int *d, char *av, char t)
{
	int	nb;

	nb = d[1];
	if (t == 'c')
		ft_putchar(av[0]);
	else if (nb < ft_strlen(av))
	{
		if (t == 's')
			compact(nb, av);
		else
			ft_putstr(av);
	}
	else
	{
		if (t == 's')
			ft_putstr(av);
		else
			stretch(nb, av);
	}	
}
