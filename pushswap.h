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
void    ft_free(char **arg);
char	**ft_split(const char *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
static size_t	ft_kelen(const char *s, char c);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
static int ft_isnum(char *num);
static int  repeat(int tmp, char **arg, int i);

//create stack
static void create_stack(s_list **stack, int argc , int **argv);




void    free_stack(s_list **stack);



#endif
