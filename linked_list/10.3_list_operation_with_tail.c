#include "list.h"

LINK s_to_l(char s[])
{
    LINK head = NULL, tail;
    int i;
    if (s[0] != '\0')
    {
        head = malloc(sizeof(ELEMENT));
        head->d = s[0];
        tail = head;
        for (i = 1; s[i] != '\0'; ++i)
        {
            tail->next = malloc(sizeof(ELEMENT));
            tail = tail->next;
            tail->d = s[i];
        }
        tail->next = NULL;
    }
    return head;
}

int main()
{
    char* str = "Hello\n";
    LINK head = s_to_l(str);
    while (head)
    {
        printf("%c", head->d);
        head = head->next;
    }
}