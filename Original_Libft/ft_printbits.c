#include "libft.h"

static void	ft_prepbits(int *toprint, int *recursion)
{
	if (toprint[0] * -1 > 0)
	{
		write (1, "1", 1);
		toprint[0] *= -1;
		recursion[0] += 1;
	}
}

void	ft_printbits(char type, int toprint)
{
	int			bits;
	static int	recursion;

	ft_prepbits(&toprint, &recursion);
	recursion++;
	if (type == 'i')
		bits = 32;
	if (type == 'c')
		bits = 8;
	if (toprint > 1)
        ft_printbits(type, toprint / 2);
	else
		while (recursion++ < (bits))
			write(1, "0", 1);
	recursion = 0;
	ft_printf("%d", toprint % 2);
}
/*
int main(void)
{
	int x;
	int y;;

	ft_printbits('i', 3982738);
	write(1, "\n", 1);
	ft_printbits('i', -3982738);
//	ft_printf("\n x = %d | y = %d", x, y);
}*/
