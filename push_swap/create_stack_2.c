/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:00:31 by alerkul           #+#    #+#             */
/*   Updated: 2024/07/01 15:00:36 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

s_list   *find_min(s_list **stack)
{
    s_list  *head;
    s_list  *min;
    int     find; // en küçük değeri bulup bulamadığımıza bakıyoruz

    min = NULL;
    find = 0;
    head = *stack;
    if (head)
    {
        while (head)
        {
            if((head->index == -1) && (!find || head->value  < min->value))  //indekslenmemiş ise ve min değer bulunmadıysa ya da yeni düğüm min olarak belirlenmişten küçük ise çalışır  
            {
                min = head;
                find = 1;
            }
            head = head->next;
        } 
    }
    return(min);
}

void    stack_index(s_list  **stack)
{
    s_list  *head;
    int     index;

    index = 0;
    head = find_min(stack); // find min indexlenmemiş düğümlelrin en küçük değerlisinden başlayarak getirir
    while (head)
    {
        head->index = index;
        index++;
        head = find_min(stack);  // en sonunda null olacak find min null döndürecek
    }
}
//düğümlere indeks atayacağız
