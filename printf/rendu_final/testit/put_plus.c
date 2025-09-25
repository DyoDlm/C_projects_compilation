#include "ft_printf.h"

void	put_plus(int *d, char *av, char t)
{
	if (d[4] == t)
	{
		if ((t == 'p' || t == 'i' || t == 'd') && av[0] != '-')
			ft_putchar('+');
		ft_putstr(av);
	}
	else
		ft_putstr("Plus problem");
}
