#include "list.h"

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

int main()
{
    char* str = "Hello\n";
    LINK head = string_to_list(str);
    while (head)
    {
        printf("%c", head->d);
        head = head->next;
    }
}