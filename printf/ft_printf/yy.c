#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	i = 12345;
	int	k = -12345;
	unsigned int	u = 7890;
	char		*s = "salutcava";
	char		c = 'z';

	ft_printf(" test %s", s);
	return (0);
}
