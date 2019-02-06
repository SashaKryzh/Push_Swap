/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 11:53:55 by okryzhan          #+#    #+#             */
/*   Updated: 2019/02/03 11:53:55 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include "ps.h"

# define ASC 1
# define DES 0
# define UNS -1

int		is_sorted(t_stack *s);
int		get_medium(t_stack *s);
int		cnt_ints(t_stack *s);

/*
**	Tests
*/

void	dump_stacks(t_stack *a, t_stack *b);

#endif
