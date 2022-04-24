/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:04:28 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/02/01 21:37:04 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*next_line(char **memory);
int		checkmem(char *str3);
char	*createmem(char **str1, char *str2);
size_t	len(char *str);
void	creatememutils(char **str1, char *str2, char *swap, size_t b);
void	nextlineutils(char **memory, char *line, size_t *a, size_t *b);
void	nextlinechecks(char *rest, char **memory);
int		gnlsplitter1(int x, char *buffer, char **memory, int fd);
int		gnlsplitter2(char *line, char *buffer);
#endif
