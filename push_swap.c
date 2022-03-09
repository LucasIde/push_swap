/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:42:56 by lide              #+#    #+#             */
/*   Updated: 2022/03/09 21:27:41 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	len(char *list)
// {
// 	int	i;

// 	if (!list)
// 		return (0);
// 	i = 0;
// 	while (list[i])
// 		i++;
// 	return (i);
// }

void	print(t_list *list)
{
	static int	i;

	i++;
	printf("\n|-- %d --|\n", i);
	if (!list)
		return ;

	while (list->status != -1)
		list = list->next;
	while (list)
	{
		printf("%d\n", (int)list->content);
		printf("|status %d|\n", (int)list->status);
		list = list->next;
		if (list)
		{
			if (list->status == -1)
				return ;
		}
	}
}

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

t_list	*lstnew(long arg)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->status = -1;
	list->content = (void *)arg;
	list->next = NULL;
	list->before = NULL;
	return (list);
}

t_list	*parcing(char **arg)
{
	t_list	*new;
	t_list	*list;
	t_verif	v;

	v.i = 0;
	list = NULL;
	while (arg[++v.i])
	{
		v.verif1 = verif(arg[v.i]);
		v.verif2 = ft_atoi(arg[v.i]);
		if (v.verif1 || v.verif2 > 2147483648)
		{
			write(1, "Error\n", 6);
			return (NULL);
		}
		new = lstnew(v.verif2);
		v.verif3 = is_double(&list, new);
		if (v.verif3)
			write(1, "Error\n", 6);
		if (v.verif3)
			return (NULL);
		addback(&list, new);
	}
	print(list);
	return (list);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	argc = 0;
	list_b = NULL;
	list_a = parcing(argv);
	if (!list_a)
		return (0);
	move(list_a, list_b);
	return (0);
}
