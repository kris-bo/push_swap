/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgreenpo <cgreenpo@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:57:19 by cgreenpo          #+#    #+#             */
/*   Updated: 2022/02/22 10:28:59 by cgreenpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(t_stack **st, const char *out)
{
	int	to;
	int	from;

	to = out[1] - 'a';
	if (to == 1)
		from = 0;
	else
		from = 1;
	pop_and_push(st[to], st[from]);
	write(1, out, 3);
}

void	rx(t_stack *st, char w_st)
{
	h_to_t(st);
	if (w_st == 'a')
		write(1, "ra\n", 3);
	else if (w_st == 'b')
		write(1, "rb\n", 3);
}

void	rrx(t_stack *st, char w_st)
{
	t_to_h(st);
	if (w_st == 'a')
		write(1, "rra\n", 4);
	else if (w_st == 'b')
		write(1, "rrb\n", 4);
}

void	rr(t_stack **sts)
{
	h_to_t(sts[0]);
	h_to_t(sts[1]);
	write(1, "rr\n", 3);
}

void	rrr(t_stack **sts)
{
	t_to_h(sts[0]);
	t_to_h(sts[1]);
	write(1, "rrr\n", 4);
}
