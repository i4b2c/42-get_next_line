/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaldas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:35:37 by icaldas           #+#    #+#             */
/*   Updated: 2022/11/25 12:35:39 by icaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_new_str(char *str)
{
	int		i;
	int		k;
	char	*new_str;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_str = malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i++;
	k = 0;
	while (str[i] != '\0')
		new_str[k++] = str[i++];
	new_str[k] = '\0';
	free(str);
	return (new_str);
}

char	*get_str(int fd, char *str)
{
	char	*buf;
	int		r_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	r_bytes = 1;
	while (r_bytes != 0 && !ft_strchr(str, '\n'))
	{
		r_bytes = read(fd, buf, BUFFER_SIZE);
		if (r_bytes == -1)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[r_bytes] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4095)
		return (NULL);
	str[fd] = get_str(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = get_line(str[fd]);
	str[fd] = get_new_str(str[fd]);
	return (line);
}
/*
int main(void) // ver melhor o main disto
{
	int fd;
	char *str;

	fd = open("teste.txt",O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n",str);
	free(str);
	close(fd);
	return 0;
}*/
