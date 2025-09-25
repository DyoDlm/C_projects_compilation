#include "get_next_line.h"

#define CHUNK_SIZE 4096  // Taille pour les lectures en morceaux

char *ft_free_join(char *buffer, char *buf)
{
    char *temp;

    temp = ft_strjoin(buffer, buf);
    free(buffer);
    return (temp);
}

char *extract_line(char *buffer)
{
    char *line;
    int i = 0;

    if (!buffer || !buffer[i])
        return (NULL);

    while (buffer[i] && buffer[i] != '\n')
        i++;

    line = ft_calloc(i + 2, sizeof(char));
    if (!line)
        return (NULL);

    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] == '\n')
        line[i] = '\n';

    return (line);
}

char *update_buffer(char *buffer)
{
    int i = 0;
    int j = 0;
    char *new_buffer;

    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (!buffer[i])
    {
        free(buffer);
        return (NULL);
    }

    new_buffer = ft_calloc(ft_strlen(buffer) - i, sizeof(char));
    if (!new_buffer)
        return (NULL);

    i++;
    while (buffer[i])
        new_buffer[j++] = buffer[i++];

    free(buffer);
    return (new_buffer);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;
    char temp_buf[BUFFER_SIZE + 1];
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);

    if (!buffer)
        buffer = ft_calloc(1, sizeof(char));

    bytes_read = 1;
    while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
    {
        bytes_read = read(fd, temp_buf, BUFFER_SIZE);
        if (bytes_read < 0)
            return (free(buffer), NULL);
        
        temp_buf[bytes_read] = '\0';
        buffer = ft_free_join(buffer, temp_buf);
    }

    line = extract_line(buffer);
    buffer = update_buffer(buffer);

    return (line);
}

