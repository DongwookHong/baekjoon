#include <stdio.h>


char	*ft_strchr(const char *s, int c)
{
	char	find;

	find = (char)c;
	while (*s && *s != find)
		s++;
	if (*s == find)
		return ((char *)s);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*dest;

	if (start > ft_strlen(s))
		size = 0;
	else if (len > ft_strlen(s + start))
		size = ft_strlen(s + start);
	else
		size = len;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (0);
	i = 0;
	if (size)
		while (i < len && s[start])
			dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}


#include "get_next_line.h"

#define BUFFERSIZE 3
#include <stdio.h>
char	*get_next_line(int fd)
{
    printf("GNL function start\n");
    char buffer[BUFFERSIZE + 1];
    static char *where;
    int count;

    if (fd < 0)
        return (NULL);
    if (where == NULL)
    {
        where = malloc(BUFFERSIZE + 1);
        if (where == NULL)
            return (NULL);
        where[0] = '\0';
    }
    while ((count = read(fd, buffer, BUFFERSIZE)) > 0)
    {
        printf("GNL while start\n");
        buffer[count] = '\0';
        where = ft_strjoin(where, buffer);
        if (ft_strchr(where, '\n'))
        {
            where = ft_substr(where,ft_strchr(where, '\n'), ft_strlen_d(where));
            return (ft_substr(where, 0, ft_strchr(where, '\n')));
        }
    }
    return (where);
}

#include <stdio.h>
int main()
{
    int fd;
    char *str;

    fd = open("lkc.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    while ((str = get_next_line(fd)) != NULL)
    {
        printf("==== main while start ====\n");
        printf("%s", str);
        free(str);
    }

    return (0);
}