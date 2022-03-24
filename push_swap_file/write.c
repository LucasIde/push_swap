/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:38:12 by lide              #+#    #+#             */
/*   Updated: 2022/03/24 15:02:13 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_mv(int mv)
{
	if (mv == 1)
		write (1, "sa\n", 3);
	else if (mv == 2)
		write (1, "ra\n", 3);
	else if (mv == 3)
		write (1, "rra\n", 4);
	else if (mv == 4)
		write (1, "ss\n", 3);
	else if (mv == 5)
		write (1, "sb\n", 3);
	else if (mv == 6)
		write (1, "rb\n", 3);
	else if (mv == 7)
		write (1, "rrb\n", 4);
}

void	*write_error(t_list **list)
{
	while (*list)
		free_list(list);
	write(2, "Error\n", 6);
	return (NULL);
}

int	write_error_array(t_list **list)
{
	while (*list)
		free_list(list);
	write(2, "Error\n", 6);
	return (0);
}

int	check_is_digit(int argc, char **argv)
{
	int		verif;
	long	verif2;

	verif = 0;
	verif2 = 0;
	if (argc < 2)
		return (0);
	verif = is_digit(argv[1]);
	verif2 = ft_atoi(argv[1]);
	if (verif || verif2 > 2147483648)
		write(2, "Error\n", 6);
	return (0);
}
