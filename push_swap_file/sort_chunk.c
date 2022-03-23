/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:52:02 by lide              #+#    #+#             */
/*   Updated: 2022/03/23 17:23:55 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *list_b, long *sorted, long len, int swap)
{
	long	rotate;
	long	reverse;

	rotate = 0;
	reverse = 0;
	list_next(&list_b);
	if (swap)
		list_b = list_b->next->next;
	while (sorted[len] != (int)list_b->content)
	{
		list_b = list_b->next;
		rotate++;
	}
	list_before(&list_b);
	if (swap)
		list_b = list_b->next->next;
	while (sorted[len] != (int)list_b->content)
	{
		list_b = list_b->before;
		reverse++;
	}
	if (rotate < reverse)
		return (6);
	else
		return (7);
}

int	check_swap(t_list *list_b, long *sorted, long len, int mv)
{
	if (sorted[len] == (int)list_b->next->content)
	{
		if (sorted[len - 1] == (int)list_b->content)
			mv = 5;
	}
	return (mv);
}

void	move_rotate(t_list **list_b, long *sorted, int len, int mv)
{
	while ((int)(*list_b)->next->content != sorted[len])
	{
		rotate(list_b);
		write_mv(mv);
	}
	mv = check_swap(*list_b, sorted, len, mv);
	if (mv == 5)
		swap(list_b);
	else
		rotate(list_b);
	write_mv(mv);
}

void	sort_chunk(t_list **list_a, t_list **list_b, long *sorted)
{
	long	len;
	int		mv;

	len = long_len(sorted) - 1;
	while (len > -1)
	{
		mv = find_max(*list_b, sorted, len, 0);
		list_next(list_b);
		if (mv == 6)
			move_rotate(list_b, sorted, len, mv);
		else if (mv == 7)
		{
			while ((int)(*list_b)->content != sorted[len])
			{
				reverse_rotate(list_b);
				write_mv(mv);
			}
		}
		push(list_b, list_a);
		write (1, "pa\n", 3);
		len--;
	}
}
