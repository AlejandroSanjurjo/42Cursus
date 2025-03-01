#include "push_swap.h"

static long ft_atol(const char *str)
{
    long n;
    int sign;

    n = 0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        n = n * 10 + *str - '0';
        str++;
    }
    return (n * sign);
}

static void append_node(t_stack_node **stack, int n)
{
    t_stack_node *new;
    t_stack_node *last;

    if(!stack)
        return ;
    new = malloc(sizeof(t_stack_node));
    if(!node)
        return ;
    new->next = NULL;
    new->data = n;
    new->cheapest = 0;
    if(!(*stack))
    {
        *stack = new;
        new->prev = NULL;
        return ;
    }
    else
    {
        last = find_last_node(*stack);
        last->next = new;
        node->prev = last;
    }
}


void init_stack_a (t_stack_node **a, char **argv)
{
    long n;
    int i;

    i = 0;
    while(argv[i])
    {
        if(error_syntax)
            free_errors(a);
        n = ft_atol[argv[i]];
        if(n>INT_MAX || n<INT_MIN)
            free_errors(a);
        if(error_duplicate)
            free_errors(a);
        append_node(a, (int)n)
        i++;
    }
}

t_stack_node *get_cheapest(t_stack_node *stack)
{
    if(!stack)
        return (NULL);
    while(stack)
    {
        if(stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

void prep_for_push(t_stack_node **stack, t_stack_node *top_node, char name)
{
    while(*stack)
    {
        if(name =='a')
        {
            if(top_node->abovemedian)
                ra(stack, false);
            else
                rra(stack, false);
        }
        else if(name == 'b')
        {
            if(top_node->abovemedian)
                rb(stack, false);
            else
                rrb(stack, false);
        }

    }
}