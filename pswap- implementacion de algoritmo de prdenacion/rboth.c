#include "push_swap.h"

void rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
    while(*b != cheapest->target && *a != cheapest)
        rr(a, b, false);
    current_index(*a);
    current_index(*b);
}

void revers_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
    while(*b != cheapest->target && *a != cheapest)
        rrr(a, b, false);
    current_index(*a);
    current_index(*b);
}