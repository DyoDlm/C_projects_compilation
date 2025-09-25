#include "ft_printf.h"

void	put_minus(int **d, char *av, char t)
{
	int	i;

	i = 0;
	ft_putstr(av);
	while (i < d[3][1])
	{
		write(1, " ", 1);
		i++;
	}
}
