#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
		i++;
	return (i);
}

char *ft_strchr(char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return (s);
	return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	x;
	int	temp;
	char *str;

	if (!s1)
		return (NULL);
	if (!s2)
		return (s1);
	x = ft_strlen(s1);
	temp = ft_strlen(s2);
	str = malloc((x + temp + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while(x > i)
		str[i++] = *s1++;
	i = 0;
	while(temp > i)
		str[x + i++] = *s2++;
	str[x + i] = '\0';
	return (str);
}
