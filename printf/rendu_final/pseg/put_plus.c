#include "ft_printf.h"

void	put_plus(int *dd, char *av, char t)
{
	if (t == 'p' || t = 'i' || t = 'd')
		ft_putchar("+");
	ft_putstr(av);
}
