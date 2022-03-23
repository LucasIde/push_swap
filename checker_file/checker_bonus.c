/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:21:15 by lide              #+#    #+#             */
/*   Updated: 2022/03/23 18:16:14 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_list	*parcing(char **arg)
{
	t_list	*new;
	t_list	*list;
	t_verif	v;

	v.i = 0;
	list = NULL;
	while (arg[++v.i])
	{
		v.verif1 = is_digit(arg[v.i]);
		if (v.verif1)
			return ((t_list *)write_error(&list));
		v.verif2 = ft_atoi(arg[v.i]);
		if (v.verif2 > 2147483648)
			return ((t_list *)write_error(&list));
		new = lstnew(v.verif2);
		if (!new)
			return ((t_list *)write_error(&list));
		v.verif3 = is_double(list, new);
		if (v.verif3)
			free(new);
		if (v.verif3)
			return ((t_list *)write_error(&list));
		addback(&list, new);
	}
	return (list);
}

void	check_sorted(t_list **list_a, t_list *list_b)
{
	int	check;

	check = 0;
	if (list_b)
	{
		write(1, "KO\n", 3);
		return ;
	}
	if ((*list_a)->next == NULL)
		write(1, "OK\n", 3);
	if ((*list_a)->next == NULL)
		return ;
	while (*list_a && check == 0)
	{
		if ((int)(*list_a)->content > (int)(*list_a)->next->content)
			check = 1;
		*list_a = (*list_a)->next;
		if ((*list_a)->status == -1)
		{
			write(1, "OK\n", 3);
			return ;
		}
	}
	list_before(list_a);
	write(1, "KO\n", 3);
}

void	double_free(t_list **list_a, t_list **list_b)
{
	while (*list_a)
		free_list(list_a);
	while (*list_b)
		free_list(list_b);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	char	*str;
	int		verif;

	if (argc < 2)
		return (0);
	list_b = NULL;
	list_a = parcing(argv);
	if (!list_a)
		return (0);
	str = get_next_line(0);
	while (str)
	{
		verif = move(&list_a, &list_b, str);
		if (verif)
			return (write_error_str(&list_a, &list_b, str));
		free(str);
		str = get_next_line(0);
	}
	check_sorted(&list_a, list_b);
	double_free(&list_a, &list_b);
	return (0);
}
