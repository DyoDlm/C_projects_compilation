#include "ft_printf.h"

// Fonction pour calculer la longueur d'un long long (entier signé)
static int	long_long_len(long long value)
{
	int	len = (value <= 0) ? 1 : 0;
	
	while (value)
	{
		value /= 10;
		len++;
	}
	return (len);
}

static char	*long_long_to_string(long long value)
{
	int     len;
	char    *str;
	int     index;
	unsigned long long abs_value;  // Gérer l'absolu

	len = long_long_len(value);
	index = len - 1;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (value == 0)
		str[0] = '0';
	else if (value < 0)
		abs_value = (unsigned long long)(-value);
	else
		abs_value = (unsigned long long)value;
	while (abs_value > 0)
	{
		str[index--] = (abs_value % 10) + '0';
		abs_value /= 10;
	}
	if (value < 0)
		str[0] = '-';
	str[len] = '\0';
	return (str);
}

static int      unsigned_long_long_len(unsigned long long value)
{
	int len = 1;
	
	while (value /= 10)
		len++;
	return (len);
}

static char     *unsigned_long_long_to_string(unsigned long long value)
{
	int	len;
	char	*str;
	int	index;

	len = unsigned_long_long_len(value);
	index = len - 1;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (value == 0)
		str[0] = '0';
	while (value > 0)
	{
		str[index--] = (value % 10) + '0';
		value /= 10;
	}
	str[len] = '\0';
	return (str);
}

static char	*char_to_string(char c)
{
	char	*s;

	s = malloc(2 * sizeof(char));
	if (!c)
		return (NULL);
	s[0] = c;
	s[1] = '\0';
	return (s);
}	

static char	*hex_to_string(unsigned long long value, char type, char *hex_digits)
{
	char    *str;
	int     index = 0;
	int     start, end;
	char    temp;

	str = malloc(17 * sizeof(char));
	if (!str)
		return (NULL);
	if (value == 0)
		str[index++] = '0';

	if (type == 'X')
		hex_digits = "0123456789ABCDEF";
	while (value > 0)
	{
		str[index++] = hex_digits[value % 16];
		value /= 16;
	}
	str[index] = '\0';
	start = 0;
	end = index - 1;
	while (start < end)
	{
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}
	return (str);
}

char	*convertor(void *value, char type)
{
	char	*hex_digits = "0123456789abcdef";

	if (type == 'i' || type == 'd')
		return (long_long_to_string(*(long long *)value));
	else if (type == 'c')
		return (char_to_string(*(char *)value));
	else if (type == 's')
		return (value);
	else if (type == 'x' || type == 'X')
		return (hex_to_string(*(unsigned long long *)value, type, hex_digits));
	else if (type == 'u')
		return (unsigned_long_long_to_string(*(unsigned long long *)value));
	else if (type == 'p')
		return (hex_to_string((unsigned long long)value, type, hex_digits));
	return (NULL);
}
