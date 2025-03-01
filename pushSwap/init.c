#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (NULL == stack)
		return ;
	median = ft_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->abovemedian = true;
		else
			stack->abovemedian = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best;

	while (b)
	{
		best = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->data > b->data
				&& current_a->data < best)
			{
				best = current_a->data;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_len(a);
	len_b = ft_len(b);
	while (b)
	{
		b->cost = b->index;
		if (!(b->abovemedian))
			b->cost = len_b - (b->index);
		if (b->target_node->abovemedian)
			b->cost += b->target_node->index;
		else
			b->cost += len_a - (b->target_node->index);
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	long			best;
	t_stack	*best_node;

	if (NULL == b)
		return ;
	best = LONG_MAX;
	while (b)
	{
		if (b->cost < best)
		{
			best = b->cost;
			best_node = b;
		}
		b = b->next;
	}
	best_node->cheapest = true;
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target(a, b);
	set_cost(a, b);
	set_cheapest(b);
}
