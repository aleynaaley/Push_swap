

#include "push_swap.h"

static int	get_distance(t_list **stack, int index)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

static int	min_index(t_list **stack, int value)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != value)
			min = head->index;
	}
	return (min);
}

void	sort_3(t_list **a)
{
	t_list	*head;
	int		min;
	int		two_min;

	head = *a;
	min = min_index(a, -1);
	two_min = min_index(a, min);
	if (is_it_sorted(a))
		return ;
	if (head->index == min && head->next->index != two_min)
		sort_3_if(a);
	else if (head->index == two_min)
	{
		if (head->next->index == min)
			swap_sa(a);
		else
			swap_rra(a);
	}
	else
	{
		if (head->next->index == min)
			swap_ra(a);
		else
			sort_3_else(a);
	}
}

void	sort_4(t_list **a, t_list **b)
{
	int	distance;

	if (is_it_sorted(a))
		return ;
	distance = get_distance(a, min_index(a, -1));
	if (distance == 1)
		swap_ra(a);
	else if (distance == 2)
	{
		swap_ra(a);
		swap_ra(a);
	}
	else if (distance == 3)
		swap_rra(a);
	if (is_it_sorted(a))
		return ;
	swap_pb(a, b);
	sort_3(a);
	swap_pa(a, b);
}

void	sort_5(t_list **a, t_list **b)
{
	int	distance;

	distance = get_distance(a, min_index(a, -1));
	if (distance == 1)
		swap_ra(a);
	else if (distance == 2)
	{
		swap_ra(a);
		swap_ra(a);
	}
	else if (distance == 3)
	{
		swap_rra(a);
		swap_rra(a);
	}
	else if (distance == 4)
		swap_rra(a);
	if (is_it_sorted(a))
		return ;
	swap_pb(a, b);
	sort_4(a, b);
	swap_pa(a, b);
}
