#include "push_swap.h"

void push(t_stack_node **dest, t_stack_node **src)
{
    t_stack_node *tmp;
    
    if(!*src)
        return ;
    tmp = *src;
    *src = (*src)->next;
    if(*src)
        (*src)->prev = NULL;
    tmp->prev = NULL;
    if(!*dest)
    {
        *dest = tmp;
        tmp->next = NULL;
    }
    else
    {
        tmp->next = *dest;
        tmp->next->prev = tmp;
        *dest = tmp;
    }
}

void pa(t_stack_node **a, t_stack_node **b, bool print)
{
    push(a, b);
    if(!print)
        write(1, "pa\n", 3);
}

void pb(t_stack_node **a, t_stack_node **b, bool print)
{
    push(b, a);
    if(!print)
        write(1, "pb\n", 3);
}