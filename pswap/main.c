#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node *a;
    t_stack_node *b;

    a=NULL;
    b=NULL;
    if(argc == 1 || (argc==2 && !argv[1][0]))
        return (1);
    else if(argc == 2)
        argv = ft_split(argv[1], ' ');
    init_stack_a(&a, argv + 1);
    if(!stack_sorted(a))
    {
        if(stack_len == 2)
            sa(&a, false);
        else if(stack_len == 3)
            short_three(&a);
        else
            short_stack(&a, &b);
    }
    free_stack(&a);
   // free_stack(&b);
    return (0);
}