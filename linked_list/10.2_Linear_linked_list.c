#include "list.h"

int main()
{
    // Defining the first node
    LINK head = malloc(sizeof(ELEMENT));
    head->d = 'n';
    head->next = NULL;
    //Defining the second node
    head->next = malloc(sizeof(ELEMENT));
    head->next->d = 'e';
    head->next->next = NULL;
    //Defining the third node
    head->next->next = malloc(sizeof(ELEMENT));
    head->next->next->d = 'w';
    head->next->next->next = NULL;

    //Print output as a string since it is null terminated already
    while (head)
    {
        printf("%c", head->d);
        head = head->next;
    }
    printf("\n");
}