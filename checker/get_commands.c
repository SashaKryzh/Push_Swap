/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 11:22:00 by okryzhan          #+#    #+#             */
/*   Updated: 2019/02/03 11:22:00 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
