/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgreenpo <cgreenpo@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:31:48 by cgreenpo          #+#    #+#             */
/*   Updated: 2022/02/19 12:56:46 by cgreenpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_check(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' ')
	{
		if (s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_arrchr(int *arr, int num)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	parse_str(int **arr, char *arv)
{
	int			i;
	int			j;
	long		nb;

	i = 0;
	j = 0;
	*arr = malloc(sizeof(int));
	if (!*arr)
		return (0);
	while (arv[i])
	{
		while (arv[i] == ' ')
			++i;
		if (arv[i] > '9' && arv[i] != ' ')
			return (0);
		if (!ft_atoi_indx(arv, &nb, &i))
			return (0);
		if (ft_arrchr(*arr, nb))
			return (0);
		(*arr)[j] = nb;
		++j;
	}
	return (j);
}

int	parse_multpl(int **arr, char **arv, int size)
{
	long	nb;
	int		index;

	index = 0;
	*arr = malloc(sizeof(int) * size);
	if (!*arr)
		return (0);
	while (index < size)
	{
		if (!arg_check(arv[index]))
			return (0);
		if (!ft_atoi(arv[index], &nb))
			return (0);
		if (ft_arrchr(*arr, nb))
			return (0);
		(*arr)[index] = nb;
		++index;
	}
	return (size);
}

int	init_stack(t_stack *st, int size, int *tab)
{
	struct s_frame	*tm;

	st->size = 0;
	if (!tab)
		return (0);
	st->head = new_frm(*tab);
	if (!st->head)
		return (0);
	st->tail = st->head;
	while (++st->size < size)
	{
		tm = new_frm(tab[st->size]);
		if (!tm)
			return (free_stack(st));
		tm->prev = st->tail;
		(st->tail)->next = tm;
		st->tail = tm;
	}
	(st->tail)->next = st->head;
	(st->head)->prev = st->tail;
	return (1);
}
