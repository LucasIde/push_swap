/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:32:39 by lide              #+#    #+#             */
/*   Updated: 2022/03/07 18:21:13 by lide             ###   ########.fr       */
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

long	ft_atoi(const char *str);
int		verif(char *arg);
int		is_double(t_list **list, t_list *new);
void	addback(t_list **list, t_list *new);
void	addfront(t_list **list, t_list *new);

#endif
