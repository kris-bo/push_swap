/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgreenpo <cgreenpo@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:54:39 by cgreenpo          #+#    #+#             */
/*   Updated: 2022/02/19 12:55:40 by cgreenpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_frame	*new_frm(int item)
{
	struct s_frame	*new;

	new = malloc(sizeof(struct s_frame));
	if (!new)
		return (NULL);
	new->item = item;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

int	free_stack(t_stack *st)
{
	struct s_frame	*nxt;
	struct s_frame	*tmp;

	tmp = st->head;
	while (st->size--)
	{
		nxt = tmp->next;
		free(tmp);
		tmp = nxt;
	}
	return (0);
}

int	free_all(t_stack **st, int *array)
{
	free_stack(st[0]);
	free_stack(st[1]);
	free(array);
	return (0);
}
