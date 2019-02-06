/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 11:22:21 by okryzhan          #+#    #+#             */
/*   Updated: 2019/02/03 11:22:21 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
