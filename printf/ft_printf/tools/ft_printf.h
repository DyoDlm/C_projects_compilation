#ifndef LIBPRINTFT_H
#define LIBPRINTFT_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <stddef.h>

typedef struct s_flags
{
	int minus;
	int zero;
	int width;
	int precision;
	int plus;
	int space;
	int sharp;
} t_flags;

void	ft_putnstr(char *str, int len);
int	ft_printf(const char *input, ...);
void	ft_parse_flags(const char **format, t_flags *flags, va_list args);

//	TOOLS1
void	ft_print_char(char c, t_flags flags);
void	ft_print_string(char *str, t_flags flags);
void	ft_print_int(int n, t_flags flags);
void	ft_print_unsigned(unsigned int n, t_flags flags);
void	ft_print_hex(unsigned int n, t_flags flags, int uppercase);
void	ft_print_pointer(void *ptr, t_flags flags);
void	ft_print_percent(t_flags flags);
void	handle_conversion(const char **format, va_list args, t_flags flags);

//	TOOLS2
int	ft_isdigit(int c);
int	ft_atoi(const char **str);
void	ft_putstr(char *str);
void	ft_putnstr(char *str, int n);
void	ft_putchar(char c);
int	ft_strlen(const char *str);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_utoa_base(unsigned long long n, int base);
void	ft_print_unsigned(unsigned int n, t_flags flags);
void	ft_put_padding(char c, int n);
int	count_mod(const char *s);
char	**seg_input(const char *seg);

#endif
