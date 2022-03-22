/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:15:06 by lide              #+#    #+#             */
/*   Updated: 2022/03/22 20:00:33 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	write_error_str(t_list **list_a, t_list **list_b, char *str)
{
	free(str);
	get_next_line(-1);
	while (*list_a)
		free_list(list_a);
	while (*list_b)
		free_list(list_b);
	write(1, "Error\n", 6);
	return (0);
}

void	*write_error(t_list **list)
{
	while (*list)
		free_list(list);
	write(1, "Error\n", 6);
	return (NULL);
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
