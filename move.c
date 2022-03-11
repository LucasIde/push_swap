/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:30:52 by lide              #+#    #+#             */
/*   Updated: 2022/03/11 19:00:41 by lide             ###   ########.fr       */
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

void	move(t_list *list_a, t_list *list_b, long *sorted)
{
	long	len;
	long	i;
	int		j;
	int		mv;

	len = long_len(sorted);
	len /= 2;
	j = 0;
	i = 0;
	while (sorted[i] < 2147483649)
	{
		while (j < len)
		{
			if (!in_list((int)list_a->content, sorted, 0, len))
			{
				mv = check_move(list_a, sorted, 0, len);
				// printf("\n|| mv  %d  mv ||\n", mv);
			}
			while (!in_list((int)list_a->content, sorted, 0, len))
			{
				if (mv == 1)
				{
					swap(&list_a);
					write (1, "sa\n", 3);
				}
				else if (mv == 2)
				{
					rotate(&list_a);
					write (1, "ra\n", 3);
				}
				else
				{
					reverse_rotate(&list_a);
					write (1, "rra\n", 4);
				}
				while (list_a->status != -1)
					list_a = list_a->next;
			}
			// printf("\n||%d||\n", (int)list_a->content);
			push(&list_a, &list_b);
			write (1, "pb\n", 3);
			j++;
		}
		i++;
	}


	printf("\n|%ld|\n", len);
	// push(&list_a, &list_b);
	// swap(&list_a);
	// rotate(&list_a);
	// reverse_rotate(&list_a);
	print(list_a, list_b);
}
