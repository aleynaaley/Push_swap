
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
