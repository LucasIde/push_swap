/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:42:56 by lide              #+#    #+#             */
/*   Updated: 2022/03/07 20:06:21 by lide             ###   ########.fr       */
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
	while (list)
	{
		printf("%d\n", (int)list->content);
		printf("|status %d|\n", (int)list->status);
		list = list->next;
		if (list->status == -1)
			return;
	}
}

t_list	*lstnew(long arg)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->status = 0;
	list->content = (void *)arg;
	list->next = NULL;
	list->before = NULL;
	return (list);
}

void	parcing(char **arg)
{
	t_list	*new;
	t_list	*list;
	t_verif	v;

	v.i = 0;
	while (arg[++v.i])
	{
		v.verif1 = verif(arg[v.i]);
		v.verif2 = ft_atoi(arg[v.i]);
		if (v.verif1 || v.verif2 > 2147483648)
		{
			write(1, "Error\n", 6);
			return ;
		}
		new = lstnew(v.verif2);
		v.verif3 = is_double(&list, new);
		if (v.verif3)
		{
			write(1, "Error\n", 6);
			return ;
		}
		addback(&list, new);
	}
	print(list);
}

int	main(int argc, char **argv)
{
	argc = 0;
	parcing(argv);
	return (0);
}
