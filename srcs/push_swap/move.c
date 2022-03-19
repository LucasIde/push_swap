/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:30:52 by lide              #+#    #+#             */
/*   Updated: 2022/03/19 15:56:27 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_next(t_list **list)
{
	while ((*list)->status != -1)
		*list = (*list)->next;
}

void	list_before(t_list **list)
{
	while ((*list)->status != -1)
		*list = (*list)->before;
}

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
