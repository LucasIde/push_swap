/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:49:55 by lide              #+#    #+#             */
/*   Updated: 2022/03/18 18:15:27 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(long *save, int i)
{
	int	j;

	j = -1;
	while (save[++j] < 2147483649)
	{
		if ((j + 1) < i)
		{
			if (save[j] > save[j + 1])
				return (1);
		}
	}
	return (0);
}

long	*sort(long *save, int i)
{
	int		verif;
	int		j;
	long	tmp;

	verif = 1;
	while (verif)
	{
		verif = check(save, i);
		j = 0;
		while (j < 5)
			j++;
		j = -1;
		while (verif && save[++j] < 2147483649)
		{
			if (save[j] > save[j + 1])
			{
				tmp = save[j];
				save[j] = save[j + 1];
				save[j + 1] = tmp;
			}
		}
	}
	return (save);
}

long	*first_sort(char **argv)
{
	long	*save;
	int		i;

	i = 0;
	while (argv[i])
		i++;
	save = malloc(sizeof(long) * i);
	if (!save)
		return (NULL);
	i = -1;
	while (argv[(++i) + 1])
		save[i] = ft_atoi(argv[i + 1]);
	save[i] = 2147483649;
	save = sort(save, i);
	return (save);
}
