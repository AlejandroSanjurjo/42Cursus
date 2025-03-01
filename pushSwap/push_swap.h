#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack
{
	int					data;
	int					index;
	int					cost;
	bool				abovemedian;
	bool				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;	

//*** Handle input ./push_swap "1 -42 1337" ***
char			**ft_split(char *str, char separator);

//*** Handle errors-free ***
void			free_matrix(char **argv);
void			error_free(t_stack **a, char **argv, bool flag_argc_2);
void			free_stack(t_stack **stack);
int				duplicated_error(t_stack *a, int nbr);
int				nonumerror(char *str_nbr);

//*** Stack creation ***
void			stack_init(t_stack **a, char **argv, bool flag_argc_2);
void			init_nodes(t_stack *a, t_stack *b);
void			set_index(t_stack *stack);
void			set_cost(t_stack *a, t_stack *b);
void			set_cheapest(t_stack *b);

//*** linked list utils ***
void			append_node(t_stack **stack, int nbr);
t_stack	*find_last(t_stack *head);
t_stack	*find_min(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
bool			sorted(t_stack *stack);
int				ft_len(t_stack *stack);
void			finish_rotation(t_stack **s, t_stack *n, char c);

//*** Algorithms ***
void			sort_three(t_stack **a);
void			sort_five(t_stack **a, t_stack **b);
void			push_swap(t_stack **a, t_stack **b);

//*** Commands ***
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **b, t_stack **a);

#endif