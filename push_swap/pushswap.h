/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:45:02 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/04/01 17:04:55 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_memory
{
	char	*instruction;
	int		ras;
	int		rras;
	int		*store;
	int		*swap;
	int		**argfrom;
	int		**argto;
	int		**parg;
	int		*arg;
	int		*len;
	int		*pmax;
	int		*pmaxposition;
	int		*pmin;
	int		*pminposition;
	int		**table;
	int		oldtablesize;
	int		firstasize;
	int		execlen;
	int		**comb;
	int		lissize;
	int		lena;
	int		lenb;
	int		*a;
	int		*b;
	char	**args;
	int		max;
	int		max2;
	int		maxposition;
	int		max2position;
	int		min;
	int		min2;
	int		minposition;
	int		min2position;
	int		answerlen;
	char	*answer;
	int		lis;
	int		lislocation;
	int		rlis;
	int		rlislocation;
	int		maxlenposition;
	int		lismax;
	int		target;
	int		mincalc;
	int		minrow;
	char	**splittedargs;
	int		argsnumbers;
	int		pippo1;
}	t_mem;

void	ft_ko(t_mem *mem);
int		ft_compare(char *instruction, char *target);
int		ft_checkerstarter(t_mem *mem, int pippo, char **topo);
size_t	len(char *str);
char	*createmem(char **str1, char *str2);
int		checkmem(char *str3);
char	*next_line(char **memory);
void	creatememutils(char **str1, char *str2, char *swap, size_t b);
void	nextlineutils(char **memory, char *line, size_t *a, size_t *b);
void	nextlinechecks(char *rest, char **memory);
int		gnlsplitter1(int x, char *buffer, char **memory, int fd);
int		gnlsplitter2(char *line, char *buffer);
char	*get_next_line(int fd);
void	ft_five(t_mem *mem);
void	ft_five1(t_mem *mem);
void	ft_fiverra(t_mem *mem, int x);
void	ft_fivera(t_mem *mem, int x);
void	ft_three(t_mem *mem);
void	ft_firstliss(t_mem *mem);
void	ft_prep1(t_mem *mem);
void	ft_prep2(t_mem *mem);
void	ft_prep3(t_mem *mem);
int		ft_prep(t_mem *mem);
void	ft_addinitializer(t_mem *mem, char what);
void	ft_findmaxinitializer(t_mem *mem, char what);
void	ft_findmininitializer(t_mem *mem, char what);
int		ft_findincomb(t_mem *mem, int x);
void	ft_freetable(int **table, int size);
void	ft_pushswap(t_mem *mem);
void	ft_exec(t_mem *mem);
void	ft_findmintable(t_mem *mem);
void	ft_tablecalc2(t_mem *mem);
void	ft_tablecalc(t_mem *mem);
void	ft_createtable(t_mem *mem);
void	ft_tablecreator(t_mem *mem);
int		ft_atoi(t_mem *mem, char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	print(t_mem *mem, char what);
void	ft_answer(t_mem *mem, char *rule, int rulelen);
void	ft_flatit(t_mem *mem);
void	ft_freeargs(t_mem *mem);
void	ft_createstack(t_mem *mem, char what);
void	ft_printanswer(t_mem *mem);
int		ft_strlen(char *s);
char	*ft_substr(char *s, int start, int len);
char	**ft_split(t_mem *mem, char *s, char c);
void	ft_newa(t_mem *mem, int a);
void	ft_splitit(t_mem *mem, char *arg);
int		ft_createa(t_mem *mem, int pippo, char **topo);
void	ft_populatemem(t_mem *mem);
void	ft_freeall(t_mem *mem);
void	ft_newcomb(t_mem *mem, int **ar, int nb, int pos);
void	ft_newrow(t_mem *mem, int **ar, int nb, int pos);
void	ft_checkmiddle(int **ar, int nb, int pos);
void	ft_lis(t_mem *mem);
void	ft_rabsinitializer(t_mem *mem, char what);
void	ft_sab(t_mem *mem, char what, int mode);
void	ft_pab(t_mem *mem, char what);
void	ft_rab(t_mem *mem, char what, int mode);
void	ft_rrab(t_mem *mem, char what, int mode);
void	ft_add(t_mem *mem, char what);
void	ft_rem(t_mem *mem, char what);
void	ft_ss(t_mem *mem);
void	ft_rr(t_mem *mem);
void	ft_rrr(t_mem *mem);
int		ft_checkspace(char *string);
int		ft_checkargv(char *string);
int		ft_finalcheck(t_mem *mem, char what);
int		ft_checkrep(int what, int *in, int sizeofin);
int		ft_checkdoubles(t_mem *mem);
void	ft_nuller(int *a, int *b, int *c, int *d);
void	ft_findmax(t_mem *mem, char what);
void	ft_findmin(t_mem *mem, char what);
void	ft_findall(t_mem *mem);
void	ft_checkmalloc(t_mem *mem, void *ptr);
void	ft_error(t_mem *mem);
int		ft_fillraj0(t_mem *mem, int *i, int *j);
int		ft_fillraj1(t_mem *mem, int *i, int *j);
void	ft_fillra(t_mem *mem);
int		ft_fillrraj0(t_mem *mem, int *i, int *j, int *k);
int		ft_fillrraj1(t_mem *mem, int *i, int *j, int *k);
void	ft_fillrra(t_mem *mem);
void	ft_fillrrb(t_mem *mem);
void	ft_fillrb(t_mem *mem);

#endif
