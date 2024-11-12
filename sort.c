/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgreenpo <cgreenpo@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:13:48 by cgreenpo          #+#    #+#             */
/*   Updated: 2022/03/14 15:37:42 by cgreenpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minisort(t_stack **st, int *data)
{
	if (st[0]->size == 3)
	{
		return (microsort(data, st));
	}
	else
	{
		five(st);
		return (free_all(st, data));
	}
	return (0);
}

int	microsort(int *data, t_stack **st)
{
	int				i;
	struct s_frame	*tm;

	i = 0;
	tm = st[0]->head;
	while (tm->item != data[0])
	{
		tm = tm->next;
		i++;
	}
	if ((tm->prev)->item == data[1])
		sx(st[0], "sa\n");
	while ((st[0]->head)->item != data[0])
	{
		if (i == 1)
			rx(st[0], 'a');
		else
			rrx(st[0], 'a');
	}
	return (free_all(st, data));
}

int	*pre_sort(int *arr, int size)
{
	int	i;
	int	key;
	int	j;
	int	tmp;
	int	*array;

	array = arr;
	i = 1;
	while (i < size)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			tmp = array[j + 1];
			array[j + 1] = array[j];
			array[j] = tmp;
			j = j - 1;
		}
		array[j + 1] = key;
		i++;
	}
	return (array);
}

int	is_sorted(t_stack *st)
{
	struct s_frame	*tm;
	int				i;

	i = 0;
	if (st->size < 2)
		return (1);
	tm = st->head;
	while (++i < st->size)
	{
		if (tm->item > (tm->next)->item)
			return (0);
		tm = tm->next;
	}
	return (1);
}
