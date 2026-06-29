/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guicarva <guicarva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 22:19:26 by guicarva          #+#    #+#             */
/*   Updated: 2026/06/24 15:34:51 by guicarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	*read_text(int fd, char *text)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	if (!text)
		text = ft_strdup("");
	if (!text)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(text), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(text, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(text), NULL);
		buffer[bytes_read] = '\0';
		temp = ft_join_free(text, buffer);
		if (!temp)
			return (free(buffer), NULL);
		text = temp;
	}
	free(buffer);
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = read_text(fd, text);
	if (!text || text[0] == '\0')
		return (free(text), text = NULL, NULL);
	if (ft_strchr(text, '\n'))
	{
		line = ft_substr(text, 0, ft_strchr(text, '\n') - text + 1);
		if (!line)
			return (free(text), text = NULL, NULL);
		temp = ft_strdup(ft_strchr(text, '\n') + 1);
		return (free(text), text = temp, line);
	}
	line = ft_strdup(text);
	return (free(text), text = NULL, line);
}

static void	checker_execute_command(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "pa\n"))
		pa(a, b, NULL);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b, NULL);
	else if (!ft_strcmp(line, "sa\n"))
		sa(a, NULL);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b, NULL);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b, NULL);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a, NULL);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b, NULL);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b, NULL);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a, NULL);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b, NULL);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b, NULL);
	else
		error_exit(a, b, NULL, line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv, NULL);
	b = NULL;
	assign_indexes(a);
	line = get_next_line(0);
	while (line)
	{
		checker_execute_command(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && !b)
		ft_printf(1, "OK\n");
	else
		ft_printf(1, "KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
