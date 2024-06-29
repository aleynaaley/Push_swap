#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//linked list düğüm veri yapısı denebilir
typedef struct stack
{
    int value;
    int index;
    struct stack *next;   //linked listte diğer elemanın düğümleri için 
}   s_list;

//check argument
void    check_arg(int argc, int **argv);
void    error();
void    ft_argfree(char **arg);
char	**ft_split(const char *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
static size_t	ft_kelen(const char *s, char c);
long	ft_atoi(const char *str);
int	ft_isdigit(int c);
static int ft_isnum(char *num);
static int  repeat(long tmp, char **arg, int i); //tmp long kontrol et

//create stack
static void create_stack(s_list **stack, int argc , int **argv);
s_list  *create_node(long value);
s_list  *last_node_find(s_list *head);
void    add_node(s_list **stack, s_list *new_node);
static s_list   *find_min(s_list **stack);
void    stack_index(s_list  **stack);



//sorted
int is_it_sorted(s_list **stack);
static void sort(s_list **a, s_list **b);
int list_size(s_list *node);
void    little_sort(s_list  **a, s_list **b);
static int  min_index(s_list **stack, int value);
int    swap_sa(s_list  **a);
int	    swap_sb(s_list **b);
int	swap_ss(s_list **a, s_list **b);
int	swap_ra(s_list **a);
int	swap_rra(s_list **a);
int	swap_pa(s_list **a, s_list **b);
int	swap_pb(s_list **a, s_list **b);

int	push(s_list **stack_to, s_list **stack_from);
int	reverseRotate(s_list **stack);
int	rotate(s_list **stack);
int swap(s_list **stack);
static void sort_3(s_list **a);
static void	sort_4(s_list **a, s_list **b);






//another
void    free_stack(s_list **stack);

#endif

