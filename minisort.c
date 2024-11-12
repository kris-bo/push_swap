/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgreenpo <cgreenpo@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:06:29 by cgreenpo          #+#    #+#             */
/*   Updated: 2022/03/04 11:26:37 by cgreenpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *st)
{
	struct s_frame	*tm;
	int				i;
	int				ret;
	int				min_num;

	ret = 0;
	i = 0;
	tm = st->head;
	min_num = tm->item;
	while (++i < st->size)
	{
		if (min_num > (tm->next)->item)
		{
			min_num = (tm->next)->item;
			ret = i;
		}
		tm = tm->next;
	}
	return (ret);
}

void	two(t_stack *st)
{
	if ((st->head->next)->item < (st->head)->item)
		sx(st, "sa\n");
}

void	three(t_stack *st)
{
	int	min_num;

	min_num = find_min(st);
	if (min_num == 1)
	{
		if ((st->tail)->item < (st->head)->item)
			rx(st, 'a');
		else
			sx(st, "sa\n");
	}
	else if (min_num == 0)
	{
		sx(st, "sa\n");
		rx(st, 'a');
	}
	else
	{
		two(st);
		rrx(st, 'a');
	}
}

void	four(t_stack **st)
{
	int	min_num;

	min_num = find_min(st[0]);
	if (min_num == 3)
		rrx(st[0], 'a');
	else if (min_num == 2)
	{
		rx(st[0], 'a');
		rx(st[0], 'a');
	}
	else if (min_num == 1)
		sx(st[0], "sa\n");
	if (!is_sorted(st[0]))
		px(st, "pb\n");
	else
		return ;
	three(st[0]);
	px(st, "pa\n");
}

void	five(t_stack **st)
{
	int	min_num;

	min_num = find_min(st[0]);
	if (min_num == 4)
		rrx(st[0], 'a');
	else if (min_num == 3)
	{
		rrx(st[0], 'a');
		rrx(st[0], 'a');
	}
	else if (min_num == 2)
	{
		rx(st[0], 'a');
		rx(st[0], 'a');
	}
	else if (min_num == 1)
		sx(st[0], "sa\n");
	if (!is_sorted(st[0]))
		px(st, "pb\n");
	else
		return ;
	four(st);
	px(st, "pa\n");
}
