/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:18:49 by alerkul           #+#    #+#             */
/*   Updated: 2024/07/01 18:18:49 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		find;

	min = NULL;
	find = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!find || head->value < min->value))
			{
				min = head;
				find = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	stack_index(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = find_min(stack);
	while (head)
	{
		head->index = index;
		index++;
		head = find_min(stack);
	}
}
