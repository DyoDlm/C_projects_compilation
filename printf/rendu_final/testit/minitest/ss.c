//#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int	count_mod(char *segment);

static int	help_get_len(const char *s, int *i)
{
	int	len;
	int	mc;

	len = 0;
	mc = 0;
	while (s[*i] && mc < 1)
	{
		printf("  pos %d :%c", *i, s[*i]);
		while (s[*i] != '%' && s[*i])
		{
			(*i)++;
			len++;
			printf("  pos %d :%c", *i, s[*i]);
		}
		if (s[*i] == '%' && len == 0)
		{
	       		mc++;
			len++;
			(*i)++;
			printf("  pos %d :%c", *i, s[*i]);
		}
		if (s[*i] == '%' && len == 1)
		{
			if (s[*i - 1] == '%')
			{	
				(*i)++;
				len++;
				printf("  pos %d :%c", *i, s[*i]);
			}
			mc++;
		}
		printf("  pos %d :%c", *i, s[*i]);
		while (s[*i] != '%' && s[*i] && mc == 1)
		{
			(*i)++;
			len++;
			printf("  pos %d :%c", *i, s[*i]);
		}
		if (s[*i] == '\0' || s[*i] == '%')
			mc++;
		printf("\n\nNew seg\n");
	}
	return (len);
}

static char	*help_get_segment(const char *seg, int *i)
{
	int	len;
	char	*sub;
	int	k;

	k = 0;
	len = help_get_len(seg, i);
	sub = malloc((len + 1) * sizeof(char *));
	if (!sub)
		return (NULL);
	while (k < len && seg[*i - len + k])
	{
		if (seg[*i - len + k])
		{
			sub[k] = seg[*i - len + k];
			k++;
		}
	}
	sub[len] = '\0';
	return (sub);
}

char	**ss(const char *seg)
{
	int	i;
	int	j;
	int	mod_count;
	char	**segments;
	
	i = 0;
	j = 0;
	mod_count = count_mod((char*)seg);
	segments = malloc((mod_count + 1) * sizeof(char *));
	if (!segments)
		return (NULL);
	while (seg[i]) 
	{
		segments[j] = help_get_segment(seg, &i);
		if (!segments[j])
		{
			while (j > 0)
				free(segments[--j]);
			free(segments);
			return (NULL);
		}
		printf("j is %d where seg is :%s\n", j, segments[j]);
		j++;
	}
	segments[j] = NULL;
	printf("j is %d where seg is :%s\n", j, segments[j]);
	return (segments);
}
