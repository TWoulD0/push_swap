#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
        return (0);

    stack_a = init_stack(argc - 1);
    stack_b = init_stack(argc - 1);

    if (!stack_a || !stack_b)
    {
        free_stack(stack_a);
        free_stack(stack_b);
        return (1);
    }

    if (!parse_arguments(argc, argv, stack_a))
    {
        write(2, "Error\n", 6);
        free_stack(stack_a);
        free_stack(stack_b);
        return (1);
    }

    if (is_sorted(stack_a))
    {
        free_stack(stack_a);
        free_stack(stack_b);
        return (0);
    }

    sort_stack(stack_a, stack_b);

    // for (int i = 0; i < stack_a->size; i++)
    // {
    //     printf("%d ", stack_a->array[i]);
    // }
    // printf("\n");

    free_stack(stack_a);
    free_stack(stack_b);
    
    return (0);
}