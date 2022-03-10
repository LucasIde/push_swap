/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:30:52 by lide              #+#    #+#             */
/*   Updated: 2022/03/10 16:27:14 by lide             ###   ########.fr       */
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

void	push_add(t_list *new, t_list **list_r)
{
	if (!*list_r)
	{
		*list_r = new;
	}
	else if (((*list_r)->next) == NULL)
	{
		new->before = *list_r;
		new->next = *list_r;
		(*list_r)->before = new;
		(*list_r)->next = new;
		(*list_r)->status = 1;
	}
	else
	{
		while ((*list_r)->status != -1)
			(*list_r) = (*list_r)->next;
		(*list_r)->before->next = new;
		new->before = (*list_r)->before;
		new->next = *list_r;
		(*list_r)->before = new;
		(*list_r)->status = 0;
	}
}

void	push_free(t_list **list_send)
{
	if ((*list_send)->next == NULL)
	{
		free(*list_send);
		*list_send = NULL;
	}
	else if ((*list_send)->status == -1 && (*list_send)->next->status == 1)
	{
		(*list_send)->next->status = -1;
		(*list_send)->next->next = NULL;
		(*list_send)->next->before = NULL;
		free(*list_send);
		*list_send = (*list_send)->next;
	}
	else
	{
		(*list_send)->next->status = -1;
		(*list_send)->next->before = (*list_send)->before;
		(*list_send)->before->next = (*list_send)->next;
		free(*list_send);
		*list_send = (*list_send)->next;
	}
}

void	push(t_list **list_send, t_list **list_r)
{
	t_list	*new;

	if (!*list_send)
		return ;
	while ((*list_send)->status != -1)
		*list_send = (*list_send)->next;
	new = lstnew((long)(*list_send)->content);
	push_add(new, list_r);
	push_free(list_send);
}

void	move(t_list *list_a, t_list *list_b)
{
	push(&list_a, &list_b);
	swap(&list_a);
	rotate(&list_a);
	reverse_rotate(&list_a);
	print(list_a);
	print(list_b);
}
