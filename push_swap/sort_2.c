
#include "push_swap.h"


int swap(s_list **stack)  // ilk iki düğümün indekslerinin ve değerlerinin yerin değiştir 
{
    s_list  *head;
    s_list  *next;
    int tmp_value;
    int tmp_index;

    if(list_size(*stack) < 2 )
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

int	rotate(s_list **stack)  //ilk düğümü sona taşır 
{
	s_list	*head;  //ilk düğüm
	s_list	*tail;   //son düğüm

	if (list_size(*stack) < 2)
		return (-1);
	head = *stack;
	tail = last_node_find(head);
	*stack = head->next;  //stackin başlangıçı ikinci düğüm oldu
	head->next = NULL;    // ilk düğüm son olduğu için nexti null yaptık
	tail->next = head;    //tail yani son düğümün nexti de head oldu
	return (0);
}

int	reverseRotate(s_list **stack)
{
	s_list	*head;
    s_list	*tail;

	if (list_size(*stack) < 2)
		return (-1);
	head = *stack;
	tail = last_node_find(head);
	while (head)
	{
		if (head->next->next == NULL)  //son düğümden önceki düğümü buluyr ve null yapıyro
		{
			 head->next = NULL;
			 break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
} //stacki tamamen ters döndürür (1-2-3) ( 3-1-2)


int	push(s_list **stack_to, s_list **stack_from)
{
	s_list	*tmp;
	s_list	*head_to;
	s_list	*head_from;

	if (list_size(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;  //taşınacak değeri geçici ttuyoruz
	*stack_from = head_from->next;  //gönderen stacki bir ilerlettik 
	if (!head_to)                  //gönderilecek yer boş ise  
	{
		head_to = tmp;            //gönderilen değeri ilk düğüm yap
		head_to->next = NULL;        // sonrakini de null yap
		*stack_to = head_to;        //
	}
	else                                //boş değil ise
	{
		tmp->next = head_to;          // tuttuğumuz değerin nexti ilk değer olsun
		*stack_to = tmp;
	} 
	return (0);
}//stack fromdan to ya bir düğüm atanır


int    swap_sa(s_list  **a)
{
    if(swap(a) == -1)
        return (-1);
    write(1,"sa\n",3);
    return (0);
}

int	    swap_sb(s_list **b)
{
	if (swap(b) == -1)
		return (-1);
    write(1,"sb\n",3);
	return (0);
}

int	swap_ss(s_list **a, s_list **b)
{	
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (-1);
	swap(a);
	swap(b);
    write(1,"ss\n",3);
    return (0);
}

int	swap_ra(s_list **a)
{
	if (rotate(a) == -1)
		return (-1);
    write(1,"ra\n",3);
    return (0);
}

int	swap_rra(s_list **a)
{
	if (reverse_rotate(a) == -1)
		return (-1);
    write(1,"rra\n",4);
	return (0);
}

int	swap_pa(s_list **a, s_list **b)
{
	if (push(a, b) == -1)
		return (-1);
    write(1,"pa\n",3);
	return (0);
}
int	swap_pb(s_list **a, s_list **b)
{
	if (push(b, a) == -1)
		return (-1);
    write(1,"pb\n",3);
	return (0);
}