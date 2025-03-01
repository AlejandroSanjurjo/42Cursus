#include "push_swap.h"

static void	rotate_both(t_stack **a,
						t_stack **b,
						t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}

static void	reverse_rotate_both(t_stack **a,
								t_stack **b,
								t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

void	finish_rotation(t_stack **stack,
							t_stack *top_node,
							char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->abovemedian)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->abovemedian)
				rb(stack);
			else
				rrb(stack);
		}	
	}
}

static void	moves(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*b);
	if (cheapest_node->abovemedian
		&& cheapest_node->target_node->abovemedian)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->abovemedian)
		&& !(cheapest_node->target_node->abovemedian))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int				len_a;

	len_a = ft_len(*a);
	if (len_a == 5)
		sort_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		moves(a, b);
	}
	set_index(*a);
	smallest = find_min(*a);
	if (smallest->abovemedian)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}