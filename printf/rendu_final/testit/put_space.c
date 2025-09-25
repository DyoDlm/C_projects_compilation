#include "ft_printf.h"

void	put_space(int *d, char *av, char t)
{
	int	i;

	printf("into space");
	i = 0;
	while (i++ < d[1])
		ft_putchar(' ');
	if ((t == 'd' || t == 'i') && av[0] == '-')
	{
		ft_putchar('-');
		i = 1;
	}
	else
		i = 0;
	if (t == 'c')
	{
		write(1, &av[i], 1);
		return ;
	}
	while (av[i])
		write(1, &av[i++], 1);
}
