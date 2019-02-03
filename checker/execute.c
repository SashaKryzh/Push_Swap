/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 11:21:54 by okryzhan          #+#    #+#             */
/*   Updated: 2019/02/03 11:21:54 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_r_rr(t_stack **a, t_stack **b, t_instr *op)
{
	if (op->op[0] == 'r' && op->op[1] == 'r' && op->op[2] == '\0')
	{
		r_op(a);
		r_op(b);
	}
	else if (op->op[2] != 'r')
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
		else
			check_r_rr(a, b, op);
		dump_stacks(*a, *b, op->op);
		op = op->next;
	}
}
