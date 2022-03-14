/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:30:52 by lide              #+#    #+#             */
/*   Updated: 2022/03/14 17:47:52 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **list)
{
	if (*list && (*list)->next != NULL)
	{
		while ((*list)->status != -1)
			*list = (*list)->next;
		(*list)->status = 1;
		(*list)->before->status = 0;
		(*list)->next->status = -1;
	}
}

void	reverse_rotate(t_list **list)
{
	if (*list && (*list)->next != NULL)
	{
		while ((*list)->status != -1)
			*list = (*list)->next;
		(*list)->status = 0;
		(*list)->before->status = -1;
		(*list)->before->before->status = 1;
	}
}

void	swap(t_list **first)
{
	t_list	*second;

	if (*first && (*first)->next != NULL)
	{
		while ((*first)->status != -1)
			*first = (*first)->next;
		second = (*first)->next;
		if ((*first)->next->status != (*first)->before->status)
		{
			(*first)->next = second->next;
			second->before = (*first)->before;
			second->before->next = second;
			(*first)->next->before = *first;
		}
		else
		{
			(*first)->next = second;
			second->before = *first;
		}
		(*first)->before = second;
		second->next = *first;
		(*first)->status = second->status;
		second->status = -1;
	}
}

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
		// printf("|%ld|\n", sorted[start]);
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

void	write_mv(int mv)
{
	if (mv == 1)
		write (1, "sa\n", 3);
	else if (mv == 2)
		write (1, "ra\n", 3);
	else if (mv == 3)
		write (1, "rra\n", 4);
}

void	chunk(t_list **list_a, t_list **list_b, long *sorted, t_move *mm)
{
	if (!in_list((int)(*list_a)->content, sorted, mm->min, mm->len))
	{
		mm->mv = check_move(*list_a, sorted, mm->min, mm->len);
		// printf("\n|| mv  %d  mv ||\n", mv);
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
	// printf("\n||%d||\n", (int)(*list_a)->content);
	push(list_a, list_b);
	write (1, "pb\n", 3);
}

void	move(t_list *list_a, t_list *list_b, long *sorted)
{
	t_move	mm;
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
			chunk(&list_a, &list_b, sorted, &mm);
			mm.i++;
		}
		mult++;
		mm.min = mm.splited * mult;
		mm.len = mm.splited * (mult + 1);
	}

	// printf("\n|yo mmi %ld|\n", mm.min);
	// printf("\n|yo maaax %d|\n", max);
	// printf("\n|%ld|\n", len);
	// push(&list_a, &list_b);
	// swap(&list_a);
	// rotate(&list_a);
	// reverse_rotate(&list_a);
	print(list_a);
	print(list_b);
}
