#include "list.h"

// From 10.3
LINK string_to_list(char s[])
{
    LINK head;
    if (s[0] == '\0')                       /* base case */
        return NULL;
    else {
        head = malloc(sizeof(ELEMENT));
        head->d = s[0];
        head->next = string_to_list(s + 1); /* Causes the last head->next to aquire the null termination char at the end of the string*/
        return head;
    }
}

// From 10.4
int count_rec(LINK head)
{
    if (head == NULL)
        return 0;
    else
        return (1 + count_rec(head->next));
}
int count_it(LINK head)
{
    int count = 0;
    while(head)
    {
        count++;
        head = head->next;
    }
    return count;
}

// My recursive
void print_list_rec(LINK head)
{
    if (head == NULL)
        return;
        printf("%c", head->d);
    print_list_rec(head->next);
}
//Book's recursive
void print_list(LINK head)
{
    if(head == NULL)
        printf("NULL");
    else{
        printf("%c --> ", head->d);
        print_list(head->next);
    }
}

void concatenate(LINK a, LINK b)
{
    assert(a != NULL);
    if (a->next == NULL)
        a->next = b;
    else
        concatenate(a->next, b);
}

void delete_list_rec(LINK head)
{
    if(head != NULL){
        delete_list(head->next);
        free(head);
    }
}