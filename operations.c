#include "push_swap.h"

static void swap(t_stack *stack)
{
    int tmp;

    if (stack->size < 2)
        return;
    
    tmp = stack->array[0];
    stack->array[0] = stack->array[1];
    stack->array[1] = tmp;
}

void sa(t_stack *stack_a, int print)
{
    swap(stack_a);
    if (print)
        write(1, "sa\n", 3);
}

void sb(t_stack *stack_b, int print)
{
    swap(stack_b);
    if (print)
        write(1, "sb\n", 3);
}

void ss(t_stack *stack_a, t_stack *stack_b, int print)
{
    swap(stack_a);
    swap(stack_b);
    if (print)
        write(1, "ss\n", 3);
}

static void push(t_stack *dest, t_stack *src)
{
    int i;

    if (src->size == 0)
        return ;
    
    i = dest->size;
    while (i > 0)
    {
        dest->array[i] = dest->array[i - 1];
        i--;
    }
    dest->array[0] = src->array[0];
    dest->size++;

    i = 0;
    while (i < src->size - 1)
    {
        src->array[i] = src->array[i + 1];
        i++;
    }
    src->size--;
}

void pa(t_stack *stack_a, t_stack *stack_b, int print)
{
    push(stack_a, stack_b);
    if (print)
        write(1, "pa\n", 3);
}

void pb(t_stack *stack_a, t_stack *stack_b, int print)
{
    push(stack_b, stack_a);
    if (print)
        write(1, "pb\n", 3);
}

static void rotate(t_stack *stack)
{
    int i;
    int tmp;

    if (stack->size < 2)
        return ;
    i = 0;
    tmp = stack->array[0];
    while (i < stack->size - 1)
    {
        stack->array[i] = stack->array[i + 1];
        i++;
    }
    stack->array[i] = tmp;
}

void ra(t_stack *stack_a, int print)
{
    rotate(stack_a);
    if (print)
        write(1, "ra\n", 3);
}

void rb(t_stack *stack_b, int print)
{
    rotate(stack_b);
    if (print)
        write(1, "rb\n", 3);
}

void rr(t_stack *stack_a, t_stack *stack_b, int print)
{
    rotate(stack_a);
    rotate(stack_b);
    if (print)
        write(1, "rr\n", 3);
}

static void reverse_rotate(t_stack *stack)
{
    int i;
    int tmp;

    if (stack->size < 2)
        return ;
    i = stack->size - 1;
    tmp = stack->array[i];
    while (i > 0)
    {
        stack->array[i] = stack->array[i - 1];
        i--;
    }
    stack->array[0] = tmp;
}

void rra(t_stack *stack_a, int print)
{
    reverse_rotate(stack_a);
    if (print)
        write(1, "rra\n", 4);
}

void rrb(t_stack *stack_b, int print)
{
    reverse_rotate(stack_b);
    if (print)
        write(1, "rrb\n", 4);
}

void rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    if (print)
        write(1, "rrr\n", 4);
}