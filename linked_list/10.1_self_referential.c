#include <stdio.h>

struct list {
    int data;
    struct list *next;
};

int main()
{
    struct list a, b, c;
    a.data = 1;
    b.data = 2;
    c.data = 3;
    a.next = b.next = c.next = NULL;
    // Link together
    a.next = &b;
    b.next = &c;

    printf("data:\na.data: %d\ta.next->data or b.data: %d\ta.next->next->data or c: %d\nb.data: %d\tb.next->data or c: %d\nc.data: %d\n", a.data, a.next->data, a.next->next->data, b.data, b.next->data, c.data);
}