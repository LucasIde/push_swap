/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:32:39 by lide              #+#    #+#             */
/*   Updated: 2022/03/19 01:03:32 by lide             ###   ########.fr       */
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

typedef struct s_move
{
	long	len;
	long	min;
	long	max;
	int		mv;
	int		i;
	int		splited;
}			t_move;

t_list	*parcing(char **arg);
t_list	*lstnew(long arg);
void	addback(t_list **list, t_list *new);
int		is_digit(char *arg);
long	ft_atoi(const char *str);
int		is_double(t_list **list, t_list *new);
void	push(t_list **list_send, t_list **list_r);
void	swap(t_list **first);
void	reverse_rotate(t_list **list);
void	rotate(t_list **list);
long	*first_sort(char **argv);
void	move(t_list *list_a, t_list *list_b, long *sorted, int divider);
void	write_mv(int mv);
void	*write_error(t_list **list);
int	write_error_array(t_list **list);
void	move2(t_list **list_a, t_list **list_b, long *sorted, int diviseur);
void	move3(t_list **list_a, t_list **list_b, long *sorted);
long	long_len(long *sorted);
void	list_before(t_list **list);
void	list_next(t_list **list);
void	tiny(t_list **list_a, t_list **list_b, long *sorted, int argc);
int		check_move(t_list *list, long *sorted, int start, int end);
void	free_list(t_list **list);


void	print(t_list *list);

#endif
