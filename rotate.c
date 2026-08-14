#include "push_swap.h"

void ra(t_node **a, int print)
{
	t_node *first;
	t_node *tail;

	if (!*a || (*a)->next == NULL)
	return ;

	first = *a;
	*a = (*a)->next;
	first->next = NULL;

	tail = *a;

    while(tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = first;
	if (print)
		write(1, "ra\n", 3);// ft_putendl_fd
	}

void rb(t_node **b, int print)
{
	t_node *first;
	t_node *tail;

	if (!*b || (*b)->next == NULL)
	return ;

	first = *b;
	*b = (*b)->next;
	first->next = NULL;

	tail = *b;

	while(tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = first;
	if (print)
		write(1, "rb\n", 3);// ft_putendl_fd
	}

void    rr(t_node **a, t_node **b, int print)
{
	ra(a, 0);
	rb(b, 0);
	if (print)
    	write(1, "rr\n", 3);// ft_putendl_fd
}

void rra(t_node **a, int print)
{
    t_node *last;

    if (!*a || !(*a)->next)
        return ;

    last = *a;
    while (last->next != NULL)
        last = last->next;
	last->prev->next = NULL;

    last->next = *a;
    (*a)->prev = last;

    last->prev = NULL;

    *a = last;

    if (print)
	    write(1, "rra\n", 4);// ft_putendl_fd
}

void rrb(t_node **b, int print)
{
    t_node *last;

    if (!*b || !(*b)->next)
        return ;

    last = *b;
    while (last->next != NULL)
        last = last->next;
	last->prev->next = NULL;

    last->next = *b;
    (*b)->prev = last;

    last->prev = NULL;

    *b = last;
    
    if (print)
	    write(1, "rrb\n", 4);// ft_putendl_fd
}

void    rrr(t_node **a, t_node **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print)
	    write(1, "rrr\n", 4);// ft_putendl_fd
}