/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaldas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:37:15 by icaldas           #+#    #+#             */
/*   Updated: 2022/11/25 12:28:17 by icaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"
# include "fcntl.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

char	*ft_strjoin(char *x, char *y);
int		ft_strlen(char *x);
char	*ft_strchr(char *x, int y);
char	*get_next_line(int x);
char	*get_str(int x, char *y);
char	*get_new_str(char *x);
char	*get_line(char *x);

#endif
