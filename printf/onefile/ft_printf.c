#include "ft_printf.h"

static void	ft_putchar(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

static void	ft_putstr(const char *str, size_t *counter)
{
	if (str)
	{
		while (*str)
		{
			ft_putchar(*str, counter);
			str++;
		}
	}
	else
		ft_putstr("(null)", counter);
}

static void	ft_pnb(unsigned long long nbr, const char *base, size_t *counter)
{
	unsigned long long	base_len;
	
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
		ft_pnb(nbr / base_len, base, counter);
	ft_putchar((char)base[nbr % base_len], counter);
}

static void     ft_put_d(long long n, size_t *counter)
{
	if (n < 0)
	{
		ft_putchar('-', counter);
		if (n == LLONG_MIN) 
		{
			ft_putstr("9223372036854775808", counter);
			return ;
		}
		n = -n;
	}
	ft_pnb((unsigned long long)n, "0123456789", counter);
}

static void	tri_format(t_format fmt, va_list args, size_t *c)
{

	if (fmt.type == 'c')
		ft_putchar((char)va_arg(args, int), c);
	else if (fmt.type == 's')
		ft_putstr(va_arg(args, char *), c);
	else if (fmt.type == 'd' || fmt.type == 'i')
		ft_put_d(va_arg(args, int), c);
	else if (fmt.type == 'u')
		ft_pnb(va_arg(args, unsigned int), "0123456789", c);
	else if (fmt.type == 'x')
		ft_pnb(va_arg(args, unsigned int), "0123456789abcdef", c);
	else if (fmt.type == 'X')
		ft_pnb(va_arg(args, unsigned int), "0123456789ABCDEF", c);
	else if (fmt.type == '%')
		ft_putchar('%', c);
	else if (fmt.type == 'p')
	{
		ft_putstr("0x", c);
		ft_pnb((unsigned long long)va_arg(args, void *), "0123456789abcdef", c);
	}
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	size_t		counter;
	size_t		i;
	t_format	fmt;

	i = 0;
	counter = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
		{
			i++;
			fmt.type = input[i];
			tri_format(fmt, args, &counter);
		}
		else
			ft_putchar(input[i], &counter);
		i++;
	}
	va_end(args);
	return ((int)counter);
}
