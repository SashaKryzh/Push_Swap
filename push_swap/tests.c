
#include "push_swap.h"

void	dump_stacks(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (a)
			ft_printf("%10d", a->v);
		if (b)
		{
			ft_printf("%*d", a ? 15 : 25, b->v);
		}
		write(1, "\n", 1);
		a = a ? a->next : a;
		b = b ? b->next : b;
	}
	ft_printf("----------     ----------\n");
	ft_printf("     a              b\n");
}
