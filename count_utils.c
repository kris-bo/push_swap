/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgreenpo <cgreenpo@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:59:16 by cgreenpo          #+#    #+#             */
/*   Updated: 2022/01/23 11:30:03 by cgreenpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findmin(int *array)
{
	int	min;
	int	i;

	i = 0;
	min = 0;
	while (i < 3)
	{
		if (array[i] < array[min])
			min = i;
		i++;
	}
	return (min);
}

void	manage_options(struct s_count *res, int i)
{
	if (i == 1)
	{
		(*res).back_a = 1;
		(*res).back_b = 1;
	}
	else if (i == 2)
	{
		(*res).back_a = 0;
		(*res).back_b = 0;
	}
}

int	best_option(struct s_count *res, int **options)
{
	int	i;

	if ((*res).back_a)
		(*options)[0] = (*res).rot_b + (*res).rot_a_b;
	else if ((*res).back_b)
		(*options)[0] = (*res).rot_a + (*res).rot_b_b;
	if ((*res).rot_a_b > (*res).rot_b_b)
		(*options)[1] = (*res).rot_a_b;
	else
		(*options)[1] = (*res).rot_b_b;
	if ((*res).rot_b > (*res).rot_a)
		(*options)[2] = (*res).rot_b;
	else
		(*options)[2] = (*res).rot_a;
	i = findmin(*options);
	manage_options(res, i);
	return (i);
}

int	assign_rtrn(struct s_count res)
{
	int		rtrn;

	if (!res.back_a && !res.back_b)
	{
		if (res.rot_a > res.rot_b)
			rtrn = res.rot_a;
		else
			rtrn = res.rot_b;
	}
	else
	{
		if (res.rot_a_b > res.rot_b_b)
			rtrn = res.rot_a_b;
		else
			rtrn = res.rot_b_b;
	}
	return (rtrn);
}
