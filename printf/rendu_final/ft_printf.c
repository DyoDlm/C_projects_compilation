#include "ft_printf.h"

char	*store_t_in_tab(t_argument *av, int count)
{
	char	*t;
	int	i;

	t = malloc((count + 1) * sizeof(char));
	i = 0;
	if (!t)
		return (NULL);
	while (av[i].type != -1)
	{
		if (av[i].type == 's')
			t[i++] = 's';
		else if (av[i].type == 'd' || av[i].type == 'i')
			t[i++] = 'i';
		else if (av[i].type == 'x')
			t[i++] = 'x';
		else if (av[i].type == 'u')
			t[i++] = 'u';
		else if (av[i].type == 'c')
			t[i++] = 'c';
		else if (av[i].type == 'p')
			t[i++] = 'p';
	}
	t[i] = '\0';
	return (t);
}

char **store_a_in_tab(t_argument *av, int count)
{
	char	**tab;
	int	i;

	i = 0;
	tab = malloc((count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (av[i].type != -1)
	{
		if (av[i].type == 's' || av[i].type == 'c')
			tab[i] = ft_strdup(av[i].value.s);
		else if (av[i].type == 'd' || av[i].type == 'i')
			tab[i] = ft_itoa(av[i].value.i);
		else if (av[i].type == 'u')
			tab[i] = ft_itoa(av[i].value.u);
		else if (av[i].type == 'x')
			tab[i] = ft_itoa(av[i].value.x);
		else if (av[i].type == 'p')
			tab[i] = "pointer";//ft_itoa(av[i].value.s);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	store_arg(t_argument *av, va_list args, char specifier)
{
	if (specifier == 'd' || specifier == 'i')
		store_int(av, args);
	else if (specifier == 'x' || specifier == 'X')
		store_hex(av, args);
	else if (specifier == 'u')
		store_uns(av, args);
	else if (specifier == 'c')
		store_char(av, args);
	else if (specifier == 's')
		store_string(av, args);
	return (1);
}

t_argument	*store_arguments(const char *input, va_list args, int count)
{
	t_argument	*av;
	int		i;
	int		j;
	
	av = malloc((count + 1) * sizeof(t_argument));
	if (!av)
		return NULL;
	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			if (input[i])
				j += store_arg(&av[j], args, input[i]);
		}
		i++;
	}
	av[j].type = -1;
	return (av);
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	int		count;
	t_argument	*av;
	char		**arg_tab;
	char		*type_tab;

	count = count_mod(input);
	if (count < 0)
		return (-1);
	va_start(args, input);
	av = store_arguments(input, args, count);
	va_end(args);
	if (!av)
		return (-1);
	type_tab = store_t_in_tab(av, count);
	arg_tab = store_a_in_tab(av, count);
	if (gerrors(ss(input), arg_tab, type_tab) == 0)
		putseg(ss(input), arg_tab, type_tab);
	count = 0;
   	while (arg_tab[count] != NULL)
        	free(arg_tab[count++]);
	free(arg_tab);
	free(av);
	free(type_tab);
	return (0);
}
/*
int	main()
{
	int	i = 42;
	int i2 = 44;
	int i3 = 45;
	int i4 = 46;
	int i5 = 47;
	int i6 = 58;
	
	ft_printf("%i%i%i%i%i%i", i, i2, i3, i4, i5, i6);
//	ft_printf("%d %u %x", 123, 456U, 0xabc);
	return (0);
}*/
