#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"
# include "fcntl.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char *ft_strjoin(char *,char *);
int ft_strlen(char *);
char *ft_strchr(char *, int );

#endif
