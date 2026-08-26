/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguezala <tguezala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 15:58:17 by tguezala          #+#    #+#             */
/*   Updated: 2026/08/14 18:43:45 by tguezala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define DEBUG_MODE 1

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		is_bench(char *s);
long	ft_atol(const char *str);
t_node	*ft_lstlast(t_node *list);
void	ft_lstadd_back(t_node **list, t_node *new);
t_node	*ft_lstnew(int value);
void	assign_index(t_node **list);
float	disorder_check(t_node *list);
int		is_valid(char *s);
int		has_duplicate(t_node *list, int value);
int		flag_detector(char *s, int flag);

void	sa(t_node **a, int print);
void	sb(t_node **b, int print);
void	ss(t_node **a, t_node **b, int print);

void	pa(t_node **a, t_node **b, int print);
void	pb(t_node **a, t_node **b, int print);
void    ra(t_node **a, int print);
void    rb(t_node **b, int print);

void    rr(t_node **a, t_node **b, int print);
void    rra(t_node **a, int print);
void    rrb(t_node **b, int print);
void    rrr(t_node **a, t_node **b, int print);
int		ft_lstsize(t_node *lst);

t_node	*find_min(t_node *a);
void	sort_simple(t_node **a, t_node **b);

#endif
