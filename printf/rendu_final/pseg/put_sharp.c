#include "ft_printf.h"

void	put_sharp(int **d, char *av, char t)
{
	if (t == 'x' || t == 'X')
		ft_putstr("0x");
	ft_putstr(av);
}
