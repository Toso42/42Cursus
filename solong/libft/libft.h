/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:49:44 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/06/07 18:44:06 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
// get_next_line
size_t	len(char *str);
char	*createmem(char **str1, char *str2);
int		gnlsplitter2(char *line, char *buffer);
int		checkmem(char *str3);
int		gnlsplitter1(int x, char *buffer, char **memory, int fd);
void	nextlinechecks(char *rest, char **memory);
void	nextlineutils(char **memory, char *line, size_t *a, size_t *b);
void	creatememutils(char **str1, char *str2, char *swap, size_t b);
char	*get_next_line(int fd);
//printf
void	ft_printftypestring(va_list args, char *ss, int sum);
int		ft_printbits(int bits, int toprint);
int		ft_putchar(char c);
int		ft_putstring(char *astring, int Sum);
int		ft_putnmbu(unsigned int n, int Sum);
int		ft_putnmb(int n, int Sum);
int		ft_putnmbcx(unsigned int n, int Sum, char *base);
int		ft_putnmbx(unsigned int n, int Sum, char *base);
int		ft_putp(unsigned long long int n, int Sum, char *base);
int		ft_pad(unsigned long long int n, int Sum, char *base);
int		type(va_list args, const char *string, int Sum, int x);
int		ft_printf(const int mode, const char *string, ...);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(int flag, const char *s, char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f) (unsigned int, char*));
char	*ft_strjoin(int flag, char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
