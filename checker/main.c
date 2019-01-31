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
	exit(1);
}

t_stack	*new_elem(int n)
{
	t_stack *new;

	new = ft_memalloc(sizeof(t_stack));
	new->v = n;
	return (new);
}

void	add_elem(t_stack **a, int n)
{
	t_stack *tmp;

	if (!*a)
		*a = new_elem(n);
	else
	{
		tmp = *a;
		while (tmp->next)
		{
			if (tmp->v == n)
				exit_func();
			tmp = tmp->next;
		}
		if (tmp->v == n)
			exit_func();
		tmp->next = new_elem(n);
	}
}

int		get_num(char **s)
{
	int n;

	n = 0;
	while (ft_isdigit(**s))
	{
		n = n * 10 + **s - '0';
		*s += 1;
	}
	return (n);
}

void	manage_arg(t_stack **a, char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
		{
			if (!ft_isspace(*s))
				exit_func();
		}
		else
			add_elem(a, get_num(&s));
		if (!*s)
			break ;
		s++;
	}
}

void	get_data(t_stack **a, int ac, char *av[])
{
	int i;

	if (ac == 1)
		exit(1);
	i = 1;
	*a = NULL;
	while (i < ac)
	{
		manage_arg(a, av[i]);
		i++;
	}
}

int		main(int ac, char *av[])
{
	t_stack	*a;

	get_data(&a, ac, av);
	t_stack *tmp;
	while (tmp)
	{
		ft_printf("%d\n", tmp->v);
		tmp = tmp->next;
	}
	return (0);
}
