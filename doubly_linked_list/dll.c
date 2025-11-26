#include "dll.h"

DLLINK create_dll(DATA arr[], int size)
{
    DLLINK head = NULL;
    if (size == 0)
        return head;

    head = (DLLINK)malloc(sizeof(ELEMENT));
    head->d = arr[0];
    head->prev = NULL;
    head->next = create_dll(arr + 1, size - 1);
    // To cover the case of last NULL node need this condition
    if (head->next)
        head->next->prev = head;
}

int count_dll(DLLINK head)
{
    if (head == NULL)
        return 0;
    return 1 + count_dll(head->next);
}

void print_dll(DLLINK head)
{
    while (head)
    {
        printf("Name: %s\nAge: %d\nWeight: %d\n\n", head->d.name, head->d.age, head->d.weight);
        head = head->next;
    }
}

void swap_el(DLLINK a, DLLINK b)
{
    DATA d = b->d;
    b->d = a->d;
    a->d = d;
}

void sort_dll(DLLINK head, int (*cmp)(const DATA, const DATA))
{
    DLLINK ptr = head;
    while (ptr)
    {
        while (ptr->next)
        {
            if (cmp(ptr->d, ptr->next->d) > 0)
                swap_el(ptr, ptr->next);
            ptr = ptr->next;
        }
        head = head->next;
        ptr = head;
    }
}

// ex15

void insert_at(DLLINK* head, DATA el, int at)
{
    if (at < 0) {
        fprintf(stderr, "insert_at: negative index %d\n", at);
        return;
    }

    DLLINK node = malloc(sizeof(ELEMENT));
    if (!node) { perror("malloc"); return; }
    node->d = el;
    node->prev = node->next = NULL;

    /* empty list */
    if (*head == NULL) {
        if (at == 0) {
            *head = node;
            return;
        }
        fprintf(stderr, "insert_at: index out of bounds (empty list) at=%d\n", at);
        free(node);
        return;
    }

    /* insert at front */
    if (at == 0) {
        node->next = *head;
        (*head)->prev = node;
        *head = node;
        return;
    }

    /* traverse toward index `at` */
    DLLINK cur = *head;
    int idx = 0;
    while (idx < at && cur->next) {
        cur = cur->next;
        idx++;
    }

    if (idx < at) {
        /* at beyond end -> append after cur (cur is last) */
        cur->next = node;
        node->prev = cur;
        node->next = NULL;
        return;
    }

    /* insert before cur (cur is node at index `at`) */
    DLLINK prev = cur->prev;
    node->next = cur;
    node->prev = prev;
    cur->prev = node;
    if (prev)
        prev->next = node;
    else
        *head = node;
}

void delete_at(DLLINK* head, int at)
{
    if (!head || !*head) {
        fprintf(stderr, "delete_at: list is empty\n");
        return;
    }
    if (at < 0) {
        fprintf(stderr, "delete_at: negative index %d\n", at);
        return;
    }

    DLLINK cur = *head;
    int i = 0;
    while (i < at && cur) {
        cur = cur->next;
        i++;
    }
    if (!cur) {
        fprintf(stderr, "delete_at: index out of bounds (last index = %d)\n", i - 1);
        return;
    }

    /* unlink cur */
    if (cur->prev)
        cur->prev->next = cur->next;
    else
        *head = cur->next; /* removed head */

    if (cur->next)
        cur->next->prev = cur->prev;

    free(cur);
}

void del_dupl(DLLINK head)
{
    DLLINK p = head;
    while (p) {
        DLLINK q = p->next;
        while (q) {
            DLLINK next = q->next; // Save next before possible free
            if (memcmp(&p->d, &q->d, sizeof(DATA)) == 0) {
                if (q->prev) q->prev->next = q->next;
                if (q->next) q->next->prev = q->prev;
                free(q);
            }
            q = next;
        }
        p = p->next;
    }
}