/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: watoumi <watoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:12:33 by watoumi           #+#    #+#             */
/*   Updated: 2025/12/05 17:44:42 by watoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	*array;
	int	size;
	int	capacity;
}	t_stack;

typedef struct s_cost
{
	int	total;
	int	use_reverse_a;
	int	use_reverse_b;
	int	cost_a;
	int	cost_b;
}	t_cost;

/* operations */
void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b, int print);
void	pa(t_stack *stack_a, t_stack *stack_b, int print);
void	pb(t_stack *stack_a, t_stack *stack_b, int print);
void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b, int print);
void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b, int print);

/* parsing functions */
int		is_valid_number(char *str);
long	ft_atol(char *str);
int		has_duplicates(t_stack *stack);
int		parse_arguments(int argc, char **argv, t_stack *stack_a);
void	push_to_stack(t_stack *stack, int value);

/* sorting */
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
t_cost	calculate_cost(t_stack *stack_a, t_stack *stack_b, int pos_b);
int		is_sorted(t_stack *stack);
int		find_min(t_stack *stack);
int		find_position_of_min(t_stack *stack);
int		find_target_position(t_stack *stack_a, int value);
void	push_to_b_chunked(t_stack *stack_a, t_stack *stack_b);
void	make_move(t_stack *stack_a, t_stack *stack_b, t_cost *cost);
void	combo0(int pos_a, int pos_b, int *min_cost, int *best_combo);
void	combo1(int a_rev, int b_rev, int *min_cost, int *best_combo);
void	combo2(int pos_a, int b_rev, int *min_cost, int *best_combo);
void	combo3(int pos_b, int a_rev, int *min_cost, int *best_combo);
void	sort_stacka_in_arr(int **sorted, t_stack *stack_a);
int		find_next_in_chunk(t_stack *stack_a, int max_val);

/* split */
char	**ft_split(char *str);
int		is_there_space(char c);
int		word_len(char *str);
int		num_of_words(char *str);
void	free_split(char **split);

/* helper */
t_stack	*init_stack(int capacity);
void	free_stack(t_stack *stack);
int		arg_have_space(char *str);
int		count_total_numbers(int argc, char **argv);

/* checker helper */
int		ft_strlen(char *str);
int		ft_strcmp(const char *str1, const char *str2);
int		is_valid_operation(char *line);
void	sort_stack_no_print(char *line, t_stack *a, t_stack *b);

#endif