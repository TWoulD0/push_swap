#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
    int *array;
    int size;
    int capacity;
}   t_stack;

/* helper functions */
int is_sorted(t_stack *stack);
int find_min(t_stack *stack);
int find_position_of_min(t_stack *stack);
int find_target_position(t_stack *stack_a, int value);
t_stack *init_stack(int capacity);
void free_stack(t_stack *stack);

/* operations */
void sa(t_stack *stack_a, int print);
void sb(t_stack *stack_b, int print);
void ss(t_stack *stack_a, t_stack *stack_b, int print);
void pa(t_stack *stack_a, t_stack *stack_b, int print);
void pb(t_stack *stack_a, t_stack *stack_b, int print);
void ra(t_stack *stack_a, int print);
void rb(t_stack *stack_b, int print);
void rr(t_stack *stack_a, t_stack *stack_b, int print);
void rra(t_stack *stack_a, int print);
void rrb(t_stack *stack_b, int print);
void rrr(t_stack *stack_a, t_stack *stack_b, int print);

/* parsing functions */
int is_valid_number(char *str);
long ft_atol(char *str);
int has_duplicates(t_stack *stack);
int parse_arguments(int argc, char **argv, t_stack *stack_a);

/* sorting functions */
void sort_stack(t_stack *stack_a, t_stack *stack_b);

#endif