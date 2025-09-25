#include "ft_printf.h"

int	gerrors(char **segs, char **av, char *t)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (av == NULL || segs == NULL || t[j] == '\0')
		return (1);
	while (segs[i])
	{
		if (dx(segs[i + j])[3][0] == 0)
			i++;
		else if (dx(segs[i + j])[3][4] != t[j] && av[j])
			return (1);
		else
			j++;
	}
	return (0);
}
