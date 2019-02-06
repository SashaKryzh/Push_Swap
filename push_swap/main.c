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

int		get_medium(t_stack *s)
{
	int max;
	int min;

	min = INT_MAX;
	max = INT_MIN;
	while (s)
	{
		min = s->v < min ? s->v : min;
		max = s->v > max ? s->v : max;
		s = s->next;
	}
	return ((min + max) / 2);
}

void	sort(t_stack **a, t_stack **b)
{
	int m;

	m = get_medium(*a);
}

int		main(int ac, char *av[])
{
	t_stack	*a;
	t_stack *b;

	get_data(&a, ac, av);
	if (!is_sorted(a))
	{
		b = NULL;
		sort(&a, &b);
	}
	return (0);
}
