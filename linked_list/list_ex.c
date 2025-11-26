#include "list.h"

// functions

LINK create_l_rec(DATA arr[], int size)
{
    LINK head = NULL, tail;
    if (size == 0)
        return head;

    head = malloc(sizeof(ELEMENT));
    head->d = arr[0];
    head->next = create_l_rec(arr + 1, size - 1);
    return head;
}

int count_l_rec(LINK head) {
    if (head == NULL)
        return 0;
    return (1 + count_l_rec(head->next));
}

void print_l(LINK head) {
    while (head) {
        printf("Name: %s\nAge: %d\nWeight: %d\n\n", head->d.name, head->d.age, head->d.weight);
        head = head->next;
    }
}

void swap_el(LINK a, LINK b)
{
    DATA tmp;
    tmp = a->d;
    a->d = b->d;
    b->d = tmp;
}


void sort_age(LINK head)
{
    LINK ptr = head;
    while (ptr)
    {
        while (head->next)
        {
            if (head->d.age > head->next->d.age)
                swap_el(head, head->next);
            head = head->next;
        }
        head = ptr->next;
        ptr = head;
    }
}



void sort_l(LINK head, int (*cmp)())
{
    LINK ptr = head;
    while (ptr)
    {
        while (head->next)
        {
            if (cmp(head, head->next) > 0)
                swap_el(head, head->next);
            head = head->next;
        }
        head = ptr->next;
        ptr = head;
    }
}


// ex6 cycle check
int iscycle(LINK head)
{
    LINK first = head;
    while (head)
    {
        if (head->next == NULL)
            return 0;
        if (head->next == first)
            return 1;
        head = head->next;
    }
    return 0;
}
void concatenate_5(LINK a, LINK b)
{
    assert(a != NULL);
    if (a->next == NULL)
    {
        a->next = b;
        // Ex6: Check for cycle to prevent infinite loop
        if (iscycle(a))
            a->next = NULL;
    }
    else
        concatenate_5(a->next, b);
}

// Ex8: Modified concatenate 
LINK concatenate(LINK a, LINK b)
{
    if (a == NULL)
        return b;

    LINK head = a;
    while (a->next)
        a = a->next;
    a->next = b;
    if (iscycle(a))
        a->next = NULL;
    return head;
}
// Ex9
LINK copy_cat(LINK a, LINK b)
{
    LINK c = a;
    if (c == NULL)
        return c;
    LINK head = c;
    while (c->next)
        c = c->next;
    c->next = b;
    if (iscycle(c))
        c->next = NULL;
    return head;
}

// Ex10 : ex8 recursive
LINK concatenate_rec(LINK a, LINK b)
{
    if (a == NULL)
        return b;

    LINK head = a;
    if (a->next == NULL)
    {
        a->next = b;
        if (iscycle(a))
            a->next = NULL;
        return head;
    }
    return concatenate_rec(a->next, b);
}

// Ex11 :insert at 0
void prepend(LINK* head, DATA e)
{
    LINK new_element = malloc(sizeof(ELEMENT));
    new_element->d = e;
    new_element->next = *head;
    *head = new_element;

}

// Ex:12 insert at tail
void append(LINK* head, DATA e)
{
    LINK new_elemet = malloc(sizeof(ELEMENT));
    new_elemet->d = e;
    LINK ptr = *head;
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = new_elemet;
}
// Ex13: insert where
void insert_where(LINK* head, DATA el, DATA where)
{
    LINK new_element = malloc(sizeof(ELEMENT));
    new_element->d = el;
    LINK ptr = *head;
    while (ptr->next && memcmp(&ptr->d, &where, sizeof(DATA)))
        ptr = ptr->next;
    new_element->next = ptr->next;
    ptr->next = new_element;
}

// Ex14: insert_at

void insert_at(LINK* head, DATA el, int at)
{
    LINK new_element = malloc(sizeof(ELEMENT));
    new_element->d = el;
    LINK ptr = *head;
    // head Check **** IMPORTANT : ADD THIS TO YOUR FUTURE LIBRARY WHEN MERGING WITH YOUR OTHER LINK LIST CODE
    if (head == NULL)
    {
        free(new_element);          // THIS AVOIDS MEMORY LEAK
        printf("List is empty.\n");
        return;
    }
    // Handles the prepend
    if (at <= 0)
    {
        new_element->next = *head;
        *head = new_element;
        return;
    }
    int i = 0;
    while (ptr->next && i < at)
    {
        ptr = ptr->next;
        i++;
        if (ptr->next == NULL && i < at)
        {
            printf("\nERROR:\nIndex out of list bound. last index = %d\n\n", i);
            return;
        }

    }
    new_element->next = ptr->next;
    ptr->next = new_element;
}