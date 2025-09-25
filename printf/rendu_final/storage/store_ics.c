#include "ft_printf.h"

void	store_int(t_argument *av, va_list args)
{
	av->type = 'd';
	av->value.i = va_arg(args, int);
}

void	store_char(t_argument *av, va_list args)
{
	av->type = 'c';
	av->value.c = (char)va_arg(args, int);
}

void	store_string(t_argument *av, va_list args)
{
	av->type = 's';
	av->value.c = va_arg(args, char *);
}
