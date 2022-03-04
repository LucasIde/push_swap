/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:31:42 by lide              #+#    #+#             */
/*   Updated: 2022/03/04 15:25:20 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	atoi2(const char *str, int i, int x)
{
	long	j;

	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		j *= 10;
		j += str[i] - '0';
		if (j > 2147483648 || (x == 1 && j > 2147483647))
			return (3147483648);
		i++;
	}
	return (j * x);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		x;

	i = 0;
	x = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		x = -1;
		i++;
	}
	return (atoi2(str, i, x));
}

int	verif(char *arg)
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

int	is_double(t_list **list, t_list *new)
{
	t_list	*tmp;

	if (!*list)
		return (0);
	tmp = *list;
	while (tmp)
	{
		if ((long)tmp->content == (long)new->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
