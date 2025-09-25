#include "ft_printf.h"

void	print_char_with_padding(char c, t_flags flags)
{
	if (flags.minus)
		ft_putchar(c);
	ft_put_padding(' ', flags.width - 1);
	if (!flags.minus)
		ft_putchar(c);
}

void	ft_print_char(char c, t_flags flags)
{
	print_char_with_padding(c, flags);
}

int	get_str_print_length(char *str, t_flags flags)
{
	int	len;
	
	len = ft_strlen(str);
	if (flags.precision >= 0 && flags.precision < len)
		len = flags.precision;
	return (len);
}

void	print_string_with_padding(char *str, int len, t_flags flags)
{
	if (flags.minus)
		ft_putnstr(str, len);
	ft_put_padding(' ', flags.width - len);
	if (!flags.minus)
		ft_putnstr(str, len);
}

void	ft_print_string(char *str, t_flags flags)
{
	int	len;

	len = get_str_print_length(str, flags);
	print_string_with_padding(str, len, flags);
}

void	print_sign(int n, t_flags flags)
{
	if (n >= 0)
	{
		if (flags.plus)
			ft_putchar('+');
		else if (flags.space)
			ft_putchar(' ');
	}
}

void	ft_print_int(int n, t_flags flags)
{
	char	*num_str;
	int	len;
	
	num_str = ft_itoa(n);
	len = ft_strlen(num_str);
	print_sign(n, flags);
	if (flags.minus)
		ft_putstr(num_str);
	ft_put_padding(flags.zero ? '0' : ' ', flags.width - len);
	if (!flags.minus)
		ft_putstr(num_str);
	free(num_str);
}

void	print_hex_prefix(unsigned int n, t_flags flags, int uppercase)
{
	if (flags.sharp && n != 0)
		ft_putstr(uppercase ? "0X" : "0x");
}

void	convert_and_print_hex(unsigned int n, int uppercase)
{
	char	*base;
	char	buffer[9];
	int	i;

	i = 0;
	base = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	if (n == 0)
		buffer[i++] = '0';
	while (n)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	while (--i >= 0)
		ft_putchar(buffer[i]);
}

void	ft_print_hex(unsigned int n, t_flags flags, int uppercase)
{
	print_hex_prefix(n, flags, uppercase);
	convert_and_print_hex(n, uppercase);
}
