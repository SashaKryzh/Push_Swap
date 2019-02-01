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
	system("leaks checker");
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

void	check_op(char *s)
{
	if (ft_strequ(s, "sa"))
		return ;
	if (ft_strequ(s, "sb"))
		return ;
	if (ft_strequ(s, "ss"))
		return ;
	if (ft_strequ(s, "pa"))
		return ;
	if (ft_strequ(s, "pb"))
		return ;
	if (ft_strequ(s, "ra"))
		return ;
	if (ft_strequ(s, "rb"))
		return ;
	if (ft_strequ(s, "rr"))
		return ;
	if (ft_strequ(s, "rra"))
		return ;
	if (ft_strequ(s, "rrb"))
		return ;
	if (ft_strequ(s, "rrr"))
		return ;
	exit_func();
}

t_instr	*new_instr(char *op)
{
	t_instr *new;

	new = (t_instr *)ft_memalloc(sizeof(t_instr));
	new->op = op;
	return (new);
}

void	add_op(t_instr **lst, char *op)
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
	char	*s;
	int		ret;

	*lst = NULL;
	while ((ret = get_next_line(0, &s)) > 0)
	{
		if (ret != 2)
			exit_func();
		check_op(s);
		add_op(lst, s);
	}
}

void	s_op(t_stack **top)
{
	t_stack *second;

	if (!*top || !(*top)->next)
		return ;
	second = (*top)->next;
	(*top)->next = second->next;
	second->next = (*top);
	*top = second;
}

void	p_op(t_stack **to, t_stack **from)
{
	t_stack *elem;

	if (!*from)
		return ;
	elem = *from;
	*from = (*from)->next;
	elem->next = *to;
	*to = elem;
}

void	r_op(t_stack **top)
{
	t_stack	*tmp;
	t_stack	*shift;

	if (!*top || !(*top)->next)
		return ;
	shift = *top;
	*top = (*top)->next;
	shift->next = NULL;
	tmp = *top;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = shift;
}

void	rr_op(t_stack **top)
{
	t_stack *tmp;
	t_stack	*shift;

	if (!*top || !(*top)->next)
		return ;
	tmp = (*top);
	while (tmp->next->next)
		tmp = tmp->next;
	shift = tmp->next;
	tmp->next = NULL;
	shift->next = *top;
	*top = shift;
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

void	check_rr(t_stack **a, t_stack **b, t_instr *op)
{
	if (op->op[2] != 'r')
		rr_op(op->op[2] == 'a' ? a : b);
	else
	{
		rr_op(a);
		rr_op(b);
	}
}

void	execute(t_stack **a, t_stack **b, t_instr *op)
{
	*b = NULL;
	while (op)
	{
		if (op->op[0] == 's' && op->op[1] != 's')
			s_op(op->op[1] == 'a' ? a : b);
		else if (op->op[0] == 'p')
			p_op(op->op[1] == 'a' ? a : b, op->op[1] == 'a' ? b : a);
		else if (op->op[0] == 'r' && op->op[1] != 'r')
			r_op(op->op[1] == 'a' ? a : b);
		else if (op->op[0] == 's' && op->op[1] == 's')
		{
			s_op(a);
			s_op(b);
		}
		else if (op->op[0] == 'r' && op->op[1] == 'r' && op->op[2] == '\0')
		{
			r_op(a);
			r_op(b);
		}
		else
			check_rr(a, b, op);
		dump_stacks(*a, *b, op->op);
		op = op->next;
	}
}

void	check_res(t_stack *a, t_stack *b)
{
	int check;

	if (b)
	{
		ft_putstr("KO\n");
		exit(0);
	}
	if (!a->next)
	{
		ft_putstr("OK\n");
		exit(0);
	}
	check = a->v > a->next->v;
	while (a->next)
	{
		if (a->v > a->next->v != check)
		{
			ft_putstr("KO\n");
			exit(1);
		}
		a = a->next;
	}
	ft_putstr("OK\n");
	exit(0);
}

int		main(int ac, char *av[])
{
	t_stack	*a;
	t_stack *b;
	t_instr	*lst;

	get_data(&a, ac, av);
	get_commands(&lst);
	dump_stacks(a, NULL, NULL);
	execute(&a, &b, lst);
	check_res(a, b);
	system("leaks checker");
	return (0);
}
