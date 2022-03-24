/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:42:56 by lide              #+#    #+#             */
/*   Updated: 2022/03/24 14:54:20 by lide             ###   ########.fr       */
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
		v.verif3 = is_double(list, new);
		if (v.verif3)
			free(new);
		if (v.verif3)
			return ((t_list *)write_error(&list));
		addback(&list, new);
	}
	return (list);
}

int	ft_divider(int argc)
{
	if (argc <= 11)
		return (2);
	if (argc > 11 && argc <= 101)
		return (6);
	else
		return (12);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	long	*sorted;
	int		div;

	if (argc < 3)
		return (check_is_digit(argc, argv));
	div = ft_divider(argc);
	list_b = NULL;
	list_a = parcing(argv);
	if (!list_a)
		return (0);
	if (!check_sorted(&list_a))
		return (0);
	sorted = first_sort(argv);
	if (!sorted)
		return (write_error_array(&list_a));
	if (argc < 7)
		tiny(&list_a, &list_b, sorted, argc);
	else
		create_chunk(&list_a, &list_b, sorted, div);
	while (list_a)
		free_list(&list_a);
	free(sorted);
	return (0);
}
