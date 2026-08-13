#include "push_swap.h"

void	sa(t_stack **a, int print)
{
	int	tmp;
 
	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	if (print)
		write(1, "sa\n", 3); // ft_putendl_f
}

void	sb(t_stack **b, int print)
{
	int	tmp;
 
	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	if (print)
		write(1, "sb\n", 3); // ft_putendl_f
}

void	ss(t_stack **a, t_stack **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		write(1, "ss\n", 3);//t_putendl_f
}

void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;
 
	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (print)
		write(1, "pa\n", 3);// // ft_putendl_f
}

void	pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;
 
	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (print)
		write(1, "pb\n", 3);// ft_putendl_f
}
