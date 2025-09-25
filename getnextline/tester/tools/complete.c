#include "test.h"

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

size_t	getlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dest;
	
	size = getlen(src);
	dest = (char *)malloc(size * sizeof(char) + 1);
	if (dest == NULL)
		return (0);
	ft_memcpy(dest, src, size);
	dest[size] = '\0';
	return (dest);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}


void	merrors(int sig)
{
	if (sig == 1)
		ft_putstr("Mauvais nombre d'argument pegu\n");
	if (sig == 2)
		ft_putstr("zz\n");
	if (sig == -1)
		ft_putstr("Ceci n'est pas un nombre\n");
	if (sig == 8)
		ft_putstr("FUCK\n GOT IT OK ?!\n");
}

void	mrules(int sig)
{
	if (sig == 1)
	{
		ft_putstr("Salut, salut ! Avant de lancer l'application graphique ");
		ft_putstr("tu dois decider avec quelles regles tu veux executer le ");
		ft_putstr("programme. \n\nVoici les options :\n\n");
		ft_putstr("MODE COULEUR :\n1 : OUI	2 : NON\n");
	}
	if (sig == 5)
		ft_putstr("PARAMETRES POUR JULIA (C):\n");
	if (sig == 4)
		ft_putstr("PARAMETRES POUR JULIA (Z):\n");
	if (sig == 3)
		ft_putstr("Reponse enregistree.\n\n");
	if (sig == 2)
		ft_putstr("Merci pour ta patience !\n");
}