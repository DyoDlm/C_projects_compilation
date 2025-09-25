#include "ft_printf.h"

void	store_pointer(t_argument *av, va_list args)
{
	av->type = 'p';
	av->value.p = va_arg(args, void *);
}

void	store_uns(t_argument *av, va_list args)
{
	av->type = 'u';
	av->value.u = va_arg(args, unsigned int);
}

void	store_hex(t_argument *av, va_list args)
{
	av->type = 'x';
	av->value.x = va_arg(args, unsigned int);
}
