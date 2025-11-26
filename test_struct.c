#include "structure.h"
int main()
{
    // DLL Test
    doubly_LL *dll;
 
    
        printf("%p\n", dll);
    dll = DLL_create();
    DLL_append(dll, 2);
   DLL_prepend(dll, 1);

    DLL_append(dll, 3);

 DLL_print_headToTail(dll);

    DLL_add_at(dll, 0, 0);

 DLL_print_headToTail(dll);
    
    DLL_prepend(dll, 1);

 DLL_print_headToTail(dll);

    DLL_append(dll, 4);

 DLL_print_headToTail(dll);
    
    DLL_add_at(dll, 2, 0);

    
DLL_print_headToTail(dll);
    DLL_append(dll, 3);

    
DLL_print_headToTail(dll);


    DLL_add_at(dll, 5, 0);
    

    DLL_print_headToTail(dll);

    // Ring Que test

    // ring_queue *a;
    // a = create_rQ(20);
    // for (int i = 10; i < 22;i++ )
    //     add_ring_Q(&a,i);
    // for (int i = 10; i < 22;i++)
    //     printf("%d\n", del_ring_Q(&a));
}