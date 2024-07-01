/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:01:17 by alerkul           #+#    #+#             */
/*   Updated: 2024/07/01 15:01:18 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

int	reverse_rotate(s_list **stack)
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
	if ((list_size(*a) < 2) || (list_size(*b) < 2))
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

int	swap_rb(s_list **b)
{
	if (rotate(b) == -1)
		return (-1);
    write(1,"rb\n",3);
    return (0);
}

int	swap_rr(s_list **a, s_list **b)
{
	if ((list_size(*a) < 2) || (list_size(*b) < 2))
		return (-1);
	rotate(a);
	rotate(b);
    write(1,"rr\n",3);
	return (0);
}

int	swap_rra(s_list **a)
{
	if (reverse_rotate(a) == -1)
		return (-1);
    write(1,"rra\n",4);
	return (0);
}
int	swap_rrb(s_list **b)
{
	if (reverse_rotate(b) == -1)
		return (-1);
    write(1,"rrb\n",4);
	return (0);
}
int	swap_rrr(s_list **a,s_list **b)
{
	if ((list_size(*a) < 2) || (list_size(*b) < 2))
		return (-1);
	reverse_rotate(a);
	reverse_rotate(b);
    write(1,"rrb\n",4);
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
