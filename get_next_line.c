#include "get_next_line.h"

unsigned int	ft_strlen(const char *s)
{
	unsigned int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	int		dir;
	unsigned int	i;

	if (len == 0 || dst == src)
		return (dst);
	dir = 1;
	i = 0;
	if (dst > src)
	{
		dir = -1;
		i = len - 1;
	}
	while (i < len)
	{
		((char *)dst)[i] = ((char *)src)[i];
		if (i == 0 && dir == -1)
			break ;
		i += dir;
	}
	return (dst);
}

char *my_strnjoin(char *line, char *buffer, unsigned int buff_n)
{
    char    *res;
    unsigned int    line_len;
    
	line_len = ft_strlen(line);
	res = (char *)malloc((line_len + buff_n + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memmove(res, line, line_len);
	ft_memmove(res + line_len, buffer, buff_n);
	res[line_len + buff_n] = 0;
	return (res);
}

int    move_check_buffer(char *buffer, unsigned int *buffer_pos, char **line)
{
    unsigned int    i;
    char    *temp;

    i = -1;
    while (++i < *buffer_pos)
        if (buffer[i] == '\n')
            break ;
    if (i < *buffer_pos)
    {
        i++;
        temp = my_strnjoin(*line, buffer, i);
        free(*line);
        *line = temp;
        ft_memmove(buffer, buffer + i, *buffer_pos - i);
        *buffer_pos -= i;
        return (1);
    }
    else
    {
        temp = my_strnjoin(*line, buffer, *buffer_pos);
        free(*line);
        *line = temp;
        *buffer_pos = 0;
        return (0);
    }
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static unsigned int buffer_pos = 0;
    char *  res;

    res = (char *)malloc(sizeof(char) * 1);
    if (!res)
        return (NULL);
    res[0] = 0;
    if (buffer_pos > 0 && move_check_buffer(buffer, &buffer_pos, &res))
        return (res);
    buffer_pos = read(fd, buffer, BUFFER_SIZE);
    while (buffer_pos > 0)
    {
        if (move_check_buffer(buffer, &buffer_pos, &res))
            return (res);
        buffer_pos = read(fd, buffer, BUFFER_SIZE);
    }
    if (res[0])
        return (res);
    free(res);
    return (NULL);
}
