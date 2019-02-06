/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:40:07 by okryzhan          #+#    #+#             */
/*   Updated: 2019/01/31 18:40:07 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

# include "ps.h"

typedef struct	s_instr
{
	char			*op;
	struct s_instr	*next;
}				t_instr;

/*
**	Main
*/

void			get_commands(t_instr **lst);
void			execute(t_stack **a, t_stack **b, t_instr *op);
void			check_res(t_stack *a, t_stack *b);

/*
**	Utils
*/

void			exit_func(void);

/*
**	Tests
*/

void			dump_stacks(t_stack *a, t_stack *b, char *op);

#endif
