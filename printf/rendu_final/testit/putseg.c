#include "ft_printf.h"

static void	free_2e_tab(int **tab)
{
	int	i;

	i = 0;
//	printf("YI");
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	free_segs(char **segs)
{
	int	i;

	i = 0;
//	printf("Yo");
	if (segs == NULL)
		return ;
	while (segs[i] != NULL)
	{
		if (segs[i] == NULL)
			i++;
		else
			free(segs[i++]);
	}
	if (segs != NULL)
		free(segs);
}

static int	okk(char *seg)
{
	int	**data;
	int	**rules;

//	printf("seg is :%s\n", seg);
	data = dx(seg);
	rules = flag_rules(seg, data);
	if ((seg[1] == '%' || seg[0] != '%') && rules[3][0] == 2)
	{
		free_2e_tab(rules);
		if (seg[0] != '%')
			ft_putstr(seg);
		else
			ft_putchar('%');
		return (2);
	}
	else if (rules[3][0] == 1)
	{
		free_2e_tab(rules);
		return (1);
	}
	else if (rules[3][0] == 0)
	{	
		free_2e_tab(rules);
		return (0);
	}
	return (2);
}

static int	*getdata(int **rules)
{
	int	*chop;

//	printf("EE");
	chop = malloc(6 * sizeof(int));
	chop[0] = rules[3][0];
	chop[1] = rules[3][1];
	chop[2] = rules[3][2];
	chop[3] = rules[3][3];
	chop[4] = rules[3][4];
	chop[5] = rules[3][5];
	free_2e_tab(rules);
	return (chop);
}

static int	ft_shoot(char *seg, char *av, char type)
{
	int	**data;
	int	**rules;
	int	*chop;

	data = dx(seg);
	rules = flag_rules(seg, data);
	chop = getdata(rules);
//	printf("error or not :%d\n", chop[0]);
	if (chop[2] == -1)
		put_space(chop, av, type);
	else if (chop[2] == -2)
		put_zero(chop, av, type);
	else if (chop[2] == -3)
		put_precision(chop, av, type);
	else if (chop[2] == -4)
		put_minus(chop, av, type);
	else if (chop[2] == -5)
		put_plus(chop, av, type);
	else if (chop[2] == -6)
		put_sharp(chop, av, type);
	else
		ft_putstr(av);
	return (chop[5]);
}

static void	put_final_string(int pos, char *str)
{
	int	i;

//	printf("HEZ");
	i = 1;
	if (str[0] == '%' && str[1] == '%')
	{
		ft_putchar('%');
		return ;
	}
	while (str[pos + i])
	{
		write(1, &str[pos + i], 1);
		i++;
	}
}

void	putseg(char *segs, char **av, char *av_t)
{
	int	i;
	int	j;
	int	pos;
	char	**sos;

	i = 0;
	j = 0;
	sos = ss(segs);
	while (sos[i][j] != '%')
		ft_putchar(sos[i][j++]);
	j = 0;
	printf("count is :%d\n", count_mod(segs));
	while ((i + j) < count_mod(segs))
	{
		printf("jj is :%d\n", i + j);
		if (okk(sos[i + j]) == 2)
		{
//			printf("kk is :%d\n", i + j);
			i++;
		}
		else if (av_t[j])
		{
			pos = ft_shoot(sos[i + j], av[j], av_t[j]);
//			printf("LL is :%d\n", i + j);
			if (av[j] != NULL)
				put_final_string(pos, sos[i + j]);
			j++;
		}
		printf("MM is :%d\n", i + j);
	}
//	printf("AAAAA!");
	free_segs(sos);
}
