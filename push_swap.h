/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:32:39 by lide              #+#    #+#             */
/*   Updated: 2022/03/11 19:00:25 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				status;
	void			*content;
	struct s_list	*next;
	struct s_list	*before;
}					t_list;

typedef struct s_verif
{
	int		i;
	int		verif1;
	long	verif2;
	long	verif3;
}			t_verif;

t_list	*parcing(char **arg);
t_list	*lstnew(long arg);
void	addback(t_list **list, t_list *new);
int		verif(char *arg);
long	ft_atoi(const char *str);
int		is_double(t_list **list, t_list *new);
void	push(t_list **list_send, t_list **list_r);
void	swap(t_list **first);
void	reverse_rotate(t_list **list);
void	rotate(t_list **list);
long	*first_sort(char **argv);
void	move(t_list *list_a, t_list *list_b, long *sorted);


void	print(t_list *list_a, t_list *list_b);

#endif
