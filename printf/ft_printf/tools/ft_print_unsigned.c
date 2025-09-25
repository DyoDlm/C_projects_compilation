#include "ft_printf.h"

void	ft_print_unsigned(unsigned int n, t_flags flags)
{
	char	*str;
	int	len;

	str = ft_utoa(n);
	if (!str)
		return ;
	len = ft_strlen(str);
	if (flags.minus)
		ft_putstr(str);
	ft_put_padding(' ', flags.width - len);
	if (!flags.minus)
		ft_putstr(str);
	free(str);
}
