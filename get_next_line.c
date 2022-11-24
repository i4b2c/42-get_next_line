#include "get_next_line.h"

char	*limpar(char *str)
{
	int i;
	int ct;
	int x;
	int i2;

	x = 0;
	i = ft_strlen(str);
	i2 = 0;
	ct = 0;
	while(str[i2] != '\0')
	{
		if (str[i2] == '\n')
			ct++;
		i2++;
	}	
	while(str[i] != '\n' || ct > x)
	{
		str[i--] = '\0';
		x++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char *str;
	char *arm;
	int b_read;

	b_read = 1;
	str = malloc(BUFFER_SIZE);
	while(b_read > 0 && !ft_strchr(str,'\n'))
	{
		b_read = read(fd,str,BUFFER_SIZE);
		arm = ft_strjoin(arm,str);
	}
	free(str);
	limpar(arm);
	return (arm);
}

int main(void)
{
	int fd;
	char *str;

	fd = open("teste.txt",O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n",str);
	return 0;
}
