/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:49:53 by lide              #+#    #+#             */
/*   Updated: 2022/03/24 15:45:30 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_move2(char *str, int i, int mv)
{
	while (str[++i] && mv >= 0)
	{
		if (str[i] == 's' && ((i == 0 && str[i + 1] != '\n')
				|| (i == 1 && mv == 10)))
			mv += 10;
		else if (str[i] == 'r' && ((i == 0 && str[i + 1] != '\n')
				|| (i == 1 && mv == 100) || (i == 2 && mv == 200)))
			mv += 100;
		else if (str[i] == 'p' && i == 0 && str[i + 1] != '\n')
			mv += 1000;
		else if (str[i] == 'a' && (mv % 10 == 0) && (i == 1
				|| (i == 2 && str[i - 1] == 'r')))
			mv += 1;
		else if (str[i] == 'b' && (mv % 10 == 0) && (i == 1
				|| (i == 2 && str[i - 1] == 'r')))
			mv += 2;
		else if (str[i] == '\n' && !str[i + 1])
			mv += 3;
		else
			mv = -1;
	}
	return (mv);
}

int	check_move(char *str)
{
	int	i;
	int	mv;

	i = -1;
	mv = 0;
	return (check_move2(str, i, mv));
}

int	move(t_list **list_a, t_list **list_b, char *str)
{
	int	mv;

	mv = check_move(str);
	if (mv == -1)
		return (1);
	if (mv == 14 || mv == 23)
		swap(list_a);
	if (mv == 15 || mv == 23)
		swap(list_b);
	if (mv == 104 || mv == 203)
		rotate(list_a);
	if (mv == 105 || mv == 203)
		rotate(list_b);
	if (mv == 204 || mv == 303)
		reverse_rotate(list_a);
	if (mv == 205 || mv == 303)
		reverse_rotate(list_b);
	else if (mv == 1004)
		push(list_b, list_a);
	else if (mv == 1005)
		push(list_a, list_b);
	return (0);
}
