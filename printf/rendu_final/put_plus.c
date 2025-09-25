#include "ft_printf.h"

void	put_plus(int **d, char *av, char t)
{
	if (d[3][4] == t)
	{
		if (t == 'p' || t == 'i' || t == 'd')
			ft_putchar('+');
		ft_putstr(av);

	}
	else
		ft_putstr("Plus problem");
}
