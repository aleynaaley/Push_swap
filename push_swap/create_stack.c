/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:18:17 by alerkul           #+#    #+#             */
/*   Updated: 2024/07/01 18:18:17 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*last_node_find(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

static void	add_node(t_list **stack, t_list *new_node)
{
	t_list	*last_node;

	if (*stack)
	{
		last_node = last_node_find(*stack);
		last_node->next = new_node;
		new_node->next = NULL;
	}
	else
	{
		*stack = new_node;
		(*stack)->next = NULL;
	}
}

static t_list	*create_node(long value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

static void	space_check(char *str)
{
	size_t	space;
	size_t	i;

	i = 0;
	space = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			space++;
		i++;
	}
	if (space == i && space != 0)
		error();
	if (space == 0 && i == 0)
		exit(0);
}

void	create_stack(t_list **stack, int argc, char **argv)
{
	t_list	*node_point;
	char	**arg;
	int		i;

	i = 0;
	if (argc == 2)
	{
		space_check(argv[1]);
		arg = ft_split(argv[1], ' ');
	}
	else
	{
		i = 1;
		arg = argv;
	}
	while (arg[i])
	{
		node_point = create_node(ft_atoi(arg[i]));
		add_node(stack, node_point);
		i++;
	}
	stack_index(stack);
	if (argc == 2)
		ft_argfree(arg);
}
