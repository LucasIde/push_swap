/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:30:52 by lide              #+#    #+#             */
/*   Updated: 2022/03/19 01:43:55 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **list)
{
	if (*list && (*list)->next != NULL)
	{
		list_next(list);
		(*list)->status = 1;
		(*list)->before->status = 0;
		(*list)->next->status = -1;
		list_next(list);
	}
}

void	reverse_rotate(t_list **list)
{
	if (*list && (*list)->next != NULL)
	{
		list_next(list);
		(*list)->status = 0;
		(*list)->before->status = -1;
		(*list)->before->before->status = 1;
		list_next(list);
	}
}

void	swap(t_list **first)
{
	t_list	*second;

	if (*first && (*first)->next != NULL)
	{
		list_next(first);
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
		list_next(first);
	}
}

void	move(t_list *list_a, t_list *list_b, long *sorted, int divider)
{
	move2(&list_a, &list_b, sorted, divider);//tester si je peux & dans move 2 au lieu de lui envoyer ** ici
	// print(list_a);
	// print(list_b);
	move3(&list_a, &list_b, sorted);


	// printf("\n|yo mmi %ld|\n", mm.min);
	// printf("\n|yo maaax %d|\n", max);
	// printf("\n|%ld|\n", len);
	// push(&list_a, &list_b);
	// swap(&list_a);
	// rotate(&list_a);
	// reverse_rotate(&list_a);
	// print(list_a);
	// print(list_b);
}
