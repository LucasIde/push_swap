/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:42:56 by lide              #+#    #+#             */
/*   Updated: 2022/03/18 19:13:47 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		v.verif1 = is_digit(arg[v.i]);
		if (v.verif1)
			return ((t_list *)write_error(&list));
		v.verif2 = ft_atoi(arg[v.i]);
		if (v.verif2 > 2147483648)
			return ((t_list *)write_error(&list));
		new = lstnew(v.verif2);
		if (!new)
			return ((t_list *)write_error(&list));
		v.verif3 = is_double(&list, new);
		if (v.verif3)
			return ((t_list *)write_error(&list));
		addback(&list, new);
	}
	return (list);
}

int	ft_divider(int argc)
{
	if (argc <= 10)
		return (2);
	if (argc > 10 && argc <= 100)
		return (6);
	else
		return (12);
}

int	check_sorted(t_list **list_a)
{
	int	check;

	check = 0;
	while (list_a && check == 0)
	{
		if ((*list_a)->content > (*list_a)->next->content)
			check = 1;
		*list_a = (*list_a)->next;
		if ((*list_a)->status == -1)
		{
			while(*list_a)
				free_list(list_a);
			return (0);
		}
	}
	list_before(list_a);
	return (check);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	long	*sorted;
	int		divider;

	argc--;
	if (argc < 2)
		return (0);
	divider = ft_divider(argc);
	list_b = NULL;
	list_a = parcing(argv);
	if (!list_a)
		return (0);
	if (!check_sorted(&list_a))
		return (0);
	sorted = first_sort(argv);
	if (!sorted)
		return (write_error_array(&list_a));
	if (argc < 6)
		tiny(&list_a, &list_b, sorted, argc);
	else
		move(list_a, list_b, sorted, divider);
	while(list_a)
		free_list(&list_a);
	free(sorted);
	return (0);
}
