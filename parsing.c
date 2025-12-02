#include "push_swap.h"

int is_valid_number(char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}


long ft_atol(char *str)
{
    long result;
    int sign;
    int i;

    result = 0;
    i = 0;
    sign = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;  
        i++;
    }
    while (str[i])
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

int has_duplicates(t_stack *stack)
{
    int i;
    int j;

    i = 0;
    while (i < stack->size)
    {
        j = i + 1;
        while (j < stack->size)
        {
            if (stack->array[i] == stack->array[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void push_to_stack(t_stack *stack, int value)
{
    if (!stack || stack->size == stack->capacity)
        return ;
    stack->array[stack->size] = value;
    stack->size++;
}

int parse_arguments(int argc, char **argv, t_stack *stack_a)
{
    int i;
    long num;

    i = 1;
    while (i < argc)
    {

        if (!is_valid_number(argv[i]))
            return (0);

        num = ft_atol(argv[i]);

        if (num > INT_MAX || num < INT_MIN)
            return (0);

        push_to_stack(stack_a, (int)num);
        i++;
    }
    if (has_duplicates(stack_a))
        return (0);
    return (1);
}