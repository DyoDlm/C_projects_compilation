#include "ft_printf.h"

void	put_sharp(int *d, char *av, char t)
{
	if (d[4] == t)
	{
		if (t == 'x' || t == 'X')
			ft_putstr("0x");
		ft_putstr(av);
	}
	else
		ft_putstr("Sharp problem");
}
