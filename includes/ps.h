/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:47:23 by okryzhan          #+#    #+#             */
/*   Updated: 2019/02/06 13:47:23 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft.h"

typedef struct	s_stack
{
	int				v;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

void			get_data(t_stack **a, int ac, char *av[]);

/*
**	Operations
*/

void			s_op(t_stack **top);
void			p_op(t_stack **to, t_stack **from);
void			r_op(t_stack **top);
void			rr_op(t_stack **top);

#endif
