#include "ft_printf.h"
#include <limits.h>

int	main()
{
	ft_printf(" %p ", (void *)-1);
	ft_printf(" %p ", (void *)1);
	ft_printf(" %p ", (void *)15);
	ft_printf(" %p ", (void *)16);
	ft_printf(" %p ", (void *)17);
	ft_printf(" %p %p ", (void *)LONG_MIN, (void*)LONG_MAX);
	ft_printf(" %p %p ", (void *)INT_MIN, (void *)INT_MAX);
	ft_printf(" %p %p ", (void *)ULONG_MAX, (void *)(-ULONG_MAX));
	ft_printf(" %p %p ", (void *)0, (void *)0);
	return (0);
}
