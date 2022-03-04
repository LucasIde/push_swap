/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:30:52 by lide              #+#    #+#             */
/*   Updated: 2022/03/04 18:41:21 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	addback(t_list **list, t_list *new)
{
	t_list	*tmp;

	tmp = *list;
	if (!list)
		return ;
	if (!*list)
		*list = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	addfront(t_list **list, t_list *new)
{
	new->next = *list;
	*list = new;
}
