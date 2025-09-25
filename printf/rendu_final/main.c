#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int		i = 12345;
//	int		j = -1234;
//	unsigned int	u = 12345;
//	char		c = 'z';
//	char		*s = "HELLO !";

	printf("TESTER INTEGER\n");
	ft_printf("%i%i", i, i);
	return (0);
}
