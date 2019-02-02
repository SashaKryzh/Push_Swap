
#include "checker.h"

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
		if ((n > INT_MAX && sign) || n > ft_abs(INT_MIN))
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
