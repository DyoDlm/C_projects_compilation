#include "libprintft.h"

void	putseg(int **d, char *seg, void *av)
{
	if (d[3][0] == 0)
		ft_putstr(seg);
	else
	{
		if (d[3][2] == -3)
			put_point_precision(d[3], seg, av);
		else if (d[3][2] == -1 || d[3][2] == -2)
			ft_putstr("en construction");	//put_spaces_or_zeros(d[3], seg, av)
		else if (d[3][2] == -4)
			ft_putstr("en construction");	//put_an_alignment();
		else if (d[3][2] == -5)
			ft_putstr("en construction");	//put_plus();
		else if (d[3][2] == -6)
			ft_putstr("en construction");	//put_hashtag();
		else
			return ;
	}
	if (pos != len_of_string && d[3][2] != -4)
		ft_putstr("en construction");
	free(data);
	free(av);
}
