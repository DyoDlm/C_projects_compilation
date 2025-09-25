#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>

typedef struct
{
	char	type;
}	format_t;

int	ft_printf(const char *input, ...);

#endif
