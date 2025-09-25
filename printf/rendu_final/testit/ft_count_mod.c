int	count_mod(const char *s)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	if (!s)
		return (ct);
	while (s && s[i])
	{
		if (s[i] == '%' && s[i + 1] == '\0')
			return (1);
		if (s[i] == '%')
		{
			ct++;
			i++;
		}
		if (i > 0 && s[i] == '%' && s[i + 1] == '%' && s[i - 1] != '%')
			ct++;
		i++;
	}
	return (ct);
}
/*
int	main()
{
	char	*s = "a";
	int	i;

	i = count_mod(s);
	printf("%d\n", i);
	return (0);
}*/
