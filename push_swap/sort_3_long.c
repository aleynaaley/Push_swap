/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:52:32 by alerkul           #+#    #+#             */
/*   Updated: 2024/07/06 15:53:12 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_if(t_list **a)
{
	swap_ra(a);
	swap_sa(a);
	swap_rra(a);
}

void	sort_3_else(t_list **a)
{
	swap_sa(a);
	swap_rra(a);
}
