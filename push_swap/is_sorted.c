/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:59:55 by okryzhan          #+#    #+#             */
/*   Updated: 2019/02/06 12:59:55 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *s)
{
	int check;

	if (!s->next)
		return (1);
	check = s->next->v > s->v;
	if (!check)
		return (0);
	while (s->next)
	{
		if (s->v > s->next->v != check)
			return (0);
		s = s->next;
	}
	return (1);
}
