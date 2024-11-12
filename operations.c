/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgreenpo <cgreenpo@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:54:18 by cgreenpo          #+#    #+#             */
/*   Updated: 2023/07/16 13:58:43 by cgreenpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_count	getmin(t_stack **st)
{
	int				i;
	int				n;
	int				min_indx;
	// struct s_frame	*tm;
	struct s_count	res;

	i = 0;
	n = 0;
	// tm = st[1]->head;
	min_indx = count_lite(st, i);
	while (i < st[1]->size)
	{
		if (count_lite(st, i) < min_indx)
		{
			min_indx = count_lite(st, i);
			n = i;
		}
		i++;
	}
	count(st, &res, n);
	return (res);
}

void	if_back(struct s_count *res, t_stack **st)
{
	if ((*res).rot_b_b > (*res).rot_a_b)
	{
		(*res).which_st = 1;
		if_both(*res, (*res).rot_b_b, (*res).rot_a_b, st);
	}
	else
	{	
		(*res).which_st = 0;
		if_both(*res, (*res).rot_a_b, (*res).rot_b_b, st);
	}
}

void	if_forward(struct s_count *res, t_stack **st)
{
	if ((*res).rot_b > (*res).rot_a)
	{
		(*res).which_st = 1;
		if_both(*res, (*res).rot_b, (*res).rot_a, st);
	}
	else
	{
		(*res).which_st = 0;
		if_both(*res, (*res).rot_a, (*res).rot_b, st);
	}
}

void	if_both(struct s_count res, int big, int small, t_stack **st)
{
	int	j;

	j = big - small;
	res.op_lt = res.which_st + 97;
	while (small--)
	{
		if (!res.back_b && !res.back_a)
			rr(st);
		else
			rrr(st);
	}
	while (j--)
	{
		if (!res.back_b && !res.back_a)
		{
			rx(st[res.which_st], res.op_lt);
		}
		else
		{
			rrx(st[res.which_st], res.op_lt);
		}
	}
}

void	if_diff(struct s_count res, t_stack **st)
{
	if (res.back_b)
	{
		while (res.rot_b_b--)
			rrx(st[1], 'b');
	}
	else
	{
		while (res.rot_b--)
			rx(st[1], 'b');
	}
	if (res.back_a)
	{
		while (res.rot_a_b--)
			rrx(st[0], 'a');
	}
	else
	{
		while (res.rot_a--)
			rx(st[0], 'a');
	}
}
