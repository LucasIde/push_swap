/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:52:51 by lide              #+#    #+#             */
/*   Updated: 2022/03/14 17:02:19 by lide             ###   ########.fr       */
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
