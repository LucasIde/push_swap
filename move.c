/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:30:52 by lide              #+#    #+#             */
/*   Updated: 2022/03/07 19:14:02 by lide             ###   ########.fr       */
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
	{
		new->status = -1;
		*list = new;
	}
	else
	{
		tmp->before = new;
		while (tmp->next != NULL && tmp->status != 1)
			tmp = tmp->next;
		if (tmp->status == 1)
			tmp->status = 0;
		new->next = *list;
		new->status = 1;
		new->before = tmp;
		tmp->next = new;
	}
}

//(sa/switch 1 et 2)pour echanger ajouter le premier element a la deuxieme place et avancer la liste de 1
//protect ne fait rien si un 1 ou 0 element

//(pa/addfront) ajoute b -> a puis avance b d'un

//(ra/addback)pour supprimer le premier element deplacer la liste d'un en avant

//(rra/addfront)pour retirer le dernier aller a l'avant dernier link le next a null

void	addfront(t_list **list, t_list *new)
{
	if (!list || new)
		return ;
	new->next = *list;
	*list = new;
}
