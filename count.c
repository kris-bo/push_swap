/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgreenpo <cgreenpo@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:55:16 by cgreenpo          #+#    #+#             */
/*   Updated: 2024/09/14 11:38:45 by cgreenpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	basic_count(struct s_count *res, int i, t_stack **st)
{
	struct s_frame	*tm;
	struct s_frame	*this;

	(*res).rot_b = i;
	(*res).rot_b_b = st[1]->size - i;
	if (i > (st[1]->size / 2))
		(*res).back_b = 1;
	this = st[1]->head;
	while (i > 0)
	{
		this = this->next;
		i--;
	}
	tm = st[0]->head;
	while (i < st[0]->size)
	{
		if (this->item < tm->item && this->item > (tm->prev)->item)
			break ;
		i++;
		tm = tm->next;
	}
	(*res).rot_a = i;
	(*res).rot_a_b = st[0]->size - i;
	if (i > (st[0]->size / 2))
		(*res).back_a = 1;
}

void	count(t_stack **st, struct s_count *res, int i)
{
	int	*options;
	// int	n;

	(*res).back_a = 0;
	(*res).back_b = 0;
	// n = 0;
	options = malloc(sizeof(int) * 3);
	basic_count(res, i, st);
	if ((!(*res).back_a && !(*res).back_b) || ((*res).back_a && (*res).back_b))
		i = 0;
	// else
	// 	n = best_option(res, &options);
	free(options);
}

int	count_lite(t_stack **st, int i)
{
	struct s_count	res;
	int				rtrn;
	int				*options;
	int				n;

	options = malloc(sizeof(int) * 3);
	res.back_a = 0;
	res.back_b = 0;
	basic_count(&res, i, st);
	if ((!res.back_a && !res.back_b) || (res.back_a && res.back_b))
		rtrn = assign_rtrn(res);
	else
	{
		n = best_option(&res, &options);
		rtrn = options[n];
	}
	free(options);
	return (rtrn);
}
