#include "push_swap.h"

void current_index(t_stack_node *stack)
{
    int i;
    int median;

    i = 0;
    if(!stack)
        return ;
    median = stack_len(stack) / 2;
    while(stack)
    {
        stack->index = i;
        if(i > median)
            stack->abovemedian = false;
        else
            stack->abovemedian = true;
        stack = stack->next;
        i++;
    }
}

static void set_target_a(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *current;
    t_stack_node *target;
    long best_match_index;

    while(a)
    {
        best_match_index = LONG_MIN;
        current = b;
        while(current)
        {
            if(current->data < a->data && current->index > best_match_index)
            {
                best_match_index = current->data;
                target = current;
            }

            current = current->next;
        }
        if(best_match_index == LONG_MIN)
            a->target = find_max(b);
        else
            a->target = target;
        a = a->next;
    }
}

static void cost_analysis(t_stack_node *a, t_stack_node *b)
{
    int len_a;
    int len_b;

    len_a = stack_len(a);
    len_b = stack_len(b);
    while(a)
    {
        a->push_cost = a->index;
        if(!a->abovemedian)
            a->push_cost = len_a - (a->index);
        if(a->target->abovemedian)
            a->push_cost += (a->target->index);
        else
            a->push_cost += len_b - (a->target->index);
        a = a->next;
    }
}
void set_cheapest(t_stack_node *stack)
{
    t_stack_node *cheapest;
    long cheapest_value;

    if(!stack)
        return ;
    cheapest_value = LONG_MAX;
    while(stack)
    {
        if(stack->push_cost < cheapest_value)
        {
            cheapest_value = stack->push_cost;
            cheapest = stack;
        }
        stack = stack->next;
    }
    cheapest->cheapest = true;
}

void init_nodes_a(t_stack_node *a, t_stack_node *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    cost_analysis(a, b);
    set_cheapest(a);
}