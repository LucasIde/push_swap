/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:49:55 by lide              #+#    #+#             */
/*   Updated: 2022/03/19 16:03:56 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	long_len(long *sorted)
{
	long	i;

	i = 0;
	while (sorted[i] < 2147483649)
		i++;
	return (i);
}

int	check(long *sorted, int i)
{
	int	j;

	j = -1;
	while (sorted[++j] < 2147483649)
	{
		if ((j + 1) < i)
		{
			if (sorted[j] > sorted[j + 1])
				return (1);
		}
	}
	return (0);
}

long	*sort(long *sorted, int i)
{
	int		verif;
	int		j;
	long	tmp;

	verif = 1;
	while (verif)
	{
		verif = check(sorted, i);
		j = 0;
		while (j < 5)
			j++;
		j = -1;
		while (verif && sorted[++j] < 2147483649)
		{
			if (sorted[j] > sorted[j + 1])
			{
				tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
			}
		}
	}
	return (sorted);
}

long	*first_sort(char **argv)
{
	long	*sorted;
	int		i;

	i = 0;
	while (argv[i])
		i++;
	sorted = malloc(sizeof(long) * i);
	if (!sorted)
		return (NULL);
	i = -1;
	while (argv[(++i) + 1])
		sorted[i] = ft_atoi(argv[i + 1]);
	sorted[i] = 2147483649;
	sorted = sort(sorted, i);
	return (sorted);
}
