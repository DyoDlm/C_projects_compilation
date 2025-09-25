#include "ft_printf.h"

void	ft_print_percent(t_flags flags)
{
	if (flags.minus)
		ft_putchar('%');
	ft_put_padding(flags.zero ? '0' : ' ', flags.width - 1);
	if (!flags.minus)
		ft_putchar('%');
}
