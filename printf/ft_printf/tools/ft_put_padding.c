#include "ft_printf.h"

void	ft_put_padding(char c, int n)
{
	while (n-- > 0)
		ft_putchar(c);
}
