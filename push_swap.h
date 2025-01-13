/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:52:13 by maximart          #+#    #+#             */
/*   Updated: 2025/01/13 11:29:26 by maximart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RESET "\033[39m"
# define ORANGE "\033[33m"
# define GRAY "\033[33m"
# define RED "\033[91m"
# define GREEN "\033[92m"
# define YELLOW "\033[93m"
# define BLUE "\033[94m"
# define MAGENTA "\033[95m"
# define CYAN "\033[96m"
# define WHITE "\033[97m"

# include "./libft/include/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

typedef struct s_data
{
	int	med;
	int	q1;
	int	q2;
	int	size;
}		t_data;

t_stack	*stack_lstnew(int value);
t_stack	*stack_lstlast(t_stack *stack);
t_stack	*add_to_list(t_stack **stack, int value);
t_stack	*get_nth_node(t_stack *stack, int n);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		check_num(const char *str);
int		stack_lstsize(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
int		check_dup(int argc, char **argv);
int		check_error(int argc, char **argv);
int		find_index(t_stack *stack, int value);
int		check_int_min_max(int argc, char **argv);
int		find_position(t_stack *stack, int target);
int		get_best_move(t_stack *stack_a, t_stack *stack_b);
int		elem_in_first_quartils(t_stack *stack, int q1, int q2);
long	ft_atol(const char *str);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	free_stack(t_stack **stack);
void	free_stack(t_stack **stack);
void	sort_three(t_stack **pile_a);
void	replace_stack(t_stack **stack);
void	quick_sort_stack(t_stack **stack);
void	ft_rr(t_stack **s_a, t_stack **s_b);
void	ft_rrr(t_stack **s_a, t_stack **s_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	fill_data(t_data **data, int size, t_stack *stack);
void	ft_sort(t_stack **stack_a, t_stack **stack_b, t_data *data);
void	get_median_quartil(t_stack **stack, int size, t_data **data);
void	insertion_sort(t_stack **stack_a, t_stack **stack_b, int b_move);
void	push_a_optimize(t_stack *stack_a, t_stack *stack_b, t_data *data);
#endif