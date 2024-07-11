/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:47:27 by alerkul           #+#    #+#             */
/*   Updated: 2024/07/06 15:00:44 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_sa(t_list **a)
{
	if (swap(a) == -1)
		return (-1);
	write(1, "sa\n", 3);
	return (0);
}

int	swap_ra(t_list **a)
{
	if (rotate(a) == -1)
		return (-1);
	write(1, "ra\n", 3);
	return (0);
}

int	swap_rra(t_list **a)
{
	if (reverse_rotate(a) == -1)
		return (-1);
	write(1, "rra\n", 4);
	return (0);
}

int	swap_pa(t_list **a, t_list **b)
{
	if (push(a, b) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	swap_pb(t_list **a, t_list **b)
{
	if (push(b, a) == -1)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}
