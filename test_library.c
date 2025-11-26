
#include "structure.h"

int main()
{
    //Test Doubly Link List
    doubly_LL* dll;
    dll = DLL_create();
    DLL_append(dll, 8);
    DLL_prepend(dll, 1);
    DLL_append(dll, 7);
    DLL_append(dll, 6);
    DLL_add_at(dll, 0, 0);
    DLL_add_at(dll, 3, 0);
    DLL_add_at(dll,DLL_get_count(dll)  + 1, 0);
    /* Must print:
    Error for the last add_at
    0, 1, 8, 0, 7, 6*/
    DLL_print(dll, 1);
    DLL_remove_node(dll, 3);
    DLL_print(dll, 1);
    DLL_remove_node(dll, 4);
    DLL_print(dll, 1);
    DLL_print(dll, -1);
    DLL_delete_list(dll);



    // Test Queue
//     ring_q *rq = RQ_create(10);
//     for (int i = 10; i < 22; i++)
//         {int c=RQ_insert(rq, i); if(c)printf("%d added to the queue\n",i);}
//     for(int i = 0; i < 5; i++)
//         printf("Que Pop: %d\n", RQ_pop(rq));
//     for (int i = 0 ;i < 10; i ++)
//         {int c=RQ_insert(rq, i); if(c)printf("%d added to the queue\n",i);}
//     for(int i = 0; i < 12; i++)
//         printf("Que Pop: %d\n", RQ_pop(rq));
}