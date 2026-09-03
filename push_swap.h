/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telmo <telmo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 15:58:17 by tguezala          #+#    #+#             */
/*   Updated: 2026/09/03 00:00:00 by telmo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_opid
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_opid;

# define FLAG_ADAPTIVE 0
# define FLAG_SIMPLE 1
# define FLAG_MEDIUM 2
# define FLAG_COMPLEX 3

# define COMPLEXITY_UNKNOWN 0
# define COMPLEXITY_SMALL 1
# define COMPLEXITY_SIMPLE 2
# define COMPLEXITY_MEDIUM 3
# define COMPLEXITY_COMPLEX 4

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_op
{
	int		flag;
	int		complexity;
	int		bench;
	float	disorder;
	int		count[OP_COUNT];
	int		total;
}			t_op;

size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
void		free_split(char **split);

t_node		*ft_lstlast(t_node *list);
void		ft_lstadd_back(t_node **list, t_node *new);
t_node		*ft_lstnew(int value);
int			ft_lstsize(t_node *list);
void		free_stack(t_node **stack);

int			parse_int(const char *s, int *out);
int			has_duplicate(t_node *list, int value);
int			flag_detector(char *s, t_op *op);
void		assign_index(t_node **list);
float		disorder_check(t_node *list);
int			ft_is_sorted(t_node *lst);

int			get_stack_size(t_node *a);
int			get_max_bits(int size);
t_node		*find_min(t_node *a);
int			node_pos(t_node *stack, t_node *target);
void		move_to_top(t_node **a, int pos, int len, t_op *op);

void		init_op(t_op *op);
void		do_op(t_op *op, t_opid id, int print);
void		ft_putnbr_fd(int n, int fd);
void		bench_put_count(const char *label, int n);
void		bench_put_disorder(float d);
const char	*bench_strat_name(int flag);
const char	*bench_class_name(int complexity);
void		print_bench_results(t_op *op);

void		sa(t_node **a, int print, t_op *op);
void		sb(t_node **b, int print, t_op *op);
void		ss(t_node **a, t_node **b, int print, t_op *op);
void		pa(t_node **a, t_node **b, int print, t_op *op);
void		pb(t_node **a, t_node **b, int print, t_op *op);
void		ra(t_node **a, int print, t_op *op);
void		rb(t_node **b, int print, t_op *op);
void		rr(t_node **a, t_node **b, int print, t_op *op);
void		rra(t_node **a, int print, t_op *op);
void		rrb(t_node **b, int print, t_op *op);
void		rrr(t_node **a, t_node **b, int print, t_op *op);

void		sort_stack(t_node **a, t_node **b, int size, t_op *op);
void		sort_small(t_node **a, t_node **b, t_op *op);
void		push_min_to_b(t_node **a, t_node **b, int len, t_op *op);
void		sort_simple(t_node **a, t_node **b, t_op *op);
void		sort_medium(t_node **a, t_node **b, t_op *op);
void		radix_sort(t_node **a, t_node **b, t_op *op);
void		adaptive_sort(t_node **a, t_node **b, float disorder, t_op *op);

#endif
