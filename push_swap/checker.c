/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:35:51 by tdi-leo           #+#    #+#             */
/*   Updated: 2022/04/01 17:10:55 by tdi-leo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	ft_keepparsing(char *instruction, int *answer)
{
	if (ft_compare(instruction, "rb\n") == 1)
		answer[0] = 7;
	if (ft_compare(instruction, "rr\n") == 1)
		answer[0] = 8;
	if (ft_compare(instruction, "rra\n") == 1)
		answer[0] = 9;
	if (ft_compare(instruction, "rrb\n") == 1)
		answer[0] = 10;
	if (ft_compare(instruction, "rrr\n") == 1)
		answer[0] = 11;
}

int	ft_parser(char *instruction)
{
	int	answer;

	answer = 0;
	if (ft_compare(instruction, "sa\n") == 1)
		answer = 1;
	if (ft_compare(instruction, "sb\n") == 1)
		answer = 2;
	if (ft_compare(instruction, "ss\n") == 1)
		answer = 3;
	if (ft_compare(instruction, "pa\n") == 1)
		answer = 4;
	if (ft_compare(instruction, "pb\n") == 1)
		answer = 5;
	if (ft_compare(instruction, "ra\n") == 1)
		answer = 6;
	ft_keepparsing(instruction, &answer);
	return (answer);
}

void	ft_keepchecking(t_mem *mem, char what)
{
	if (what == 6)
		ft_rab(mem, 'a', 0);
	if (what == 7)
		ft_rab(mem, 'b', 0);
	if (what == 8)
		ft_rr(mem);
	if (what == 9)
		ft_rrab(mem, 'a', 0);
	if (what == 10)
		ft_rrab(mem, 'b', 0);
	if (what == 11)
		ft_rrr(mem);
}

void	ft_checkit(t_mem *mem, char *instruction)
{
	int	what;

	what = ft_parser(instruction);
	if (what == 0)
		ft_error(mem);
	if (what == 1)
		ft_sab(mem, 'a', 0);
	if (what == 2)
		ft_sab(mem, 'b', 0);
	if (what == 3)
		ft_ss(mem);
	if (what == 4)
		ft_pab(mem, 'a');
	if (what == 5)
		ft_pab(mem, 'b');
	ft_keepchecking(mem, what);
}

int	main(int pippo, char **topo)
{
	t_mem	mem;

	if (pippo < 2)
		return (0);
	if (ft_checkerstarter(&mem, pippo, topo) == 0)
		return (0);
	mem.comb = NULL;
	mem.instruction = get_next_line(0);
	while ((mem.instruction != NULL && *mem.instruction != 10))
	{
		ft_checkit(&mem, mem.instruction);
		free(mem.instruction);
		mem.instruction = get_next_line(0);
	}
	if (mem.instruction)
		if (*mem.instruction == 10)
			ft_error(&mem);
	if (ft_finalcheck(&mem, 'a') == 1 && mem.lenb == 0)
		write(1, "OK\n", 3);
	else
		ft_ko(&mem);
	ft_freeall(&mem);
	return (0);
}
