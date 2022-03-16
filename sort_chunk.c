/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:52:02 by lide              #+#    #+#             */
/*   Updated: 2022/03/16 20:43:27 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *list_b, long *sorted, long len)
{
	long	rotate;
	long	reverse;

	rotate = 0;
	reverse = 0;
	list_next(&list_b);
	while (sorted[len] != (int)list_b->content)
	{
		// printf("|sorted  %ld |\n", sorted[len]);
		// printf("|sorted  %d |\n", (int)list_b->content);
		list_b =list_b->next;
		rotate++;
	}
	list_before(&list_b);
	while (sorted[len] != (int)list_b->content)
	{
		list_b =list_b->before;
		reverse++;
	}
	if (rotate < reverse)
		return (6);
	else
		return (7);
}

int	check_swap(t_list *list_b, long *sorted, long len, int mv)
{
	// while ((*list_b)->status != -1)
	// 	*list_b =(*list_b)->next;
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
		mv = find_max(*list_b, sorted, len);
		// printf("|contentttttt %d|\n", (int)(*list_b)->content);
		list_next(list_b);
		while ((int)(*list_b)->content != sorted[len])
		{
			// printf("\n|mmmoooovvveee %d|\n", mv);
			if (mv == 6)
				rotate(list_b);
			else if (mv == 7)
				reverse_rotate(list_b);
			write_mv(mv);
			list_next(list_b);
		}
		// mv = check_swap(*list_b, sorted, len, mv);
		push(list_b, list_a);
		write (1, "pa\n", 3);
		len--;
	}
}

	// {
	// 	// mv = check_swap(*list_b, sorted, len);
	// 	// if (!mv)
	// 	mv = find_max(list_b, sorted, len);
	// 	if (mv == 6)
	// 	{
	// 		while ((int)(*list_b)->content != sorted[len])
	// 			rotate(list_b);
	// 		// check_swap(*list_b, sorted, len);
	// 		// if (mv == 0)
	// 		// {
	// 		// 	rotate(list_b);
	// 		// }
	// 	}
	// 	else if (mv == 7)
	// 	{
	// 		while ((int)(*list_b)->content != sorted[len])
	// 			reverse_rotate(list_b);
	// 	}
	// 	write_mv(mv);
	// 	// a push sans swap doit faire le swap
	// 	push(list_b, list_a);
	// 	write (1, "pa\n", 3);
	// 	len--;
	// }
