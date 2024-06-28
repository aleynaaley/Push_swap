/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2024/06/20 02:28:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creates new node and returns the pointer of it
t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;   //düğüm henüz sııralanmadı oluşturuldu sadece
	new->next = NULL;  //düğüm şuanda listenin son düğümü
	return (new);
}

// Adds the specified node to a stack (list) making it the head
void	ft_lstadd_front(t_list **stack, t_list *new)
{
	new->next = *stack;
	*stack = new;
}

//verilen listenin son düğümünü bulmak için fonk
t_list	*ft_lstlast(t_list *head)
{
	t_list	*tmp;

	tmp = head;  // head listenin başını işaret eden işaretçi tmp tutuyor 
	while (tmp->next)  //hep bir donrakine gideceğiz ve tmp null olmadığı sürece
	{
		tmp = tmp->next;  // burada bir sonraki null ise onu iaretçisini döndürüyoruz
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

// Adds the specified node to a stack (list) making it the last node
void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*n;   //listenin son düğümünü işaret edecek

	if (*stack)   //eğer liste boş değilse son düğümü bulur 
	{
		n = ft_lstlast(*stack);
		n->next = new;
		new->next = NULL;   // sadece önlem ve okunabilirlilikiçin tekrar null ladım . listenin sonunda olduğunu göstermek için
	}
	else               // liste boş ise yeni düğüm listenin ilk ve tek düğümü olur
	{
		*stack = new;
		(*stack)->next = NULL; // yeni düğümün nexti null olur son ve tek düğüm olduğu için 
	}
}

// Returns the size of the Linked List
int	ft_lstsize(t_list *head)
{
	size_t	i;
	t_list	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

// Prints the Linked List
void	printList(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}

