#include "ft_printf.h"
#include <limits.h>

int	main()
{
	ft_printf(" %p %p ", 0, 0);
	ft_printf(" %d ", INT_MIN);
	ft_printf(" %d ", INT_MAX);
	ft_printf(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %i ", INT_MIN);
	ft_printf(" %i ", INT_MAX);
	 ft_printf(" %i %i %i %i %i %i %i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	return (0);
}
