#include "ft_printf.h"

static int	long_long_len(long long value)
{
	int	len;
	
	len = (value <= 0) ? 1 : 0;
	while (value)
	{
		value /= 10;
		len++;
	}
	return (len);
}

static char	*long_long_to_string(long long value)
{
	int	len;
	char	*str;
	int	index;
	unsigned long long	abs_value;

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

static char	*char_to_string(char value)
{
	char	*str;

	str = malloc(2 * sizeof(char));	
	if (str)
	{
		str[0] = value;
		str[1] = '\0';
	}
	return (str);
}

static int	unsigned_long_long_len(unsigned long long value)
{
    int len = 1;
    while (value /= 10)
        len++;
    return (len);
}

static int	unsigned_len(unsigned int value)
{
	int	len;
	
	len = 1;
	while (value /= 10)
		len++;
	return (len);
}

static char	*unsigned_to_string(unsigned int value)
{
	int	len;
	char	*str;
	int	index;
	
	len = unsigned_len(value);
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

static char	*hex_to_string(unsigned int value, char type, char *hex_digits)
{
	char	*str;
	int	index;
	int	start;
	int	end;
	char	temp;

	index = 0;
	start = 0;
	end = 0;
	temp = 't';
	str = malloc(9 * sizeof(char));
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
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (type == 'i' || type == 'd')
		return (int_to_string(*(int *)value));
	else if (type == 'c')
		return (char_to_string(*(char *)value));
	else if (type == 's')
		return (value);
	else if (type == 'x' || type == 'X')
		return (hex_to_string(*(unsigned int *)value, type, hex_digits));
	else if (type == 'u')
		return (unsigned_to_string(*(unsigned int *)value));
	else if (type == 'p')
		return (hex_to_string((unsigned int)value, type, hex_digits));
	return (NULL);
}
