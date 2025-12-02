#include "push_swap.h"

// calculate cost to move element from B to A
typedef struct s_cost
{
    int total;
    int use_reverse_a;
    int use_reverse_b;
    int cost_a;
    int cost_b;

} t_cost;

t_cost calculate_cost(t_stack *stack_a, t_stack *stack_b, int pos_b)
{
    t_cost cost;
    int value_b = stack_b->array[pos_b];
    int pos_a = find_target_position(stack_a, value_b);

    int cost_b_normal = pos_b;
    int cost_b_reverse = stack_b->size - pos_b;

    int cost_a_normal = pos_a;
    int cost_a_reverse = stack_a->size - pos_a;

    int min_cost = INT_MAX;
    int best_combo = 0;

    // both rotate normally
    int combo0 = (cost_a_normal > cost_b_normal) ? cost_a_normal : cost_b_normal;
    if (combo0 < min_cost)
    {
        min_cost = combo0;
        best_combo = 0;
    }

    // both rotate reverse
    int combo1 = (cost_a_reverse > cost_b_reverse) ? cost_a_reverse : cost_b_reverse;
    if (combo1 < min_cost)
    {
        min_cost = combo1;
        best_combo = 1;
    }

    // a normal, b reverse
    int combo2 = cost_a_normal + cost_b_reverse;
    if (combo2 < min_cost)
    {
        min_cost = combo2;
        best_combo = 2;
    }
    
    // a reverse, b normal
    int combo3 = cost_a_reverse + cost_b_normal;
    if (combo3 < min_cost)
    {
        min_cost = combo3;
        best_combo = 3;
    }

    cost.total = min_cost;
    cost.use_reverse_a = (best_combo == 1 || best_combo == 3);
    cost.use_reverse_b = (best_combo == 1 || best_combo == 2);
    cost.cost_a = cost.use_reverse_a ? cost_a_reverse : cost_a_normal;
    cost.cost_b = cost.use_reverse_b ? cost_b_reverse : cost_b_normal;
    
    return cost;
}

// make the cheapest move
void make_move(t_stack *stack_a, t_stack *stack_b, t_cost cost)
{
    while (cost.cost_a > 0 && cost.cost_b > 0 &&
        cost.use_reverse_a == cost.use_reverse_b)
    {
        if (cost.use_reverse_a)
            rrr(stack_a, stack_b, 1);
        else
            rr(stack_a, stack_b, 1);
        cost.cost_a--;
        cost.cost_b--;
    }

    while (cost.cost_a > 0)
    {
        if (cost.use_reverse_a)
            rra(stack_a, 1);
        else
            ra(stack_a, 1);
        cost.cost_a--;     
    }
    
    while (cost.cost_b > 0)
    {
        if (cost.use_reverse_b)
            rrb(stack_b, 1);
        else
            rb(stack_b, 1);
        cost.cost_b--;     
    }
    
    pa(stack_a, stack_b, 1);
}

// sort 3 elements in stack a
void sort_three(t_stack *stack_a)
{
    int a = stack_a->array[0];
    int b = stack_a->array[1];
    int c = stack_a->array[2];

    if (a > b && b > c)
    {
        ra(stack_a, 1);
        sa(stack_a, 1);
    }
    else if (a > b && b < c && c > a)
        sa(stack_a, 1);
    else if (a > b && b < c && c < a)
        ra(stack_a, 1);
    else if (a < b && b > c && c < a)
        rra(stack_a, 1);
    else if (a < b && b > c && c > a)
    {
        sa(stack_a, 1);
        ra(stack_a, 1);
    }
}

int find_next_in_chunk(t_stack *stack_a, int max_val)
{
    for (int i = 0; i < stack_a->size; i++)
    {
        if (stack_a->array[i] <= max_val)
            return (i);
    }
    return (0);
}

// push elements to B using chunks strategy
void push_to_b_chunked(t_stack *stack_a, t_stack *stack_b)
{
    int size = stack_a->size;
    int *sorted = malloc(sizeof(int) * size);
    if (!sorted)
        return ;

    for (int i = 0; i < size; i++)
        sorted[i] = stack_a->array[i];

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (sorted[j] > sorted[j + 1])
            {
                int tmp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = tmp;
            } 
        } 
    }

    int num_chuncks = 3;
    if (size > 100)
        num_chuncks = 5;
    
    int chunk_size = size / num_chuncks;
    int pushed = 0;

    for (int chunk = 0; chunk < num_chuncks && stack_a->size > 3; chunk++)
    {
        int chunk_max = sorted[(chunk + 1) * chunk_size - 1];
        if (chunk == num_chuncks - 1)
            chunk_max = sorted[size - 4];

        int current_chunk_size = (chunk + 1) * chunk_size;
        if (chunk == num_chuncks - 1)
            current_chunk_size = size - 3;

        while (pushed < current_chunk_size && stack_a->size > 3)
        {
            if (stack_a->array[0] <= chunk_max)
            {
                pb(stack_a, stack_b, 1);
                pushed++;
            }
            else
            {
                int pos = find_next_in_chunk(stack_a, chunk_max);
                if (pos <= size / 2)
                    ra(stack_a, 1);
                else
                    rra(stack_a, 1);
            }            
        }
    }
    free(sorted);
}

void sort_stack(t_stack *stack_a, t_stack *stack_b)
{
    /*==== handle small stack ====*/
    if (stack_a->size == 2)
    {
        if (stack_a->array[0] > stack_a->array[1])
            sa(stack_a, 1);
        return;
    }
    
    if (stack_a->size == 3)
    {
        sort_three(stack_a);
        return;
    }

    /*==== handle big stack ====*/
    push_to_b_chunked(stack_a, stack_b);

    if (stack_a->size == 3)
        sort_three(stack_a);
    else if (stack_a->size == 2 && stack_a->array[0] > stack_a->array[1])
        sa(stack_a, 1);

    // push back to stack a by calculating the cost
    while (stack_b->size > 0)
    {
        t_cost less_cost = calculate_cost(stack_a, stack_b, 0);
        for (int i = 1; i < stack_b->size; i++)
        {
            t_cost current_cost = calculate_cost(stack_a, stack_b, i);
            if (current_cost.total < less_cost.total)
                less_cost = current_cost;    
        }
        
        make_move(stack_a, stack_b, less_cost);
    }

    // rotate stack a until min num in top
    int min_pos = find_position_of_min(stack_a);
    if (min_pos <= stack_a->size / 2)
    {
        while (min_pos > 0)
        {
            ra(stack_a, 1);
            min_pos--;
        }
    }
    else
    {
        while (min_pos < stack_a->size)
        {
            rra(stack_a, 1);
            min_pos++;
        } 
    }
    
}