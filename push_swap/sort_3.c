/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:01:29 by alerkul           #+#    #+#             */
/*   Updated: 2024/07/01 15:01:31 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	get_distance(s_list **stack, int index)
{
	s_list	*head;
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

int  min_index(s_list **stack, int value)
{
    s_list  *head;
    int     min;

    head = *stack;
    min = head->index;
    while (head->next)  //listenin sonuna geldimi kontrol ediyorum
    {
        head = head->next;
        if((head->index < min) && head->index != value)
            min = head->index;
    }
    return(min);
}
//verilen stackte belirli bir değerden farklı olan en küçük indexli düğümü bulur


void sort_3(s_list **a)
{
    s_list  *head;
    int min;
    int two_min;

    head = *a;
    min = min_index(a,-1);
    two_min = min_index(a,min);
    if(is_it_sorted(a))
        return;
    if(head->index == min && head->next->index != two_min)     //ilk düğümün en küçük olması (0 2 1)
    {
        swap_ra(a);
        swap_sa(a);
        swap_rra(a);   ///burayı rra sa ile de dene daha kısalacak mı?
    }
    else if(head->index == two_min)   // ilk düğüm 1. index ise (1 0 2)(1 2 0)
    {
        if(head->next->index == min)
            swap_sa(a);
        else
            swap_rra(a);
    }
    else                         // (2 0 1) (2 1 0)
    {
        if(head->next->index == min)
            swap_ra(a);
        else
        {
            swap_sa(a);
            swap_rra(a);
        }
    }
}

void	sort_4(s_list **a, s_list **b)
{
	int	distance;

	if (is_it_sorted(a))
		return ;
	distance = get_distance(a, min_index(a, -1)); //en küçük düğümün heade uzaklığını buluyoruz
	if (distance == 1)  //ise bir rotate işe yarar
		swap_ra(a);     // (5-1-4-3) (1-4-3-5) 
	else if (distance == 2) //( 3-5-1-4) (5-1-4-3) (1-4-3-5)
	{
		swap_ra(a);
		swap_ra(a);
	}
	else if (distance == 3)  //(5-3-4-1) (1-5-3-4)
		swap_rra(a);
	if (is_it_sorted(a))  
		return ;
	swap_pb(a, b);   //min en üstte bunu b ye taşı
	sort_3(a);  //sonra kalan 3 ü sırala ve en son b dekini geri a ya ata
	swap_pa(a, b);
}

void    sort_5(s_list **a,s_list **b)
{
    int distance;
    distance = get_distance(a, min_index(a, -1));
    if (distance == 1)
		swap_ra(a);
    else if (distance == 2)   //
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
	sort_4(a,b);
	swap_pa(a, b);
}
