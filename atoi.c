/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgreenpo <cgreenpo@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:52:21 by cgreenpo          #+#    #+#             */
/*   Updated: 2022/02/19 12:54:06 by cgreenpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_atoi(long num, char sign)
{
	if (sign == 'p')
	{
		if (num >= 2147483648)
			return (0);
	}
	else
	{
		if (num <= -2147483649)
			return (0);
	}
	return (1);
}

int	ft_atoi_indx(const char *s, long *num, int *i)
{
	unsigned int	tm;

	*num = 0;
	if (s[*i] == '-')
	{
		while (1)
		{
			tm = (unsigned)((s[++*i]) - '0');
			if (tm > 9)
				break ;
			*num = *num * 10 - tm;
		}
		return (check_atoi(*num, 'n'));
	}
	while (1)
	{
		tm = (unsigned)((s[*i]) - '0');
		if (tm > 9)
			break ;
		*num = *num * 10 + tm;
		++*i;
	}
	return (check_atoi(*num, 'p'));
}

int	ft_atoi(const char *s, long *num)
{
	unsigned int	tm;

	*num = 0;
	if (*s == '-')
	{
		while (1)
		{
			tm = (unsigned)((*++s) - '0');
			if (tm > 9)
				break ;
			*num = *num * 10 - tm;
		}
		return (check_atoi(*num, 'n'));
	}
	while (1)
	{
		tm = ((unsigned)(*s++) - '0');
		if (tm > 9)
			break ;
		*num = *num * 10 + tm;
	}
	return (check_atoi(*num, 'p'));
}
