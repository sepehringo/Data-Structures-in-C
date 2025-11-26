#include "list.h"

#ifdef COUNT_REC
int count_rec(LINK head)
{
    if (head == NULL)
        return 0;
    else
        return (1 + count_rec(head->next));
}
#endif
int main()
{
    char* str = "Hello";
    LINK head = string_to_list(str);
    print_list_rec(head);
    printf("\n");
    print_list(head);
    printf("\n");
    printf("count: %d\n",count_rec(head));
    printf("count: %d\n",count_it(head));

    char* str_b = ", World!\n";
    LINK b = string_to_list(str_b);
    concatenate(head, b);
    print_list_rec(head);
}