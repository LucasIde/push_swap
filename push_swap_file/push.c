/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:52:51 by lide              #+#    #+#             */
/*   Updated: 2022/03/22 19:12:42 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		list_next(list_r);
		(*list_r)->before->next = new;
		new->before = (*list_r)->before;
		new->next = *list_r;
		(*list_r)->before = new;
		(*list_r)->status = 0;
	}
}

void	free_list(t_list **list)
{
	if (*list && (*list)->next != NULL)
		list_next(list);
	if ((*list)->next == NULL)
	{
		free(*list);
		*list = NULL;
	}
	else if ((int)(*list)->next->content == (int)(*list)->before->content)
	{
		(*list)->next->status = -1;
		(*list)->next->next = NULL;
		(*list)->next->before = NULL;
		free(*list);
		*list = (*list)->next;
	}
	else
	{
		(*list)->next->status = -1;
		(*list)->next->before = (*list)->before;
		(*list)->before->next = (*list)->next;
		free(*list);
		*list = (*list)->next;
	}
}

void	push(t_list **list_send, t_list **list_r)
{
	t_list	*new;

	if (!*list_send)
		return ;
	list_next(list_send);
	new = lstnew((int)(*list_send)->content);
	push_add(new, list_r);
	free_list(list_send);
	if (*list_send && (*list_send)->next != NULL)
		list_next(list_send);
	if (*list_r && (*list_r)->next != NULL)
		list_next(list_r);
}
