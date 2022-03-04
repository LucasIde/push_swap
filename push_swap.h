/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:32:39 by lide              #+#    #+#             */
/*   Updated: 2022/03/04 15:21:45 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_test
{
	int		i;
	int		verif1;
	long	verif2;
	long	verif3;
}			t_test;

long	ft_atoi(const char *str);
int		verif(char *arg);
int		is_double(t_list **list, t_list *new);

#endif
