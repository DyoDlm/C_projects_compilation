#include "ft_printf.h"

static int	getlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa_base(unsigned long long n, int base)
{
	const char	*b;
	int		len;
	char		*str;

	len = getlen(n);
	b = "0123456789abcdef";
	str = malloc((len + 1) * sizeof(char*));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--len] = b[n % base];
		n /= base;
	}
	return (str);
}
