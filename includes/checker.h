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

# include "libft.h"

typedef struct	s_stack
{
	int				v;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct	s_instr
{
	char			*op;
	struct s_instr	*next;
}				t_instr;

/*
**	Main
*/

void			get_data(t_stack **a, int ac, char *av[]);
void			get_commands(t_instr **lst);
void			execute(t_stack **a, t_stack **b, t_instr *op);
void			check_res(t_stack *a, t_stack *b);

/*
**	Operations
*/

void			s_op(t_stack **top);
void			p_op(t_stack **to, t_stack **from);
void			r_op(t_stack **top);
void			rr_op(t_stack **top);

/*
**	Utils
*/

void			exit_func(void);

/*
**	Tests
*/

void			dump_stacks(t_stack *a, t_stack *b, char *op);

#endif
