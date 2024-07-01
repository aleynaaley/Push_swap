/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:00:15 by alerkul           #+#    #+#             */
/*   Updated: 2024/07/01 15:00:17 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

s_list  *last_node_find(s_list *head)
{
    s_list  *tmp;
    tmp = head; //head listenin başını işaret edern işaretçi tmp tutacak
    while (tmp->next)  //hep bir sonraki olduğu sürece
    {
        tmp = tmp->next;  //buradn emin misin?
    }
    return (tmp);
}


void    add_node(s_list **stack, s_list *new_node)
{
    s_list *last_node;
    if(*stack) //eğer liste boş değilse son düğüme gitmeliyiz
    {
        last_node = last_node_find(*stack) ;
        last_node->next = new_node;
        new_node->next = NULL;   // sadece önlem ve okunabilirlilikiçin tekrar null ladım . listenin sonunda olduğunu göstermek için
    }
    else
    {
        *stack = new_node;
        (*stack)->next = NULL; //YENİ DÜĞÜMÜN NEXTİ NULL OLUR SON VE TEK DÜĞÜM OLDUĞU İÇİN
    }
}

s_list  *create_node(long value)  //atoiden dolayı long türü s_list çünkü dönüşü o türde düğüm pointer olacak
{
    s_list  *new_node;

    new_node =(s_list *)malloc(sizeof(*new_node));
    if(!new_node)
        return (NULL);
    new_node->value = value;
    new_node->index = -1;
    new_node->next = NULL;
    return(new_node);
}

void create_stack(s_list **stack, int argc , char **argv)
{
    s_list *node_point; //yeni listenin düğümünün işaretçisi
    char **arg;  // argümanları tutacak
    int i;

    i=0;
    if(argc == 2)
        arg = ft_split(argv[1] , ' '); 
    else
    {
        i = 1;
        arg = argv;
    }
    while(arg[i])
    {
        node_point = create_node(ft_atoi(arg[i]));  //burada değerler için tek tek düğüm oluşturacaksın 
        add_node(stack, node_point); // düğümleri de burada stacke  ekler
        i++;
    }
    stack_index(stack);
    if(argc == 2)
        ft_argfree(arg);
}
