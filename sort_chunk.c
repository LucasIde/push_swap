/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:52:02 by lide              #+#    #+#             */
/*   Updated: 2022/03/15 18:31:07 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list **list_b, long *sorted, long len)
{
	long	rotate;
	long	reverse;

	rotate = 0;
	reverse = 0;
	while ((*list_b)->status != -1)
		*list_b =(*list_b)->next;
	while (sorted[len] != (int)(*list_b)->content)
	{
		// printf("|yo|\n");
		printf("|sorted %ld|\n", sorted[len]);
		printf("|list %d|\n", (int)(*list_b)->content);
		*list_b =(*list_b)->next;
		rotate++;
	}
	while ((*list_b)->status != -1)
		*list_b =(*list_b)->before;
	while (sorted[len] != (int)(*list_b)->content)
	{
		*list_b =(*list_b)->before;
		reverse++;
	}
	if (rotate < reverse)
		return (6);
	else
		return (7);
}

int	check_swap(t_list *list_b, long *sorted, long len)
{
	int	mv;

	// while ((*list_b)->status != -1)
	// 	*list_b =(*list_b)->next;
	mv = 0;
	if (sorted[len] == (int)list_b->next->content)
	{
		if (sorted[len - 1] == (int)list_b->content)
		{
			mv = 5;
			while ((int)list_b->next->content != sorted[len - 2])
				list_b = list_b->next;
			if ((int)list_b->content == sorted[len - 3])
				mv = 4;
		}
	}
	return (mv);
}

void	move3(t_list **list_a, t_list **list_b, long *sorted)
{
	long	len;
	int		mv;

	len = long_len(sorted) - 1;
	while (len > -1)
	{
		mv = check_swap(*list_b, sorted, len);
		if (!mv)
			find_max(list_b, sorted, len);
		if (mv == 6)
		{
			while ((int)(*list_b)->next->content != sorted[len])
				rotate(list_b);
			check_swap(*list_b, sorted, len);
			if (mv == 0)
			{
				rotate(list_b);
			}
		}
		else if (mv == 7)
		{
			while ((int)(*list_b)->content != sorted[len])
				reverse_rotate(list_b);
		}
		// a push sans swap doit faire le swap
		push(list_b, list_a);
		len--;
	}
}
	// printf("long len | %ld\n", l);
	// printf("long | %ld\n", sorted[l]);
	// if (list_a < list_b)
	// 	l = 0;
