/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 22:54:50 by guilh             #+#    #+#             */
/*   Updated: 2026/06/24 15:29:22 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_flags(char *args, t_bench *bench)
{
	if (!ft_strcmp(args, "--bench"))
		bench->active = 1;
	if (!ft_strcmp(args, "--simple"))
	{
		bench->algorithm = 1;
		bench->strategy = "Simple / O(n²)";
	}
	else if (!ft_strcmp(args, "--medium"))
	{
		bench->algorithm = 2;
		bench->strategy = "Medium / O(n√n)";
	}
	else if (!ft_strcmp(args, "--complex"))
	{
		bench->algorithm = 3;
		bench->strategy = "Complex / O(n log n)";
	}
}

static int	is_flags(char *args)
{
	if (!ft_strcmp(args, "--simple"))
		return (1);
	if (!ft_strcmp(args, "--medium"))
		return (1);
	if (!ft_strcmp(args, "--complex"))
		return (1);
	if (!ft_strcmp(args, "--adaptive"))
		return (1);
	if (!ft_strcmp(args, "--bench"))
		return (1);
	return (0);
}

static int	ft_atoi(const char *n_str, long *n)
{
	int		i;
	long	sinal;
	long	dest;

	i = 0;
	sinal = 1;
	dest = 0;
	if (n_str[i] == '+' || n_str[i] == '-')
		if (n_str[i++] == '-')
			sinal *= -1;
	if (!n_str[i])
		return (1);
	while (n_str[i] && (n_str[i] >= '0' && n_str[i] <= '9'))
		dest = (dest * 10) + (n_str[i++] - '0');
	dest = (dest * sinal);
	if (n_str[i])
		return (1);
	if (dest > (long)INT_MAX || dest < (long)INT_MIN)
		return (1);
	*n = dest;
	return (0);
}

static void	create_stack(t_stack **stack, char **args, t_bench *bench)
{
	t_stack	*new_node;
	int		i;
	long	n;

	i = 0;
	while (args[i])
	{
		if (is_flags(args[i]))
		{
			set_flags(args[i], bench);
			i++;
			continue ;
		}
		if (ft_atoi(args[i], &n))
			error_exit(stack, NULL, args, NULL);
		if (is_duplicate(*stack, n))
			error_exit(stack, NULL, args, NULL);
		new_node = ft_circular_newnode(n);
		if (!new_node)
			error_exit(stack, NULL, args, NULL);
		ft_circular_add_back(stack, new_node);
		i++;
	}
}

t_stack	*parse_args(int argc, char **argv, t_bench *bench)
{
	t_stack	*stack;
	char	**args;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			error_exit(&stack, NULL, NULL, NULL);
		args = ft_split(argv[i], ' ');
		if (!args || !args[0])
			error_exit(&stack, NULL, args, NULL);
		create_stack(&stack, args, bench);
		free_args(args);
		i++;
	}
	return (stack);
}
