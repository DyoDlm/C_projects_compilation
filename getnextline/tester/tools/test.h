#ifndef TEST_H
# define TEST_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>

typedef struct s_data
{
    int         disolvant;
	char		*rules;
}	t_data;

void    merrors(int sig);
void    mrules(int sig);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	getlen(const char *str);
void	ft_putstr(const char *str);

#endif