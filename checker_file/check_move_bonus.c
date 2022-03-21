/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:49:53 by lide              #+#    #+#             */
/*   Updated: 2022/03/21 21:05:38 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	tr(char *str)
{
	int	i;
	int	mv;

	i = 0;
	mv = 0;
	while (str[i])
	{
		if (str[i] == 's')
			mv += 10;
		else if (str[i] == 'r')
			mv += 100;
		else if (str[i] == 'p')
			mv += 1000;
		else if (str[i] == 'b')
			mv += 1;
		else if (str[i] == 'a')
			mv += 2;
		else if (str[i] == '\n')
			mv += 3;
	}
}

void	check_move(t_list **list_a, t_list **list_b, char *str)
{

}

void	move(t_list **list_a, t_list **list_b, char *str)//ss rr rrr
{
	int	i;

	i = 0;
	if (str[i] == 's')
	{
		if (str[i + 1] == 'a')
			swap(list_a);
		else if (str[i + 1] == 'b')
			swap(list_b);
	}
	else if (str[i] == 'r')
	{
		if (str[i + 1] == 'a')
			rotate(list_a);
		else if (str[i + 1] == 'b')
			rotate(list_b);
		else if (str[i + 1] == 'r')
		{
			if (str[i + 2] == 'a')
				reverse_rotate(list_a);
			else if (str[i + 2] == 'b')
				reverse_rotate(list_b);
		}
	}
	else if (str[i] == 'p')
	{
		if (str[i + 1] == 'a')
			push(list_b, list_a);
		else if (str[i + 1] == 'b')
			push(list_a, list_b);
	}
}
