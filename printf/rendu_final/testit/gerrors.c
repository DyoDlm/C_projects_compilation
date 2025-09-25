#include "ft_printf.h"

int	gerrors(char **seg, char **arg_tab, char *type_tab)
{
	int	i;

	i = 0;
	if (!seg || !arg_tab || !type_tab)
		return (-1);
	while (seg[i] != NULL)
	{
		if (type_tab[i] == 's' && arg_tab[i] == NULL)
			return (-2);
		i++;
	}
	return (0);
}

