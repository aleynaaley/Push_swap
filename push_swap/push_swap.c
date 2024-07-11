/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:17:18 by alerkul           #+#    #+#             */
/*   Updated: 2024/07/01 18:17:18 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_list **stack)
{
	t_list	*here;
	t_list	*tmp;

	here = *stack;
	while (here)
	{
		tmp = here;
		here = here->next;
		free(tmp);
	}
	free(stack);
}

int	main(int argc, char **argv)
{
	t_list	**stacka;
	t_list	**stackb;

	if (argc < 2)
	{
		return (-1);
	}
	check_arg(argc, argv);
	stacka = (t_list **)malloc(sizeof(t_list));
	stackb = (t_list **)malloc(sizeof(t_list));
	*stacka = NULL;
	*stackb = NULL;
	create_stack(stacka, argc, argv);
	if (is_it_sorted(stacka))
	{
		free_stack(stacka);
		free_stack(stackb);
		return (0);
	}
	sort(stacka, stackb);
	free_stack(stacka);
	free_stack(stackb);
	return (0);
}
