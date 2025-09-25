#include "ft_printf.h"

void	ft_print_pointer(void *ptr, t_flags flags)
{
	unsigned long long	address;
	char			*str;
	int			len;

	address = (unsigned long long)ptr;
	str = ft_utoa_base(address, 16);
	if (!str)
		return ;
	len = ft_strlen(str) + 2;
	if (flags.minus)
		ft_putstr("0x");
	ft_put_padding(' ', flags.width - len);
	if (!flags.minus)
		ft_putstr("0x");
	ft_putstr(str);
	free(str);
}
