

#include "push_swap.h"

static void create_stack(s_list **stack, int argc , int **argv)
{
    s_list *new; //yeni listenin düğümünün işaretçisi
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
        new = create_node(ft_atoi(arg[i]));

    }
}