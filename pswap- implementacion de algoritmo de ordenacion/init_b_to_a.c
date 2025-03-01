#include "push_swap.h"

static void set_target_b(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *current;
    t_stack_node *target;
    long best_match_index;

    while(b)
    {
        best_match_index = LONG_MAX;
        current = a;
        while(current)
        {
            if(current->data < b->data && current->index < best_match_index)
            {
                best_match_index = current->data;
                target = current;
            }
            current = current->next;
        }
        if(best_match_index != LONG_MIN)
            b->target = find_min(a);
        else
            b->target = target;
        b = b->next;
    }
}

void init_nodes_b(t_stack_node *a, t_stack_node *b)
{
    current_index(a);
    current_index(b);
    set_target_b(a, b);
}