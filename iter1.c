#include "pushswap.h"

void push(Stack *stack, int value)
{
    if(stack->top < stack->maxsize - 1)
    {
        stack->box[++(stack->top)] = value;
    }
}
int pop(Stack *stack)
{
    if(stack->top >= 0)
    {
        return stack->box[(stack->top)--];
    }
    return -1;
}
int is_empty(Stack *stack)
{
    return stack->top == -1;
}

void sa(Stack *stack)
{
    if(stack->top > 0)   //0 mı 1 mi emin değilsin
    {   
        int temp;
        temp = stack->box[stack->top];
        stack->box[stack->top] = stack->box[stack->top -1];
        stack->box[stack->top -1] = temp;
        printf("sa\n");
    }
}
void sb(Stack *stack)
{
    if(stack->top > 0)   //0 mı 1 mi emin değilsin
    {   
        int temp;
        temp = stack->box[stack->top];
        stack->box[stack->top] = stack->box[stack->top -1];
        stack->box[stack->top -1] = temp;
        printf("sb\n");
    }
}
void ss(Stack *a, Stack *b)
{
    sa(a);
    sb(b);
    printf("ss\n");
}
void pa(Stack *a, Stack *b)
{
    if(!is_empty(b))
    {
        push(a,pop(b));  // pop top dakini döndürür ve toptakini siler, push da ekler topa
        printf("pa\n");
    }
}
void pb(Stack *a, Stack *b)
{
    if(!is_empty(a))
    {
        push(b,pop(a));  
        printf("pb\n");
    }
}
void ra(Stack *a)
{
    if(a->top > 0)     // 0 mı 1 mi emin değilsin
    {    
        int temp;
        int i;
        i = a->top;
        temp = a->box[a->top];
        while(i > 0)
        {
            a->box[i] = a->box[i - 1];
            i--;
        }
        a->box[0] = temp;
        printf("ra\n");
    }
}
void rb(Stack *b)
{
    if(b->top > 0)     // 0 mı 1 mi emin değilsin
    {    
        int temp;
        int i;
        i = b->top;
        temp = b->box[b->top];
        while(i > 0)
        {
            b->box[i] = b->box[i - 1];
            i--;
        }
        b->box[0] = temp;
        printf("rb\n");
    }
}
void rr(Stack *a, Stack *b)
{
    ra(a);
    rb(b);
    printf("rr\n");
}
void rra(Stack *a)
{
    if(a->top > 0)     // 0 mı 1 mi emin değilsin
    {    
        int temp;
        int i;
        i = 0;
        temp = a->box[0];
        while(i > 0)
        {
            a->box[i] = a->box[i + 1];
            i--;
        }
        a->box[a->top] = temp;
        printf("rra\n");
    }
}
void rrb(Stack *b)
{
    if(b->top > 0)     // 0 mı 1 mi emin değilsin
    {    
        int temp;
        int i;
        i = 0;
        temp = b->box[0];
        while(i > 0)
        {
            b->box[i] = b->box[i + 1];
            i--;
        }
        b->box[b->top] = temp;
        printf("rrb\n");
    }
}
void rrr(Stack *a, Stack *b)
{
    rra(a);
    rrb(b);
    printf("rrr\n");
}