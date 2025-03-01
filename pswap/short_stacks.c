#include "push_swap.h"


static void move_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest;

    cheapest = get_cheapest(*a);
    if(cheapest->abovemedian && cheapest->target->abovemedian)
        rotate_both(a, b, cheapest);
    else if(!cheapest->abovemedian && !cheapest->target->abovemedian)
        rev_rotate_both(b, a, cheapest);
    prep_for_push(a, cheapest, 'a');
    prep_for_push(b, cheapest-target, 'b');
    pb(b, a, false);
}

static void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    prep_for_push(a, (*b)->target, 'a');
    pa(a, b, false);
}

static void min_on_top(t_stack_node **stacck)
{
    while((*stack)->data != find_min(*stack)->data)
    {
        if(find_min(*stack)->abovemedian)
            ra(stack, false);
        else
            rra(stack, false);
    }
}

void short_stacks(t_stack_node **a, t_stack_node **b)
{
    int len_a;
    
    len_a = stack_len(*a);
    if(len_a-- > 3 && !stack_sorted(*a))
    pb(b, a, false);
    if(len_a-- > 3 && !stack_sorted(*a))
    pb(b, a, false);
    while(len_a-- > 3 && !stack_sorted(*a))
    {
        init_nodes_a(*a, *b)
        move_a_to_b(a, b);
    }
    short_three(a);
    while(*b)
    {
        init_nodes_b(*a, *b);
        move_b_to_a(a, b);
    }
    current_index(*a);
    min_on_top(a);
}