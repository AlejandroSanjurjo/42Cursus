#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
    int	data; //numero a ordenar
    int	index; // posicion en la lista
    int push_cost; //costo de mover el numero a la pila contraria
    bool abovemedian; // si el numero esta arriba de la mediana
    bool cheapest; // si es el mas barato de mover
    struct s_stack_node *target; //puntero al nodo en la otra pila
    struct s_stack_node *next; //puntero al siguiente nodo
    struct s_stack_node *prev; //puntero al nodo anterior
}	t_stack_node;

//errors
int error_syntax(char *str);
int error_duplicate(t_stack_node *stack, int n);
void free_stack(t_stack_node **stack);
void free_errors(t_stack_node **stack);
//init
void init_nodes_a(t_stack_node *a, t_stack_node *b);
void set_cheapest(t_stack_node *stack);
void current_index(t_stack_node *stack);
void init_nodes_b(t_stack_node *a, t_stack_node *b);
void init_stack_a(t_stack_node **a, char **argv);
t_stack_node *get_cheapest(t_stack_node *stack);
void prep_for_push(t_stack_node **stack, t_stack_node *top_node, char name);
//utils
int stack_len(t_stack_node *stack);
t_stack_node *find_last_node(t_stack_node *stack);
bool stack_sorted(t_stack_node *stack);
t_stack_node *find_min(t_stack_node *stack);
t_stack_node *find_max(t_stack_node *stack);
char **ft_split(char *argv, char c);
//both
void rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
void revers_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest);
//operations
void sa(t_stack_node **a, bool print);
void sb(t_stack_node **b, bool print);
void ss(t_stack_node **a, t_stack_node **b, bool print);
void pa(t_stack_node **a, t_stack_node **b, bool print);
void pb(t_stack_node **a, t_stack_node **b, bool print);
void ra(t_stack_node **a, bool print);
void rb(t_stack_node **b, bool print);
void rr(t_stack_node **a, t_stack_node **b, bool print);
void rra(t_stack_node **a, bool print);
void rrb(t_stack_node **b, bool print);
void rrr(t_stack_node **a, t_stack_node **b, bool print);
//sort
void short_three(t_stack_node **a);
void short_stack(t_stack_node **a, t_stack_node **b);

#endif