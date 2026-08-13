#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
 
# include <stdlib.h>
# include <unistd.h>
 
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
 
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);
 
#endif