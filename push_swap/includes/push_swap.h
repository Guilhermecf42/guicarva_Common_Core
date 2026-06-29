/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:06:57 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/24 16:07:39 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef A
#  define A 0
# endif

# ifndef B
#  define B 1
# endif

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_bench
{
	double	disorder;
	char	*strategy;
	int		active;
	int		algorithm;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_bench;

// Operations
void	pa(t_stack **a, t_stack **b, t_bench *bench);
void	pb(t_stack **a, t_stack **b, t_bench *bench);
void	sa(t_stack **a, t_bench *bench);
void	sb(t_stack **b, t_bench *bench);
void	ss(t_stack **a, t_stack **b, t_bench *bench);
void	ra(t_stack **a, t_bench *bench);
void	rb(t_stack **b, t_bench *bench);
void	rr(t_stack **a, t_stack **b, t_bench *bench);
void	rra(t_stack **a, t_bench *bench);
void	rrb(t_stack **b, t_bench *bench);
void	rrr(t_stack **a, t_stack **b, t_bench *bench);

// Ft_printf
int		ft_printf(int fd, const char *format, ...);
int		ft_putchr(int c, int fd);
int		ft_putnbr_h(unsigned long nbr, char *base, int fd);
int		ft_putnbr_u(unsigned int n, int fd);
int		ft_putnbr(long n, int fd);
int		ft_putstr(char *s, int fd);

// Get_next_line
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_join_free(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

// turk
int		get_min_pos(t_stack *stack);
int		get_max_pos(t_stack *stack);
int		get_target_b_pos(t_stack *b, int index_a);
int		get_target_a_pos(t_stack *a, int index_b);
void	rotate_single_a(t_stack **a, int pos_a, int size_a, t_bench *bench);
void	rotate_single_b(t_stack **b, int pos_b, int size_b, t_bench *bench);
void	execute_move(t_stack **a, t_stack **b, int *best, t_bench *bench);
void	turk_sort(t_stack **a, t_stack **b, t_bench *bench);

// Algorithm
void	simple_3low(t_stack **stack, t_bench *bench);
void	k_sort(t_stack **a, t_stack **b, t_bench *bench);
void	sort_simple(t_stack **a, t_stack **b, t_bench *bench);
void	radix_sort(t_stack **a, t_stack **b, t_bench *bench);

// make_stack
t_stack	*parse_args(int argc, char **argv, t_bench *bench);
void	assign_indexes(t_stack *stack);
t_stack	*ft_circular_newnode(int value);
void	ft_circular_add_back(t_stack **lst, t_stack *new_node);

// Free
void	error_exit(t_stack **a, t_stack **b, char **args, char *line);
void	free_stack(t_stack **stack);
void	free_args(char **args);

// utils
char	**ft_split(char const *s, char c);
int		ft_stack_size(t_stack *stack);
int		ft_strcmp(char *s1, char *s2);
int		is_sorted(t_stack *stack);
int		is_duplicate(t_stack *stack, int n);

#endif
