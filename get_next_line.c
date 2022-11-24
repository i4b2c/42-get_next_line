#include "get_next_line.h"

char	*get_line(char *str)
{
	int i;
	char *line;

	i = 0;
	while(str[i] != '\n' && str[i])
		i++;
	line = malloc(sizeof(char) * (i + 1));
	line[i] = '\0';
	i--;
	while(i >= 0)
	{
		line[i] = str[i];
		i--;
	}
	return (line);
}

char	*get_new_str(char *str)
{
	int i;
	int k;
	char *new_str;

	i = 0;
	while(str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	new_str = malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!new_str)
		return (0);
	i++;
	k = 0;
	while(str[k])
		new_str[k++] = str[i++];
	new_str[k] = '\0';
	free(str);
	return(new_str);
}

char 	*get_str(int fd, char *str)
{
	char *buf;
	int r_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	r_bytes = 1;
	while(r_bytes != 0 && !ft_strchr(str,'\n'))
	{
		r_bytes = read(fd,buf,BUFFER_SIZE);
		if (r_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[r_bytes] = '\0';
		str = ft_strjoin(str,buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char *str;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = get_str(fd,str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = get_new_str(str);
	return (line);
}
/*
int main(void) // ver melhor o main disto
{
	int fd;

	fd = open("teste.txt",O_RDONLY);
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	return 0;
}*/
