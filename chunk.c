/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:17:48 by lide              #+#    #+#             */
/*   Updated: 2022/03/14 19:27:38 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	long_len(long *sorted)
{
	long	i;

	i = 0;
	while (sorted[i] < 2147483649)
		i++;
	return (i);
}

int	in_list(int content, long *sorted, int start, int end)
{
	while (start < end)
	{
		if (content == sorted[start])
			return (1);
		start++;
	}
	return (0);
}

int	check_move(t_list *list, long *sorted, int start, int end)
{
	int		rotate;
	int		reverse;

	rotate = 0;
	reverse = 0;
	while (list->status != -1)
		list = list->next;
	if (in_list((int)list->next->content, sorted, start, end))
		return (1);
	while (!in_list((int)list->content, sorted, start, end))
	{
		list = list->next;
		rotate++;
	}
	while (list->status != -1)
		list = list->before;
	while (!in_list((int)list->content, sorted, start, end))
	{
		list = list->before;
		reverse++;
	}
	if (rotate < reverse)
		return (2);
	else
		return (3);
}

void	chunk(t_list **list_a, t_list **list_b, long *sorted, t_move *mm)
{
	if (!in_list((int)(*list_a)->content, sorted, mm->min, mm->len))
	{
		mm->mv = check_move(*list_a, sorted, mm->min, mm->len);
	}
	while (!in_list((int)(*list_a)->content, sorted, mm->min, mm->len))
	{
		if (mm->mv == 1)
			swap(list_a);
		else if (mm->mv == 2)
			rotate(list_a);
		else
			reverse_rotate(list_a);
		while ((*list_a)->status != -1)
			*list_a = (*list_a)->next;
		write_mv(mm->mv);
	}
	push(list_a, list_b);
	write (1, "pb\n", 3);
}

void	move2(t_list **list_a, t_list **list_b, long *sorted)
{
	t_move		mm;
	static int	mult;

	mm.max = long_len(sorted);
	mm.splited = mm.max / 3;
	mm.min = 0;
	mm.len = mm.splited;
	while (mm.min < mm.max)
	{
		if (mm.len > mm.max)
			mm.len = mm.max;
		mm.i = mm.min;
		while (mm.i < mm.len)
		{
			chunk(list_a, list_b, sorted, &mm);
			mm.i++;
		}
		mult++;
		mm.min = mm.splited * mult;
		mm.len = mm.splited * (mult + 1);
	}
}
