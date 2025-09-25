#include "ft_printf.h"

void	ft_putnstr(char *str, int n)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] && i < n)
		write(1, &str[i++], 1);
}

