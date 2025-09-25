int	count_mod(const char *s)
{
	int	i;
	int	ct;

	i = 0;
	ct = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == '\0')
			return (1);
		if (s[i] == '%')
		{
			ct++;
			i++;
		}
		if (s[i] == '%' && s[i + 1] == '%' && s[i - 1] != '%')
			ct++;
		i++;
	}
	return (ct);
}
