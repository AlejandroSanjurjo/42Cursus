#include "push_swap.h"

bool	sorted(t_stack *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack	*find_max(t_stack *stack)
{
	int				highest;
	t_stack	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->data > highest)
		{
			highest = stack->data;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}


void	sort_three(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = find_max(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}


void	sort_five(t_stack **a, t_stack **b)
{
	while (ft_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_min(*a), 'a');
		pb(b, a);
	}
}
