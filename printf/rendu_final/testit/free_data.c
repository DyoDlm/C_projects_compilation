#include "ft_printf.h"

int	free_data0(int *d0, int **d)
{
	if (!d0)
	{
		free(d);
		ft_putstr("\nFAIL IN FREEDATA0\n");
		return (-1);
	}
	return (0);
}

int	free_data1(int *d1, int *d0, int **d)
{
	if (!d1)
	{
		free(d0);
		free(d);
		ft_putstr("\nFAIL IN FREEDATA1\n");
		return (-1);
	}
	return (0);
}

int	free_data2(int *d2, int *d1, int *d0, int **d)
{
	if (!d2)
	{
		free(d1);
		free(d0);
		free(d);
		ft_putstr("\nFAIL IN FREEDATA2\n");
		return (-1);
	}
	return (0);
}

int	free_data3(int *d3, int *d2, int *d1, int *d0, int **d)
{
	if (!d3)
	{
		free(d2);
		free(d1);
		free(d0);
		free(d);
		ft_putstr("\nFAIL IN FREEDATA3\n");
		return (-1);
	}
	return (0);
}
