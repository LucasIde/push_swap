/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:42:56 by lide              #+#    #+#             */
/*   Updated: 2022/03/04 18:41:23 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	len(char *list)
{
	int	i;

	if (!list)
		return (0);
	i = 0;
	while (list[i])
		i++;
	return (i);
}

void	print(t_list *list)
{
	while (list)
	{
		printf("%d\n", (int)list->content);
		list = list->next;
	}
}

t_list	*lstnew(long arg)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = (void *)arg;
	list->next = NULL;
	return (list);
}

void	parcing(char **arg)
{
	t_list	*new;
	t_list	*list;
	t_test	tt;

	tt.i = 0;
	while (arg[++tt.i])
	{
		tt.verif1 = verif(arg[tt.i]);
		tt.verif2 = ft_atoi(arg[tt.i]);
		if (tt.verif1 || tt.verif2 > 2147483648)
		{
			write(1, "Error\n", 6);
			return ;
		}
		new = lstnew(tt.verif2);
		tt.verif3 = is_double(&list, new);
		if (tt.verif3)
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
