/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximart <maximart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:52:13 by maximart          #+#    #+#             */
/*   Updated: 2024/12/15 12:15:57 by maximart         ###   ########.fr       */
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

# include "super_libft/include/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack	*prev;
	struct s_stack	*next;
}		t_stack;

typedef struct s_data
{
	int	med;
	int	q1;
	int	q2;
	int	size;
}		t_data;

int main(int argc, char **argv);
int	stack_lstsize(t_stack *lst);
int	check_num(const char *str);
int	check_dup(int argc, char **argv);
int	check_int_min_max(int argc, char **argv);


t_stack	*stack_lstnew(int value);
t_stack	*stack_lstlast(t_stack *lst);
void	stack_lstadd_back(t_stack **lst, t_stack *new);
void	free_stack(t_stack **stack);

int	stack_is_sorted(t_stack *stack);
void	sort_three(t_stack **stack_a);
int find_min(t_stack *stack);
int find_max(t_stack *stack);
int find_index(t_stack *stack, int value);
int	find_position(t_stack *stack, int target);

void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rrb(t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

void	calcul_quartils(t_data **data, int len, t_stack *stack);
int	get_nth_value(t_stack *stack, int n);



#endif