#include "ft_printf.h"

void	put_zero(int **d, char *av, char t)
{
	int	i;

	i = 0;
	if (t == 'p')
		ft_putstr("pointer zero not defined");
	else if (t == 'c' || t == 's')
	{
		while (i++ < ((d[3][1] + 1) - ft_strlen(av)))
			ft_putchar(' ');
		if (t == 'c')
			ft_putchar(av[0]);
		else
			ft_putstr(av);
	}
	else if ((t == 'i' || t == 'd') && av[0] == '-')
	{
		ft_putchar('-');
		i = 1;
	}
	if (t != 'c' && t != 's' && t != 'p')
	{
		while (i++ < ((d[3][1] + 1) - ft_strlen(av)))
			ft_putchar('0');
		while (av[i])
			write(1, &av[i++], 1);
	}	
}
