#include "ft_printf.h"

void	handle_conversion(const char **format, va_list args, t_flags flags)
{
	if (**format == 'c')
		ft_print_char(va_arg(args, int), flags);
	else if (**format == 's')
		ft_print_string(va_arg(args, char *), flags);
	else if (**format == 'd' || **format == 'i')
		ft_print_int(va_arg(args, int), flags);
	else if (**format == 'u')
		ft_print_unsigned(va_arg(args, unsigned int), flags);
	else if (**format == 'x')
		ft_print_hex(va_arg(args, unsigned int), flags, 0);
	else if (**format == 'X')
		ft_print_hex(va_arg(args, unsigned int), flags, 1);
	else if (**format == 'p')
		ft_print_pointer(va_arg(args, void *), flags);
	else if (**format == '%')
		ft_print_percent(flags);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	t_flags	flags;

	va_start(args, input);
	while (*input)
	{
		if (*input)
		{
			input++;
			ft_parse_flags(&input, &flags, args);
			handle_conversion(&input, args, flags);
		}
		else
			ft_putchar(*input);
		input++;
	}
	va_end(args);
	return (0);
}
