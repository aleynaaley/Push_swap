/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:58:22 by alerkul           #+#    #+#             */
/*   Updated: 2024/07/01 14:58:29 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

//kontrol et 
void    free_stack(s_list **stack)
{
    s_list  *here;  //mevcut düğümü tutsun
    s_list  *tmp;   //mevcut düğümü freelemek için
    here = *stack;   //gönderilen stackin ilk düğümünü atadık
    while(here)
    {
        tmp = here;
        here = here->next;
        free(tmp);   //listenin düğümleri
    }
    free(stack); //stack pointerının freelenmesi gerek 
//Bir bağlı liste (linked list) yapısını bellekten serbest bırakırken, önce elemanları tek tek
//serbest bırakıyoruz ve ardından işaretçiyi (yani listenin başını tutan adresi) serbest bırakıyoruz.
//Bu sayede hem elemanlar hem de listenin kendisi bellekten temizlenmiş olur
}

int main(int argc, char **argv)
{
    s_list  **stacka;
    s_list  **stackb;

    if(argc < 2)
    {
        return (-1);
    }
    check_arg(argc,argv);
    stacka = (s_list **)malloc(sizeof(s_list));
    stackb = (s_list **)malloc(sizeof(s_list));    
    *stacka = NULL;     //rasgele bir bellek alanı işaret edebilri beliresiz değer olabilri
    *stackb = NULL;
    create_stack(stacka, argc, argv); //stackleri oluşturuyoruz
    if(is_it_sorted(stacka))
    {
        free_stack(stacka);
        free_stack(stackb);
        return (0);
    }
    sort(stacka,stackb);  //sort kaldı 
    
    free_stack(stacka);
    free_stack(stackb);
    return(0);
}