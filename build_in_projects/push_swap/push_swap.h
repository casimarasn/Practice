/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:28:41 by msedeno-          #+#    #+#             */
/*   Updated: 2025/09/09 15:57:26 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_stack
{
	int				num;
	int				pos;
	int				chunk;
	int				cost_a;
	int				cost_b;
	int				t_cost;
	int				target_pos;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

// ./algorithm_chunk.c
int		find_pos(int num, int *sorted, int size);
int		find_max(t_stack *b);
int		find_min(t_stack *a);
int		find_min_pos(t_stack *a);

// ./algorithm_costs.c
void	set_target_pos(t_stack *a, t_stack *b);
t_stack	*cheapest_node(t_stack *b);
void	cheapest_to_a(t_stack **a, t_stack **b);

// ./arguments.c
char	*ft_strjoin_space(char const *s1, char const *s2);
int		ft_atoi_strict(const char *str, long *num);
char	*create_big_av(int ac, char **av);
char	**join_arguments(int ac, char **av);

// ./build_stack.c
int		*str_to_int(char **numbers, int count);
int		*copy_and_sort(int *arr, int count);
void	add_nodes(t_stack **stack_a, int *arr, int *sorted, int count);
t_stack	*build_stack(char **numbers);

// ./chunk_moves.c
int		chunk_count(int size);
void	assign_chunks(t_stack *stack, int size, int chunk_count);
int		has_chunk(t_stack *a, int chunk);
void	final_rotate_a(t_stack **a);
void	chunk_to_b(t_stack **a, t_stack **b, int chunk);

// ./cost_moves.c
void	calculate_costs(t_stack *a, t_stack *b);
void	move_a(t_stack **a, int cost_a);
void	move_b(t_stack **b, int cost_b);
void	update_pos(t_stack *stack);
void	push_back(t_stack **a, t_stack **b);

// ./distance_chunk.c
int		dist_to_min_chunk(t_stack *a, int chunk);
int		rev_dist_to_min_chunk(t_stack *a, int chunk);
int		dist_to_chunk(t_stack *a, int chunk);
int		rev_dist_to_chunk(t_stack *a, int chunk);
int		median_b(t_stack *b);

// ./free.c
void	free_stack(t_stack *stack);
void	free_array(char **str);
void	error(void);

// ./handle_numbers.c
void	rotate_to_min(t_stack **a, int min_pos, int size);
void	push_min_to_b(t_stack **a, t_stack **b);
void	handle_small_numbers(t_stack **a, t_stack **b, int num_chunks);
void	handle_large_numbers(t_stack **a, t_stack **b);
void	return_elements_to_a(t_stack **a, t_stack **b);

// ./is_valid.c
void	check_empty_str(char **numbers);
int		is_valid_char(char *s);
void	is_valid_args(int ac, char **av);
int		is_duplicated(char **numbers, int count);
int		is_sorted(t_stack *a);

// ./main.c
//void	print_stack_debug(t_stack *stack, char name);
void	print_stack(t_stack *stack, char name);
void	push_swap(t_stack **a, t_stack **b, int num_chunks);
int		main(int ac, char **av);

// ./multi_moves.c
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// ./ps_moves.c
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);

// ./push_swap.c
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	sort_medium(t_stack **a, t_stack **b);
void	sort_small(t_stack **a, t_stack **b);

// ./r_moves.c
void	ra( t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);

// ./utils_args.c
int		ft_isspace(int c);
void	sort_int_array(int *arr, int size);

// ./utils_stacks.c
t_stack	*stack_new(int num);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);

#endif