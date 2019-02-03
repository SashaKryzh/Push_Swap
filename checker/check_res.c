/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 11:24:57 by okryzhan          #+#    #+#             */
/*   Updated: 2019/02/03 11:24:57 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		show_res(char *s)
{
	ft_putendl(s);
	system("leaks checker"); //
	exit(0);
}

void			check_res(t_stack *a, t_stack *b)
{
	int check;

	if (b)
		show_res("KO");
	if (!a->next)
		show_res("OK");
	check = a->v > a->next->v;
	while (a->next)
	{
		if (a->v > a->next->v != check)
			show_res("KO");
		a = a->next;
	}
	show_res("OK");
}
