/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:30:52 by lide              #+#    #+#             */
/*   Updated: 2022/03/08 20:57:10 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list *list)
{
	while (list->status != -1)
		list = list->next;
	list->status = 1;
	list->next->status = -1;
	list->before->status = 0;
}

void	reverse_rotate(t_list *list)
{
	while (list->status != -1)
		list = list->next;
	list->status = 0;
	list->before->status = -1;
	list->before->before->status = 1;
}

void	swap(t_list *list)
{
	t_list	*first;

	while (list->status != -1)
		list = list->next;
	first = list;
	list = list->next;
	first->next = list->next;
	list->before = first->before;
	list->next = first;
	first->before = list;
	first->status = list->status;
	list->status = -1;
	while (first->status != 1)
		first = first->before;
	first->next = list;
}

void	push(t_list *list_send, t_list *list_r)
{
	t_list	*new;

	while (list_send->status != -1)
		list_send = list_send->next;
	new = lstnew((long)list_send->content);
	if (!list_r)
		list_r = new;
	else if (listr->next == NULL)
	{
		new->before = list_r;
		new->next = list_r;
		list_r->before = new;
		list_r->next = new;
		list_r->status = 1;
	}
	else
	{
		while (list_r->status != -1)
			list_r = list_r->next;
		list_r->before->next = new;
		new->before = list_r->before;
		new->next = list_r;
		list_r->before = new;
		list_r->status = 0;
	}
}

void	move(t_list *list_a, t_list *list_b)
{
	// list_b = NULL;
	rotate(list_a);
	swap(list_a);
	print(list_a);
}
