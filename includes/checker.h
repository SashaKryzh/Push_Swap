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

#endif
