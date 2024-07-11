/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:41:04 by alerkul           #+#    #+#             */
/*   Updated: 2024/07/06 14:41:04 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_value;
	int		tmp_index;

	if (list_size(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	tmp_value = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_value;
	next->index = tmp_index;
	return (0);
}

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (list_size(*stack) < 2)
		return (-1);
	head = *stack;
	tail = last_node_find(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (list_size(*stack) < 2)
		return (-1);
	head = *stack;
	tail = last_node_find(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (list_size(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	*stack_from = head_from->next;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}
