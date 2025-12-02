#include "push_swap.h"

int is_sorted(t_stack *stack) // check if the stack is alredy sorted
{
    int i = 0;
    while (i < stack->size - 1)
    {
        if (stack->array[i] > stack->array[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int find_min(t_stack *stack) // find the smallest num in stack
{
    int i = 0;
    int min;
    min = stack->array[0];
    while (i < stack->size)
    {
        if (min > stack->array[i])
            min = stack->array[i];
        i++;
    }
    return (min);
}

int find_position_of_min(t_stack *stack)
{
    int i = 0;
    int min;
    int pos = 0;

    min = find_min(stack);
    while (i < stack->size)
    {
        if (min == stack->array[i])
        {
            pos = i;
            break ;
        }
        i++;
    }
    return (pos);
}

int find_target_position(t_stack *stack_a, int value)
{
    int target_pos = 0;
    int target_value = INT_MAX;
    for (int i = 0; i < stack_a->size; i++)
    {
        if (stack_a->array[i] > value && stack_a->array[i] < target_value)
        {
            target_value = stack_a->array[i];
            target_pos = i;
        }  
    }

    if (target_value == INT_MAX)
        target_pos = find_position_of_min(stack_a);
    
    return (target_pos);
}


t_stack *init_stack(int capacity) // create new empty stack with specific size
{

    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (0);
    stack->array = (int *)malloc(sizeof(int) * capacity);
    if (!stack->array)
    {
        free(stack);
        return (0);
    }
    stack->size = 0;
    stack->capacity = capacity;
    return (stack);
}

void free_stack(t_stack *stack)
{
    if (!stack)
        return ;
    if(stack->array)
        free(stack->array);
    free(stack);
}