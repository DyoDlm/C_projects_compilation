//#include "ft_printf.h"

int	count_mod(const char *s)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	while (s[i])
	{
		if (s[i] == '%')
			ct++;
		i++;
	}
	return (ct);
}
