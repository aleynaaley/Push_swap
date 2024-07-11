/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:59:41 by alerkul           #+#    #+#             */
/*   Updated: 2024/07/01 17:59:41 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_it_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	list_size(t_list *node)
{
	t_list	*tmp;
	int		i;

	tmp = node;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static void	little_sort(t_list **a, t_list **b)
{
	int	len;

	if (is_it_sorted(a) || list_size(*a) == 0 || list_size(*a) == 1)
		return ;
	len = list_size(*a);
	if (len == 2)
		swap_sa(a);
	else if (len == 3)
		sort_3(a);
	else if (len == 4)
		sort_4(a, b);
	else if (len == 5)
		sort_5(a, b);
}

void	sort(t_list **a, t_list **b)
{
	if (list_size(*a) <= 5)
		little_sort(a, b);
	else
		radix_sort(a, b);
}
