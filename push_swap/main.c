/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:10:59 by okryzhan          #+#    #+#             */
/*   Updated: 2019/01/31 18:10:59 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_func(void)
{
	ft_putstr("Error\n");
	// system("leaks push_swap"); //
	exit(1);
}

void	check_ints(t_stack **s, int acs)
{
	if ((*s)->next->v > (*s)->v == acs)
		s_op(s);
	else if (!acs)
		s_op(s);
}

void	qisort(t_stack **a, t_stack **b)
{
	int		med;
	int		cnt;

	med = get_medium(*a);
	// ft_printf("medium : %d\n", m); //
	cnt = cnt_ints(*a);
	if (cnt == 2)
		check_ints(a, ASC);
	while (cnt > 0)
	{
		if ((*a)->v < med)
		{
			p_op(b, a);
			cnt--;
		}
		cnt--;
	}
}

int		main(int ac, char *av[])
{
	t_stack	*a;
	t_stack *b;

	get_data(&a, ac, av);
	if (is_sorted(a) != ASC)
	{
		b = NULL;
		qisort(&a, &b);
	}
	return (0);
}
