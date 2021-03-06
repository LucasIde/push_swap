/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:44:58 by lide              #+#    #+#             */
/*   Updated: 2022/03/22 19:08:05 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two(t_list **list_a)
{
	if ((int)(*list_a)->content > (int)(*list_a)->next->content)
	{
		swap(list_a);
		write(1, "sa\n", 3);
	}
}

void	three(t_list **list_a, long *sorted, int len)
{
	if ((int)(*list_a)->content == sorted[2])
	{
		rotate(list_a);
		write(1, "ra\n", 3);
	}
	if ((int)(*list_a)->before->content == sorted[len + 1])
	{
		reverse_rotate(list_a);
		write(1, "rra\n", 4);
	}
	if ((int)(*list_a)->content > (int)(*list_a)->next->content)
	{
		swap(list_a);
		write(1, "sa\n", 3);
	}
	if ((int)(*list_a)->before->content == sorted[len])
	{
		reverse_rotate(list_a);
		write(1, "rra\n", 4);
	}
}

void	four(t_list **list_a, t_list **list_b, long *sorted, int len)
{
	int	mv;

	mv = check_move(*list_a, sorted, 0, 1);
	while ((int)(*list_a)->content != sorted[0])
	{
		if (mv == 1)
			swap(list_a);
		else if (mv == 2)
			rotate(list_a);
		else if (mv == 3)
			reverse_rotate(list_a);
		write_mv(mv);
	}
	push(list_a, list_b);
	write(1, "pb\n", 3);
	three(list_a, sorted, len + 1);
	push(list_b, list_a);
	write(1, "pa\n", 3);
}

void	five(t_list **list_a, t_list **list_b, long *sorted)
{
	int	mv;

	mv = check_move(*list_a, sorted, 1, 2);
	while ((int)(*list_a)->content != sorted[1])
	{
		if (mv == 1)
			swap(list_a);
		else if (mv == 2)
			rotate(list_a);
		else if (mv == 3)
			reverse_rotate(list_a);
		write_mv(mv);
	}
	push(list_a, list_b);
	write(1, "pb\n", 3);
	four(list_a, list_b, sorted, 1);
	push(list_b, list_a);
	write(1, "pa\n", 3);
	if ((int)(*list_a)->content > (int)(*list_a)->next->content)
	{
		swap(list_a);
		write(1, "sa\n", 3);
	}
}

void	tiny(t_list **list_a, t_list **list_b, long *sorted, int argc)
{
	if (argc == 3)
		two(list_a);
	else if (argc == 4)
		three(list_a, sorted, 0);
	else if (argc == 5)
		four(list_a, list_b, sorted, 0);
	else if (argc == 6)
		five(list_a, list_b, sorted);
}
