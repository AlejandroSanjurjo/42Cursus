#include "push_swap.h"

void revrotate(t_stack_node **stack)
{
    t_stack_node *last;

    if(!stack || !(*stack)->next)
        return ;
    last = find_last_node(*stack);
    last->prev->next = NULL;
    last->prev = NULL;
    last->next = *stack;
    *stack = last;
    last->next->prev = last;
}

void rra(t_stack_node **a, bool print)
{
    revrotate(a);
    if(!print)
        write(1, "rra\n", 4);
}

void rrb(t_stack_node **b, bool print)
{
    revrotate(b);
    if(!print)
        write(1, "rrb\n", 4);
}

void rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    revrotate(a);
    revrotate(b);
    if(!print)
        write(1, "rrr\n", 4);
}