#include "push_swap.h"

int error_syntax(char *str)
{
    if(!(*str == '-' || *str == '+' || (*str >= '0' && *str <= '9')))
        return(1);
    if((*str == '-' || *str == '+') && !(str[1]>= '0' && str[1] <= '9'))
        return(1);
    while(*++str)
    {
        if(!(*str >= '0' && *str <= '9'))
            return(1);
    }
    return(0);
}

int error_duplicate(t_stack_node *stack, int n)
{
    if(!stack)
        return(0);
    while(stack)
    {
        if(stack->data == n)
            return(1);
        stack = stack->next;
    }
    return(0);
}

void free_stack(t_stack_node **stack)
{
    t_stack_node *tmp;
    t_stack_node *current;

    if(!stack)
        return ;
    current= *stack;
    while(current)
    {
        tmp = current->next;
        current->data = 0;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}

void free_errors(t_stack_node **stack)
{
    free_stack(stack);
    write(2, "Error\n", 6);
    exit(1);
}