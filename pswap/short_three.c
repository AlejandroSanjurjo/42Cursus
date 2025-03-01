#include "push_swap.h"

void short_three(t_stack_node **a)
{
    t_stack_node *biggest;
    biggest = find_max(*a);
    if(biggest == *a)
     ra(a, false);
     else if((*a)->next == biggest)
        rra(a, false);
    if((*a)->data > (*a)->next->data)
        sa(a, false);
}
