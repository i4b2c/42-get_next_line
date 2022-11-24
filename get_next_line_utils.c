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
	int i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if(s[i] == (char)c)
			return (s + i);
		i++;
	}
	return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int k;
	char *p;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if(!s2 || !s1)
		return (0);
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return 0;
	i = 0;
	if (s1)
		while (s1[i] != '\0')
		{
			p[i] = s1[i];
			i++;
		}
	k = 0;
	while (s2[k] != '\0')
		p[i++] = s2[k++];
	p[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (p);
}
