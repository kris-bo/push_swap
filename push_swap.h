/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgreenpo <cgreenpo@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:21:15 by cgreenpo          #+#    #+#             */
/*   Updated: 2022/03/04 11:08:36 by cgreenpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h> 
# include <stdio.h>

struct	s_count
{
	int		rot_b;
	int		rot_b_b;
	int		rot_a;
	int		rot_a_b;
	int		back_b;
	int		back_a;
	int		which_st;
	char	op_lt;
	int		rtrn;
};

struct s_frame
{
	struct s_frame	*next;
	struct s_frame	*prev;
	int				item;
};

typedef struct s_stack
{
	struct s_frame	*head;
	struct s_frame	*tail;
	int				size;
}				t_stack;

int				parse_multpl(int **array, char **av, const int size);
int				parse_str(int **array, char *av);
int				init_stack(t_stack *st, int size, int *tab);
int				ft_atoi(const char *s, long *num);
int				ft_atoi_indx(const char *s, long *num, int *i);
int				*pre_sort(int *array, int size);
int				is_sorted(t_stack *st);
int				free_stack(t_stack *st);
int				free_all(t_stack **st, int *array);
struct s_frame	*new_frm(int item);
int				microsort(int *data, t_stack **st);

void			px(t_stack **sts, const char *out);
void			px(t_stack **sts, const char *out);
void			rx(t_stack *st, char w_st);
void			rrx(t_stack *st, char w_st);
void			rr(t_stack **sts);
void			rrr(t_stack **sts);
void			sx(t_stack *st, char *out);

void			if_both(struct s_count res, int big, int small, t_stack **st);
void			if_diff(struct s_count res, t_stack **st);
void			if_back(struct s_count *res, t_stack **st);
void			if_forward(struct s_count *res, t_stack **st);
void			first_push(int *array, int size, t_stack **st);
void			final_rot(int *data, t_stack **st, int size);
void			big_sort(t_stack **st);
struct s_count	getmin(t_stack **st);

// count
void			basic_count(struct s_count *res, int i, t_stack **st);
void			count(t_stack **st, struct s_count *res, int i);
int				count_lite(t_stack **st, int i);

// count_utils
int				assign_rtrn(struct s_count res);
int				best_option(struct s_count *res, int **options);

void			pop_and_push(t_stack *to, t_stack *from);
void			h_to_t(t_stack *st);
void			t_to_h(t_stack *st);

int				minisort(t_stack **st, int *data);
int				microsort(int *data, t_stack **st);
void			five(t_stack **st);

#endif