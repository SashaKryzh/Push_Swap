/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:25:52 by okryzhan          #+#    #+#             */
/*   Updated: 2019/02/06 14:25:52 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		cnt_ints(t_stack *s)
{
	int cnt;

	cnt = 0;
	while (s)
	{
		cnt++;
		s = s->next;
	}
	return (cnt);
}

static int	middle(t_stack *s)
{
	int		max;
	int		min;

	min = INT_MAX;
	max = INT_MIN;
	while (s)
	{
		min = s->v < min ? s->v : min;
		max = s->v > max ? s->v : max;
		s = s->next;
	}
	return ((min + max) / 2);
}

int			get_medium(t_stack *s)
{
	int	dif;
	int	med;
	int	res;

	med = middle(s);
	dif = ft_abs(med - s->v);
	res = s->v;
	while (s)
	{
		if (ft_abs(med - s->v) < dif)
		{
			dif = ft_abs(med - s->v);
			res = s->v;
		}
		s = s->next;
	}
	return (res);
}
