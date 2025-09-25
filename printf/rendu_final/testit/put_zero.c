#include "ft_printf.h"

static void	zero_char(int n, char *s)
{
	int	i;
	int	len;
	
	i = 0;
	len = n - ft_strlen(s);
	while (i < len)
	{
		ft_putchar(' ');
		i++;
	}
}

static void	zero_int(int n, char *s)
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
}

void	put_zero(int *d, char *av, char t)
{
	int	nb;

	nb = d[1];
	if (nb < ft_strlen(av))
		ft_putstr(av);
	else
	{
		if (t == 'p')
			ft_putstr("pointer zero not defined");
		else if (t == 'c' || t == 's')
			zero_char(nb, av);
		else if (t == 'i' || t == 'd' || t == 'x' || t == 'X')
			zero_int(nb, av);
		else if (t == 'u')
			zero_int(nb, av);
		if (t != 'p')
			ft_putstr(av);
	}
}
