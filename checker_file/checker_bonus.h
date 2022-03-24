/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:15:07 by lide              #+#    #+#             */
/*   Updated: 2022/03/24 13:46:09 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				status;
	void			*content;
	struct s_list	*next;
	struct s_list	*before;
}					t_list;

typedef struct s_verif
{
	long	i;
	int		verif1;
	long	verif2;
	long	verif3;
}			t_verif;

long	ft_atoi(const char *str);
int		is_digit(char *arg);
int		is_double(t_list *list, t_list *new);
void	addback(t_list **list, t_list *new);
t_list	*lstnew(long arg);
void	list_next(t_list **list);
void	list_before(t_list **list);
void	rotate(t_list **list);
void	reverse_rotate(t_list **list);
void	swap(t_list **first);
void	push(t_list **list_send, t_list **list_r);
void	free_list(t_list **list);
int		move(t_list **list_a, t_list **list_b, char *str);
void	*write_error(t_list **list);
int		write_error_str(t_list **list_a, t_list **list_b, char *str);

int		backspace(char *s);
int		ft_find(char *s);
int		ft_strlen(char *s);
char	*ft_line(char *save, int len);
char	*ft_save(char *save, int len);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *save);
char	*ft_strjoin(char *s1, char *s2, int i, int j);

#endif
