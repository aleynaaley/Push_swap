#include <stdio.h>
#include <stdlib.h>

// Stack yapısı tanımı
typedef struct s_stack
{
    int *items;
    int top;
    int max_size;
} Stack;

// Stack oluşturma fonksiyonu
Stack *create_stack(int max_size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->items = (int *)malloc(sizeof(int) * max_size);
    stack->top = -1;
    stack->max_size = max_size;
    return stack;
}

// Stack'e eleman ekleme (push) fonksiyonu
void push(Stack *stack, int value)
{
    if (stack->top < stack->max_size - 1)
    {
        stack->items[++(stack->top)] = value;
    }
}

// Stack'ten eleman çıkarma (pop) fonksiyonu
int pop(Stack *stack)
{
    if (stack->top >= 0)
    {
        return stack->items[(stack->top)--];
    }
    return -1; // Stack boşsa
}

// Stack'in en üstündeki elemanı döndürme fonksiyonu
int peek(Stack *stack)
{
    if (stack->top >= 0)
    {
        return stack->items[stack->top];
    }
    return -1; // Stack boşsa
}

// Stack'in boş olup olmadığını kontrol etme fonksiyonu
int is_empty(Stack *stack)
{
    return stack->top == -1;
}

// sa: a stack'inin en üstteki iki elemanını değiştirir
void sa(Stack *a)
{
    if (a->top > 0)
    {
        int temp = a->items[a->top];
        a->items[a->top] = a->items[a->top - 1];
        a->items[a->top - 1] = temp;
        printf("sa\n");
    }
}

// sb: b stack'inin en üstteki iki elemanını değiştirir
void sb(Stack *b)
{
    if (b->top > 0)
    {
        int temp = b->items[b->top];
        b->items[b->top] = b->items[b->top - 1];
        b->items[b->top - 1] = temp;
        printf("sb\n");
    }
}

// ss: sa ve sb eylemlerini aynı anda gerçekleştirir
void ss(Stack *a, Stack *b)
{
    sa(a);
    sb(b);
    printf("ss\n");
}

// pa: b stack'inin en üstündeki elemanı a stack'ine koyar
void pa(Stack *a, Stack *b)
{
    if (!is_empty(b))
    {
        push(a, pop(b));
        printf("pa\n");
    }
}

// pb: a stack'inin en üstündeki elemanı b stack'ine koyar
void pb(Stack *a, Stack *b)
{
    if (!is_empty(a))
    {
        push(b, pop(a));
        printf("pb\n");
    }
}

// ra: a stack'inin elemanlarını bir yukarı kaydırır
void ra(Stack *a)
{
    if (a->top > 0)
    {
        int temp = a->items[a->top];
        for (int i = a->top; i > 0; i--)
        {
            a->items[i] = a->items[i - 1];
        }
        a->items[0] = temp;
        printf("ra\n");
    }
}

// rb: b stack'inin elemanlarını bir yukarı kaydırır
void rb(Stack *b)
{
    if (b->top > 0)
    {
        int temp = b->items[b->top];
        for (int i = b->top; i > 0; i--)
        {
            b->items[i] = b->items[i - 1];
        }
        b->items[0] = temp;
        printf("rb\n");
    }
}

// rr: ra ve rb eylemlerini aynı anda gerçekleştirir
void rr(Stack *a, Stack *b)
{
    ra(a);
    rb(b);
    printf("rr\n");
}

// rra: a stack'inin elemanlarını bir aşağı kaydırır
void rra(Stack *a)
{
    if (a->top > 0)
    {
        int temp = a->items[0];
        for (int i = 0; i < a->top; i++)
        {
            a->items[i] = a->items[i + 1];
        }
        a->items[a->top] = temp;
        printf("rra\n");
    }
}

// rrb: b stack'inin elemanlarını bir aşağı kaydırır
void rrb(Stack *b)
{
    if (b->top > 0)
    {
        int temp = b->items[0];
        for (int i = 0; i < b->top; i++)
        {
            b->items[i] = b->items[i + 1];
        }
        b->items[b->top] = temp;
        printf("rrb\n");
    }
}

// rrr: rra ve rrb eylemlerini aynı anda gerçekleştirir
void rrr(Stack *a, Stack *b)
{
    rra(a);
    rrb(b);
    printf("rrr\n");
}

// push_swap fonksiyonu
void push_swap(Stack *a, Stack *b)
{
    int size = a->top + 1;
    int min_index;

    while (size > 0)
    {
        min_index = 0;
        for (int i = 1; i < size; i++)
        {
            if (a->items[i] < a->items[min_index])
            {
                min_index = i;
            }
        }

        while (min_index < size - 1)
        {
            ra(a);
            min_index++;
        }
        
        pb(a, b);
        size--;
    }

    while (!is_empty(b))
    {
        pa(a, b);
    }
}

// Ana program
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Kullanım: ./push_swap num1 num2 num3 ...\n");
        return 1;
    }

    Stack *a = create_stack(argc - 1);
    Stack *b = create_stack(argc - 1);

    for (int i = 1; i < argc; i++)
    {
        push(a, atoi(argv[i]));
    }

    push_swap(a, b);

    free(a->items);
    free(a);
    free(b->items);
    free(b);

    return 0;
}
