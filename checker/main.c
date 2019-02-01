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

t_stack	*new_elem(int n, t_stack *prev)
{
	t_stack *new;

	new = ft_memalloc(sizeof(t_stack));
	new->v = n;
	new->prev = prev;
	return (new);
}

void	add_elem(t_stack **a, int n)
{
	t_stack *tmp;

	if (!*a)
		*a = new_elem(n, NULL);
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
		tmp->next = new_elem(n, tmp);
	}
}

int		get_num(char **s)
{
	long	n;
	int		sign;

	n = 0;
	sign = **s == '-' ? -1 : 1;
	*s += **s == '+' || **s == '-' ? 1 : 0;
	while (ft_isdigit(**s))
	{
		n = n * 10 + **s - '0';
		if ((n > INT_MAX && sign) || (n < INT_MIN && sign < 0))
			exit_func();
		*s += 1;
	}
	if ((**s && !ft_isspace(**s)) || !ft_isdigit((*s)[-1]))
		exit_func();
	return (n * sign);
}

void	manage_arg(t_stack **a, char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != '+' && *s != '-')
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

int		get_next_command(char *s)
{
	char	trash[10000];
	int		i;

	i = 0;
	while (read(0, &s[i], 1) && i < 4)
	{
		if (s[i] == '\n')
		{
			if (!i)
				exit_func();
			s[i] = '\0';
			return (1);
		}
		i++;
	}
	if (i > 0)
	{
		read(0, &trash, 10000);
		exit_func();
	}
	return (0);
}

int		check_op(char *s)
{
	if (ft_strequ(s, "sa"))
		return (sa);
	if (ft_strequ(s, "sb"))
		return (sb);
	if (ft_strequ(s, "ss"))
		return (ss);
	if (ft_strequ(s, "pa"))
		return (pa);
	if (ft_strequ(s, "pb"))
		return (pb);
	if (ft_strequ(s, "ra"))
		return (ra);
	if (ft_strequ(s, "rb"))
		return (rb);
	if (ft_strequ(s, "rr"))
		return (rr);
	if (ft_strequ(s, "rra"))
		return (rra);
	if (ft_strequ(s, "rrb"))
		return (rrb);
	if (ft_strequ(s, "rrr"))
		return (rrr);
	else
		exit_func();
	return (-1);
}

t_instr	*new_instr(int op)
{
	t_instr *new;

	new = (t_instr *)ft_memalloc(sizeof(t_instr));
	new->op = op;
	return (new);
}

void	add_op(t_instr **lst, int op)
{
	t_instr *tmp;

	if (!*lst)
		*lst = new_instr(op);
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_instr(op);
	}
}

void	get_commands(t_instr **lst)
{
	char	s[4];
	int		op;

	*lst = NULL;
	while (get_next_command((char *)&s))
	{
		op = check_op((char *)&s);
		add_op(lst, op);
	}
}

int		main(int ac, char *av[])
{
	t_stack	*a;
	t_instr	*lst;

	get_data(&a, ac, av);
	get_commands(&lst);
	ft_printf("\n");
	t_stack *tmp;
	t_instr *tmp2;
	tmp = a;
	tmp2 = lst;
	while (tmp)
	{
		ft_printf("%d\n", tmp->v);
		tmp = tmp->next;
	}
	ft_printf("\n");
	while (tmp2)
	{
		ft_printf("%d\n", tmp2->op);
		tmp2 = tmp2->next;
	}
	return (0);
}
