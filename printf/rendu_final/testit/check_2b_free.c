#include "ft_printf.h"

int	check_free1(t_argument *av, char *ninput)
{
	if (!av)
	{
		free(ninput);
		ft_putstr("\nFAIL IN CHECKFREE1\n");
		return (-1);
	}
	return (0);
}

int	check_free2(char *tt, t_argument *av, char *ninput)
{
	if (!tt)
	{
		printf("fail1");
		free(av);
		printf("fail2");
		free(ninput);
		ft_putstr("\nFAIL IN CHECKFREE2\n");
		return (-1);
	}
	return (0);
}

int	check_free3(char **at, char *tt, t_argument *av, char *ninput)
{
	if (!at)
	{
		free(tt);
		free(av);
		free(ninput);
		ft_putstr("\nFAIL IN CHECKFREE3\n");
		return (-1);
	}
	return (0);
}
