#include "ft_printf.h"

void	parse_basic_flags(const char **t, t_flags *flags)
{
	while (**t == 45 || **t == 48 || **t == 43 || **t == 32 || **t == 35)
	{
		if (**t == '-') flags->minus = 1;
		if (**t == '0') flags->zero = 1;
		if (**t == '+') flags->plus = 1;
		if (**t == ' ') flags->space = 1;
		if (**t == '#') flags->sharp = 1;
		(*t)++;
	}
}

void	parse_width(const char **t, t_flags *flags, va_list args)
{
	if (ft_isdigit(**t))
		flags->width = ft_atoi(t);
	else if (**t == '*')
	{
		flags->width = va_arg(args, int);
		(*t)++;
	}
}

void	parse_precision(const char **t, t_flags *flags, va_list args)
{
	if (**t == '.')
	{
		(*t)++;
		if (ft_isdigit(**t))
			flags->precision = ft_atoi(t);
		else if (**t == '*')
		{
			flags->precision = va_arg(args, int);
			(*t)++;
		}
		else
			flags->precision = 0;
	}
}

void	ft_parse_flags(const char **t, t_flags *flags, va_list args)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = -1;
	flags->width = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->sharp = 0;

	parse_basic_flags(t, flags);
	parse_width(t, flags, args);
	parse_precision(t, flags, args);
}
