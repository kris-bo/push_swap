/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgreenpo <cgreenpo@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:10:39 by cgreenpo          #+#    #+#             */
/*   Updated: 2022/02/22 10:32:18 by cgreenpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_and_push(t_stack *to, t_stack *from)
{
	struct s_frame	*tm;

	tm = from->head;
	from->head = tm->next;
	(from->head)->prev = from->tail;
	(from->tail)->next = from->head;
	--from->size;
	if (!to->size)
	{
		to->head = tm;
		(to->head)->prev = tm;
		(to->head)->next = tm;
		to->tail = to->head;
	}
	else
	{
		(to->head)->prev = tm;
		tm->next = to->head;
		tm->prev = to->tail;
		to->head = tm;
		(to->tail)->next = tm;
	}
	++to->size;
}

void	h_to_t(t_stack *st)
{
	st->tail = st->head;
	st->head = (st->tail)->next;
}

void	t_to_h(t_stack *st)
{
	st->head = st->tail;
	st->tail = (st->head)->prev;
}

void	swap(t_stack *stack)
{
	int	tm;

	tm = (stack->head)->item;
	(stack->head)->item = ((stack->head)->next)->item;
	((stack->head)->next)->item = tm;
}

void	sx(t_stack *st, char *out)
{
	swap(st);
	write(1, out, 3);
}
