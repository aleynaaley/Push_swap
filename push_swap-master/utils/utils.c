
#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}
//dinamik tahsis edilmiş iki boyutlu bir char tek tek freelemelisin her string için ayrı blook açıldı çünkü

/*

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])  // Eleman sayısını bulur
	{
		free(str[i]);  // Her bir elemanı serbest bırakır
		i++;
	}
	free(str);  // Son olarak dizinin kendisini serbest bırakır
}
bu da alternatif bunu kuıllan ama yanlış olabilir üsttekine eksik denildi
*/

int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;   //verilen stackin başlangıç düğümünü işaret eder aslında 
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_distance(t_list **stack, int index)
{
	t_list	*head;
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

void	make_top(t_list **stack, int distance)
{
	t_list	*head;
	int		tmp;

	if (distance == 0)
		return ;
	head = *stack;
	tmp = ft_lstsize(head) - distance;
	if (distance <= (ft_lstsize(head) / 2))
	{
		while (distance-- > 0)
			ra(stack);
	}
	else
	{
		while (tmp-- > 0)
			rra(stack);
	}
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}
