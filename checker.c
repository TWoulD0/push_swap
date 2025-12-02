#include "push_swap.h"
#include "get_next_line/get_next_line.h"

int ft_strlen(char *str)
{
    int i = 0;

    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);    
}

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while ((str1[i] || str2[i]))
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}


int is_valid_operation(char *line)
{
    int len;
    int i;

    if (!line)
        return (0);
    
    len = ft_strlen(line);
    if (len == 0)
        return (0);
    
    i = 0;
    while (line[i])
    {
        if (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
            return (0);
        i++;
    }

    if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0 ||
        ft_strcmp(line, "ss") == 0 || ft_strcmp(line, "pa") == 0 ||
        ft_strcmp(line, "pb") == 0 || ft_strcmp(line, "ra") == 0 ||
        ft_strcmp(line, "rb") == 0 || ft_strcmp(line, "rr") == 0 ||
        ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0 ||
        ft_strcmp(line, "rrr") == 0)
        return (1);
    
    return (0);
}

void sort_stack_no_print(char *line, t_stack *a, t_stack *b)
{
    if (ft_strcmp(line, "sa") == 0)
        sa(a, 0);
    else if (ft_strcmp(line, "sb") == 0)
        sb(b, 0);
    else if (ft_strcmp(line, "ss") == 0)
        ss(a, b, 0);
    else if (ft_strcmp(line, "pa") == 0)
        pa(a, b, 0);
    else if (ft_strcmp(line, "pb") == 0)
        pb(a, b, 0);
    else if (ft_strcmp(line, "ra") == 0)
        ra(a, 0);
    else if (ft_strcmp(line, "rb") == 0)
        rb(b, 0);
    else if (ft_strcmp(line, "rr") == 0)
        rr(a, b, 0);
    else if (ft_strcmp(line, "rra") == 0)
        rra(a, 0);
    else if (ft_strcmp(line, "rrb") == 0)
        rrb(b, 0);
    else if (ft_strcmp(line, "rrr") == 0)
        rrr(a, b, 0);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char *line;
    int len;

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
        write(1, "Error\n", 6);
        free_stack(stack_a);
        free_stack(stack_b);
        return (1);
    }

    while ((line = get_next_line(0)) != NULL)
    {
        len = ft_strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';
        
        if (!is_valid_operation(line))
        {
            write(1, "Error\n", 6);
            free(line);
            free_stack(stack_a);
            free_stack(stack_b);
            return (1);
        }
        sort_stack_no_print(line, stack_a, stack_b);
        free(line);
    }
    

    if (is_sorted(stack_a) && stack_b->size == 0)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);

    free_stack(stack_a);
    free_stack(stack_b);
    
    return (0);
}