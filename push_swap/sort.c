/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:01:04 by alerkul           #+#    #+#             */
/*   Updated: 2024/07/01 15:01:06 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int is_it_sorted(s_list **stack)
{
    s_list  *head;

    head = *stack;
    while(head && head->next)
    {
        if( head->value >   head->next->value)
            return (0);
        head = head->next;
    }
    return (1);
}

int list_size(s_list *node)
{
    int i;
    s_list  *tmp;
    tmp = node;
    i = 0;
    while(tmp)
    {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

void    little_sort(s_list  **a, s_list **b)
{
    int len;  //listenin uzunluğunu tuatacak

    if(is_it_sorted(a) || list_size(*a) == 0 || list_size(*a) == 1)
        return;
    len = list_size(*a);
    if(len == 2)
        swap_sa(a);
    else if (len == 3)
        sort_3(a);
    else if (len == 4)
        sort_4(a,b);
    else if(len == 5)
        sort_5(a,b);
}


void sort(s_list **a, s_list **b)
{
    if(list_size(*a) <= 5)
        little_sort(a,b);
    else
        radix_sort(a,b);
}
