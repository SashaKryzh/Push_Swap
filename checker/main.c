/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:45:58 by okryzhan          #+#    #+#             */
/*   Updated: 2019/01/31 17:45:59 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_func(void)
{
	ft_putstr("Error\n");
	system("leaks checker"); //
	exit(1);
}

void	dump_stacks(t_stack *a, t_stack *b, char *op)
{
	if (op)
		ft_printf("Exec %s\n", op);
	else
		ft_putstr("Initial state\n");
	while (a || b)
	{
		if (a)
			ft_printf("%3d", a->v);
		if (b)
			ft_printf("%*d", a ? 4 : 7, b->v);
		a = a ? a->next : a;
		b = b ? b->next : b;
		write(1, "\n", 1);
	}
	ft_putstr("___ ___\n a   b \n\n");
}

int		main(int ac, char *av[])
{
	t_stack	*a;
	t_stack *b;
	t_instr	*lst;

	get_data(&a, ac, av);
	get_commands(&lst);
	dump_stacks(a, NULL, NULL); //
	execute(&a, &b, lst);
	check_res(a, b);
	return (0);
}
