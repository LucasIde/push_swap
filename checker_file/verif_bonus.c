/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:29:22 by lide              #+#    #+#             */
/*   Updated: 2022/03/22 19:17:55 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

long	ft_atoi(const char *str)
{
	long	j;
	int		i;
	int		x;

	i = 0;
	x = 1;
	j = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		x = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j *= 10;
		j += str[i] - '0';
		if (j > 2147483648 || (x == 1 && j > 2147483647))
			return (2147483649);
		i++;
	}
	return (j * x);
}

int	is_digit(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	is_double(t_list *list, t_list *new)
{
	t_list	*tmp;

	if (!list)
		return (0);
	tmp = list;
	while (tmp)
	{
		if ((int)tmp->content == (int)new->content)
			return (1);
		if (tmp->next == NULL)
			return (0);
		tmp = tmp->next;
		if (tmp->status == -1)
			return (0);
	}
	return (0);
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
