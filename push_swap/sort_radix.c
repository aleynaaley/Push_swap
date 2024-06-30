
#include "push_swap.h"


int  find_max_bits(s_list **stack)     //radixin çalışması için gereken max bit sayısı döndürür
{
    s_list  *head;
    int     max;    //en büyük indeks değerini tutmak için 
    int     max_bits;   //en büyüğün bitini tutacak

    head = *stack;
    max = head->index;
    max_bits =0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
    while ((max >> max_bits) != 0)     // max = 5 olsun (101) max_bits = 3
		max_bits++;
	return (max_bits);
}
 

void    radix_sort(s_list **a, s_list **b)
{
    s_list	*head_a;
	int		i;
	int		j;
	int		size;  //stack a nın büyüklüğünü tutacak
	int		max_bits;  //sıralma için gereken max bit sayısı 3 ise 111 mesela indeks ile işler

    i = 0;
    head_a = *a;
    size = list_size(head_a);
    max_bits = find_max_bits(a);
    while (i < max_bits)
	{
        j = 0;
		while (j++ < size)   //eleman sayısı kadar dönecek ve tek tek biz düzeyinde sıralama yapacak
		{
            head_a = *a;
            if (((head_a->index >> i) & 1) == 1)   // indekslerin ilk bitten 1 mı 0 mı kontrol ediyor 
				swap_ra(a);
			else
				swap_pb(a, b);
        }
        while (list_size(*b) !=0 )
            swap_pa(a,b);
        i++;
        if(is_it_sorted(a))
            return;
    }
}