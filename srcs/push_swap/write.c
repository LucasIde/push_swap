/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:38:12 by lide              #+#    #+#             */
/*   Updated: 2022/03/19 15:56:29 by lide             ###   ########.fr       */
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
	write(1, "Error\n", 6);
	return (NULL);
}

int	write_error_array(t_list **list)
{
	while (*list)
		free_list(list);
	write(1, "Error\n", 6);
	return (0);
}
