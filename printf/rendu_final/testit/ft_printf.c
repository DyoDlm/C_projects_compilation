#include "ft_printf.h"

static void	free_args(t_argument *av, char **a, char *f, char *t)
{
	int	i;

	i = 0;
        while (t[i] != '\0')
	{
		if (f[i] != 's' && a[i] != NULL)
                	free(a[i]);
		i++;
	}
	if (a)
        	free(a);
        if (av)
		free(av);
        if (f)
		free(f);
	if (t)
		free(t);
}

static void	free_tab(char **tab, int allocated_count)
{
	int	i;

	i = 0;
	while (i < allocated_count)
	{
//		printf("iis%d\n", i);
		if (tab[i] != NULL)
			free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

static char	*cut_input(const char *input)
{
	int	i;
	int	j;
	char	*temp;

	i = 0;
	j = 0;
	if (!input)
		return (NULL);
	temp = malloc((2 + ft_strlen(input)) * sizeof(char));
	if (!temp)
		return (NULL);
	while (input[i] && input[i] != '%')
		write(1, &input[i++], 1);
	while (input[i])
		temp[j++] = input[i++];
	if ((input[0] == '%' && input[1] == '\0') || input[0] == '\0')
	{
		temp[0] = '%';
		temp[1] = '@';
		if (input[0] == '\0')
			temp[0] = '@';
		temp[2] = '\0';
	}
	else if (input[0] == '\0')
		temp[0] = '@';
	return (temp);
}

char	*store_t_in_tab(t_argument *av, int count)
{
	char	*t;
	int	i;

	i = 0;
	t = malloc((count + 1) * sizeof(char));
//	printf("\ncount is :%d\n", count);
	if (!t)
		return (NULL);
	while (av[i].type != -1)
	{
		if (av[i].type == 's')
			t[i] = 's';
		else if (av[i].type == 'd' || av[i].type == 'i')
			t[i] = 'i';
		else if (av[i].type == 'x' || av[i].type == 'X')
			t[i] = av[i].type;
		else if (av[i].type == 'u')
			t[i] = 'u';
		else if (av[i].type == 'c')
			t[i] = 'c';
		else if (av[i].type == 'p')
			t[i] = 'p';
		else if (av[i].type == '%')
			t[i] = '%';
		i++;
//		printf("type is :%c", t[i - 1]);
	}
	t[i] = '\0';
//	printf("\n type is :%c\n", t[i]);
	return (t);
}

static char	*convert_value(t_argument av)
{
	char	*res;
	char	mod;

	mod = '%';
	res = NULL;
	if (av.type == 'c')
		res = convertor(&av.value.c, av.type);
	else if (av.type == 'd' || av.type == 'i')
		res = convertor(&av.value.i, av.type);
	else if (av.type == 'u')
		res = convertor(&av.value.u, av.type);
	else if (av.type == 'x' || av.type == 'X')
		res = convertor(&av.value.x, av.type);
	else if (av.type == 'p')
		res = convertor(&av.value.p, av.type);
	else if (av.type == 's')
		res = av.value.s;
	else
		res = convertor(&mod, av.type);
//	printf("res is :%s\n", res);
	return (res);
}

char	**store_a_in_tab(t_argument *av, int count)
{
	char	**tab;
	int	i;

	i = 0;
	tab = malloc((count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (av[i].type != -1)
	{
		tab[i] = convert_value(av[i]);
//		printf("here is tab :%s\n", tab[i]);
		if (tab[i] == NULL && av[i].type != '%')
		{
			printf("zaza");
			free_tab(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	store_arg(t_argument *av, va_list args, char *input, int k)
{
	int	**d;
	int	**r;
	char	**s;
	char	specifier;

	s = ss(input);
	d = dx(s[k]);
	r = flag_rules(s[k], d);
	specifier = (char)r[3][4];
	if (specifier == 'd' || specifier == 'i')
		store_int(av, args);
	else if (specifier == 'x')
		store_hex(av, args);
	else if (specifier == 'X')
		store_hexmaj(av, args);
	else if (specifier == 'u')
		store_uns(av, args);
	else if (specifier == 'c')
		store_char(av, args);
	else if (specifier == 's')
		store_string(av, args);
	else if (specifier == 'p')
		store_pointer(av, args);
	else
		store_mod(av);
	free(s);
	free(r);
	return (1);
}

t_argument	*store_arguments(char *input, va_list args, int count)
{
	t_argument	*av;
	int		i;
	int		j;
	int		k;

	av = malloc((count + 1) * sizeof(t_argument));
	if (!av)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			if (input[i])
			{
				j += store_arg(&av[j], args, input, k);
				k++;
			}
		}
		i++;
	}
	av[j].type = -1;
	return (av);
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	char		*ninput;
	t_argument	*av;
	char		**arg_tab;
	char		*type_tab;

	ninput = cut_input(input);
	if (ninput[0] == '%' && ninput[1] == '@')
		ft_putchar('%');
	if (ninput[0] == '@' || ninput[1] == '@')
		return (-1);
	va_start(args, input);
	av = store_arguments(ninput, args, count_mod(ninput));
	va_end(args);
//	printf("11");
	if (check_free1(av, ninput) == -1)
		return (-1);
	type_tab = store_t_in_tab(av, count_mod(ninput));
//	printf("%s\n");
	if (check_free2(type_tab, av, ninput) == -1)
		return (-1);
	arg_tab = store_a_in_tab(av, count_mod(ninput));
//	printf("33");
	if (check_free3(arg_tab, type_tab, av, ninput) == -1)
		return (-1);
	if (gerrors(ss(ninput), arg_tab, type_tab) == 0)
		putseg(ninput, arg_tab, type_tab);
	free_args(av, arg_tab, type_tab, ninput);
	return (0);
}
