
#include "pushswap.h"


//stack i oluşturan bir fonksiyoon yaz
Stack *create_stack(int maxsize)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->box = (int *)malloc(sizeof(int) * maxsize);
    stack->maxsize = maxsize;
    stack->top = -1;    // stacki oluştururkenn boş olması için en üstteki olmayan elemana -1 . indeksi atadık 
	return stack;
}

//en büyük sayıyı bulmak için fonksiyon
int find_max(Stack *stack)
{
    int max;
    int i = 1;
    max = stack->box[0];
    while(i <= stack->top)
    {
        if(max < stack->box[i])
            max = stack->box[i];
        i++;
    }
    return max;
}


int radixsort(Stack *a, Stack *b)
{

    return;
}

int main(int argc,int *argv[])
{
	if(argc < 0 )  //argc < = 2 1  0 falan konrtol et 
	{
		//sonra yazacaksın
	}

	//tüm kontrolle üstte yap

	Stack *a = create_stack(argc - 1);
    Stack *b = create_stack(-1);

    int i;

    while (i < argc)
    {
        push(a,argv[i]);     // push fonksiyonu ile a stackine tek tek tüm elemanları ekleyeceğim
        i++;
    }
    
    radixsort(a, b); // burada radix sort ile sıralama yapılacak 

    //herşeyi bu aşamada tekrar tekrar freelemeyi unutma .

}