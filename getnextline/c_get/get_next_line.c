#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static char	*redaction(char *prototype, char *new_chapter)
{
	char	*book_updated;

	book_updated = ft_strjoin(prototype, new_chapter);
	free(prototype);
	printf("book_updated is :%s\n", book_updated);
	return (book_updated);
}

static char	*next_chapter(char *prototype)
{
	int	word;
	int	cpy_word;
	char	*new_chap;
	char	end_book;
	char	end_chapter;

	word = 0;
	end_book = '\0';
	end_chapter = '\n';
	while (prototype[word] != end_book && prototype[word] != end_chapter)
		word++;
	if (!prototype[word])
	{
		free(prototype);
		return (NULL);
	}
	new_chap = ft_calloc((ft_strlen(prototype) - word + 1), sizeof(char));
	word++;
	cpy_word = 0;
	while (prototype[word] != end_book)
		new_chap[cpy_word++] = prototype[word++];
	printf("nb word copied are :%d\n", cpy_word);
	free(prototype);
	printf("new_chapter :%s\n", new_chap);
	return (new_chap);
}

static char	*write_chapter(char *prototype)
{
	char	*chapter;
	int		word;
	char	end_book;
	char	end_chapter;

	word = 0;
	end_book = '\0';
	end_chapter = '\n';
	if (!prototype[word])
		return (NULL);
	while (prototype[word] != end_book && prototype[word] != end_chapter)
		word++;
	chapter = ft_calloc(word + 2, sizeof(char));
	word = 0;
	while (prototype[word] != end_book && prototype[word] != end_chapter)
	{
		chapter[word] = prototype[word];
		word++;
	}
	if (prototype[word] != end_book && prototype[word] == end_chapter)
		chapter[word++] = '\n';
	printf("chapter written :%s\n", chapter);
	return (chapter);
}

static char	*find_inspiration(int fd, char *inspiration)
{
	char	*prototype;
	int	nb_letters;

	nb_letters = 1;
	if (!inspiration)
		inspiration = ft_calloc(1, 1);
	prototype = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (nb_letters > 0)
	{
		nb_letters = read(fd, prototype, BUFFER_SIZE);
		printf("nb letters is :%d\n", nb_letters);
		if (nb_letters == -1)
		{
			free(prototype);
			return (NULL);
		}
		prototype[nb_letters] = '\0';
		inspiration = redaction(inspiration, prototype);
		printf("inspiration is :%s\n", inspiration);
		if (ft_strchr(prototype, '\n'))
			break ;
	}
	free(prototype);
	return (inspiration);
}

char	*get_next_line(int fd)
{
	static char	*prototype;
	char		*chapter;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	prototype = find_inspiration(fd, prototype);
	printf("prototype 1 is :%s\n", prototype);
	if (!prototype)
		return (NULL);
	chapter = write_chapter(prototype);
	printf("chapter is :%s\n", chapter);
	prototype = next_chapter(prototype);
	printf("prototype 2 is :%s\n", prototype);
	return (chapter);
}

int	main()
{
	int	fd;
   	char *line;
    int     i = 0;

    fd = open("x.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("\n\n\n\n\nTHE LINE %d: %s\n\n\n\n\n", i, line);
        free(line);
        i++;
    }

    // Fermer le fichier
    close(fd);
    return (0);
}
