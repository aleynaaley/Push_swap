#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

//linked list düğüm veri yapısı denebilir
typedef struct stack
{
    int value;
    int index;
    struct stack *next;   //linked listte diğer elemanın düğümleri için 
}   s_list;

//check argument
void    check_arg(int argc, char **argv);
void    ft_argfree(char **arg);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *s);
long	ft_atoi(const char *str);
int	ft_isdigit(int c);
int ft_isnum(char *num);
int  repeat(long tmp, char **arg, int i); //tmp long kontrol et

//create stack
void create_stack(s_list **stack, int argc , char **argv);
s_list  *create_node(long value);
s_list  *last_node_find(s_list *head);
void    add_node(s_list **stack, s_list *new_node);
s_list   *find_min(s_list **stack);
int  min_index(s_list **stack, int value);
void    stack_index(s_list  **stack);

//sorted
int is_it_sorted(s_list **stack);
int list_size(s_list *node);
int  find_max_bits(s_list **stack);
int    swap_sa(s_list  **a);
int	    swap_sb(s_list **b);
int	swap_ss(s_list **a, s_list **b);
int	swap_ra(s_list **a);
int	swap_rb(s_list **b);
int	swap_rr(s_list **a, s_list **b);
int	swap_rra(s_list **a);
int	swap_rrb(s_list **b);
int	swap_rrr(s_list **a,s_list **b);
int	swap_pa(s_list **a, s_list **b);
int	swap_pb(s_list **a, s_list **b);
int	get_distance(s_list **stack, int index);
int	push(s_list **stack_to, s_list **stack_from);
int	reverse_rotate(s_list **stack);
int	rotate(s_list **stack);
int swap(s_list **stack);
void sort(s_list **a, s_list **b);
void sort_3(s_list **a);
void	sort_4(s_list **a, s_list **b);
void    sort_5(s_list **a,s_list **b);
void    little_sort(s_list  **a, s_list **b);
void    radix_sort(s_list **a, s_list **b);

//another
void    free_stack(s_list **stack);
void    error();

#endif
