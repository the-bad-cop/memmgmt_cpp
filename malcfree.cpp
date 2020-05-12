#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = (int *)malloc(sizeof(int));
    printf("address=%p, value=%d\n", p, *p);
    int *a = (int *)malloc(4 * sizeof(int));
    a[0] = 1;
    a[2] = 33;
    // printf("%d \n %p", a[2], a);

    struct MyStruct
    {
        int i;
        float f;
        char c[3];
    };
    MyStruct *my = (MyStruct *)calloc(4, sizeof(MyStruct));
    my[1].i = 12;
    my[0].f = 2.2;
    printf("\n %p \n %d", my + 2, my[1].i);
    return 0;
}

/*At compile time, only the space for the pointer is reserved (on the stack). 
When the pointer is initialized, a block of memory of sizeof(int) bytes is allocated (on the heap) at program runtime. 
The pointer on the stack then points to this memory location on the heap.
*/