#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

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
	}	value;
}	t_argument;

//	STORAGE
void	store_int(t_argument *av, va_list args);
void	store_char(t_argument *av, va_list args);
void	store_string(t_argument *av, va_list args);
//void	store_pointer(t_argument *av, va_list args);
void	store_uns(t_argument *av, va_list args);
void	store_hex(t_argument *av, va_list args);

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

//	PUT SEGMENTS
void	put_minus(int **d, char *av, char t);
void	put_plus(int **d, char *av, char t);
void	put_precision(int **d, char *av, char t);
void	put_sharp(int **d, char *av, char t);
void	put_zero(int **d, char *av, char t);
void	put_space(int **d, char *av, char t);

//	BIG DADYS
int	ft_printf(const char *input, ...);
int	**dx(char *segment);
int	**flag_rules(char *seg, int **data);
char	**ss(const char *seg);
void	putseg(char **segs, char **av, char *av_t);
int	gerrors(char **segs, char **av, char *t);

#endif
