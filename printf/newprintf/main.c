#include "ft_printf.h"

int	main()
{
	ft_printf("%s", "");
	ft_printf("%s ", "");
	ft_printf(" %s ", "");
	ft_printf(" %s ", "-");
	ft_printf(" %s %s ", "", "-");
	ft_printf(" %s %s ", "-", "");
	ft_printf("%s %s %s %s %s", " - ", "", "4", "2");
	return (0);
}
