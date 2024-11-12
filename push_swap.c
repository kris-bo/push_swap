/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgreenpo <cgreenpo@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:20:45 by cgreenpo          #+#    #+#             */
/*   Updated: 2022/03/14 14:56:20 by cgreenpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize(int size, t_stack **st, int **array, char **arv)
{
	int	new_size;

	new_size = 0;
	if (size == 1)
		new_size = parse_str(array, *arv);
	else
		new_size = parse_multpl(array, arv, size);
	if (!new_size)
	{
		free(*array);
		write(1, "Error\n", 6);
		return (0);
	}
	if (!(init_stack(st[0], new_size, *array)))
	{
		free(*array);
		write(1, "Error\n", 6);
		return (0);
	}
	*array = pre_sort(*array, size);
	init_stack(st[1], 0, NULL);
	return (new_size);
}

void	first_push(int *data, int size, t_stack **st)
{
	struct s_frame	*tm;
	int				i;

	i = 0;
	while (i < size)
	{
		tm = st[0]->head;
		if (tm->item != data[0] && tm->item != data[size - 1])
		{
			px(st, "pb\n");
			if (tm->item < data[size / 2])
				rx(st[1], 'b');
		}
		else
			rx(st[0], 'a');
		i++;
	}
}

void	total_sort(t_stack **st)
{
	struct s_count	res;

	res = getmin(st);
	if (res.back_b && res.back_a)
		if_back(&res, st);
	else if (!res.back_b && !res.back_a)
		if_forward(&res, st);
	else
		if_diff(res, st);
}

void	final_rot(int *data, t_stack **st, int size)
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
	if (i <= (size / 2))
	{
		while (i--)
			rx(st[0], 'a');
	}
	else
	{
		i = size - i;
		while (i--)
			rrx(st[0], 'a');
	}
}

int	main(int arc, char **arv)
{
	t_stack			a;
	t_stack			b;
	t_stack			*st[2];
	int				*array;
	int				size;

	st[0] = &a;
	st[1] = &b;
	if (arc < 3)
		return (0);
	size = initialize(arc - 1, st, &array, arv + 1);
	if (!size)
		return (0);
	if (is_sorted(st[0]))
		return (free_all(st, array));
	if (size <= 5)
		return (minisort(st, array));
	first_push(array, size, st);
	while (st[1]->size > 0)
	{
		total_sort(st);
		px(st, "pa\n");
	}
	final_rot(array, st, size);
	return (free_all(st, array));
}
