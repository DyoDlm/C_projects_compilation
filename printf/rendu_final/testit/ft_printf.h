#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

typedef	struct	s_argument
{
	int	type;
	union
	{
		int		i;
		unsigned int	u;
		char		c;
		char		*s;
		void		*p;
		unsigned int	x;
		char		m;
	}	value;
}	t_argument;

//	STORAGE
void	store_int(t_argument *av, va_list args);
void	store_char(t_argument *av, va_list args);
void	store_string(t_argument *av, va_list args);
//void	store_pointer(t_argument *av, va_list args);
void	store_uns(t_argument *av, va_list args);
void	store_hex(t_argument *av, va_list args);
void	store_mod(t_argument *av);
void	store_hexmaj(t_argument *av, va_list args);
void	store_pointer(t_argument *av, va_list args);
//	TOOLS
int	ft_atoi(const char *nptr);
char	*ft_itoa(int n);
void	ft_putnstr(char *str, int n);
int	count_mod(const char *s);
void	ft_putchar(char c);
char	*ft_strdup(const char *s);
int	ft_strlen(const char *str);
void	ft_putstr(char *str);
int	ft_isdigit(int c);
char	*ft_strcpy(char *s);
int	ft_toupper(int c);
//	PUT SEGMENTS
void	put_minus(int *d, char *av, char t);
void	put_plus(int *d, char *av, char t);
void	put_precision(int *d, char *av, char t);
void	put_sharp(int *d, char *av, char t);
void	put_zero(int *d, char *av, char t);
void	put_space(int *d, char *av, char t);
int	count_mod(const char *s);
//	BIG DADYS
int	ft_printf(const char *input, ...);
int	**dx(char *segment);
int	**flag_rules(char *seg, int **data);
char	**ss(const char *seg);
void	putseg(char *segs, char **av, char *av_t);
int	gerrors(char **seg, char **arg_tab, char *type_tab);
char	*convertor(void *value, char type);
int	check_free1(t_argument *av, char *ninput);
int	check_free2(char *tt, t_argument *av, char *ninput);
int	check_free3(char **at, char *tt, t_argument *av, char *ninput);
int	free_data0(int *d0, int **d);
int	free_data1(int *d1, int *d0, int **d);
int	free_data2(int *d2, int *d1, int *d0, int **d);
int	free_data3(int *d3, int *d2, int *d1, int *d0, int **d);

#endif
