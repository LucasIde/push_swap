/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:17:48 by lide              #+#    #+#             */
/*   Updated: 2022/03/23 17:02:56 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	list_next(&list);
	if (in_list((int)list->next->content, sorted, start, end))
		return (1);
	while (!in_list((int)list->content, sorted, start, end))
	{
		list = list->next;
		rotate++;
	}
	list_before(&list);
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

int	check_move2(t_list *list)
{
	if (list && list->next != NULL)
	{
		list_next(&list);
		if ((int)list->content < (int)list->next->content)
			return (4);
	}
	return (1);
}

void	chunk(t_list **list_a, t_list **list_b, long *sorted, t_move *m)
{
	if (!in_list((int)(*list_a)->content, sorted, m->min, m->len))
	{
		m->mv = check_move(*list_a, sorted, m->min, m->len);
		if (m->mv == 1)
			m->mv = check_move2(*list_b);
	}
	while (!in_list((int)(*list_a)->content, sorted, m->min, m->len))
	{
		if (m->mv == 1 || m->mv == 4)
			swap(list_a);
		else if (m->mv == 2)
			rotate(list_a);
		else if (m->mv == 3)
			reverse_rotate(list_a);
		if (m->mv == 4)
			swap(list_b);
		write_mv(m->mv);
	}
	push(list_a, list_b);
	write (1, "pb\n", 3);
}

void	create_chunk(t_list **list_a, t_list **list_b, long *sorted, int div)
{
	t_move		m;
	static int	mult;

	m.max = long_len(sorted);
	m.splited = m.max / div;
	m.min = 0;
	m.len = m.splited;
	while (m.min < m.max)
	{
		if (m.len > m.max)
			m.len = m.max;
		m.i = m.min;
		while (m.i < m.len)
		{
			chunk(list_a, list_b, sorted, &m);
			m.i++;
		}
		mult++;
		m.min = m.splited * mult;
		m.len = m.splited * (mult + 1);
	}
	sort_chunk(list_a, list_b, sorted);
}
