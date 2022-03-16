/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:42:56 by lide              #+#    #+#             */
/*   Updated: 2022/03/16 20:26:42 by lide             ###   ########.fr       */
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

// void	print(t_list *list_a, t_list *list_b)
// {
// 	static int	i;

// 	i++;
// 	printf("\n-|a| -- --  --%d--  -- -- |b|-\n", i);
// 	while (list_a->status != -1)
// 		list_a = list_a->next;
// 	while (list_b->status != -1)
// 		list_b = list_b->next;
// 	while (list_a && list_b)
// 	{
// 		printf(" |%d|                     |%d|\n", (int)list_a->content, (int)list_b->content);
// 		printf("-|status %d|        |status %d|-\n", (int)list_a->status, (int)list_a->status);
// 		list_a = list_a->next;
// 		list_b = list_b->next;
// 		if (list_a)
// 		{
// 			if (list_a->status == -1)
// 			{
// 				while (list_b)
// 				{
// 					printf("                         |%d|\n", (int)list_b->content);
// 					printf("-                  |status %d|-\n", (int)list_b->status);
// 					list_b = list_b->next;
// 					if (list_b)
// 					{
// 						if (list_b->status == -1)
// 							return ;
// 					}
// 				}
// 			}
// 		}
// 		else if (list_b)
// 		{
// 			if (list_b->status == -1)
// 			{
// 				while (list_a)
// 				{
// 					printf(" |%d|\n", (int)list_a->content);
// 					printf("-|status %d|-\n", (int)list_a->status);
// 					list_a = list_a->next;
// 					if (list_a)
// 					{
// 						if (list_a->status == -1)
// 							return ;
// 					}
// 				}
// 			}
// 		}
// 	}
// }
void	print(t_list *list)
{
	static int	i;

	i++;
	printf("\n |-- %d --|\n", i);
	if (!list)
		return ;
	while (list->status != -1)
		list = list->next;
	while (list)
	{
		printf("    |%d|\n", (int)list->content);
		printf("-|status %d|-\n", (int)list->status);
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
		if (v.verif1)
			return ((t_list *)write_error());
		v.verif2 = ft_atoi(arg[v.i]);
		if (v.verif2 > 2147483648)
			return ((t_list *)write_error());
		new = lstnew(v.verif2);
		v.verif3 = is_double(&list, new);
		if (v.verif3)
			return ((t_list *)write_error());
		addback(&list, new);
	}
	return (list);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	long	*sorted;
	int		i;

	i = -1;
	if (argc < 3)
		return (0);
	list_b = NULL;
	list_a = parcing(argv);
	if (!list_a)
		return (0);
	sorted = first_sort(argv); //regarder si write error/free
	if (!sorted)
		return (0);
	// while (argv[(++i) + 1])
		// printf("|long [%ld]|", sorted[i]);
	move(list_a, list_b, sorted);
	return (0);
}
