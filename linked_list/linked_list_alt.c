#include "slist.h"
typedef struct slist slist;
struct slist
{
    int num;
    slist *link;
};
void slist_allocate(slist *p)
{
    p = malloc(sizeof(slist));
    if (!p)
    {
        printf("Could not allocate\n");
        return;
    }
    return;
}
void initiate(slist *p, int n)
{
    p->num = n;
    p->link = NULL;
}
void print_list(slist *p)
{
    slist *head = p;
    do
    {
        printf("%d\t", head->num);
        head = head->link;
    } while (head->link);
}

void append(slist *p, int n)
{
    slist *q = malloc(sizeof(slist));
    q->num = n;
    p->link = q;
    q->link = NULL;
}

void insert(slist *p, int at, int n)
{
    slist *q, *r = malloc(sizeof(slist));
    q = p;
    while (at--)
    {
        if (!(q->link))
        {
            printf("List overrun!");
            return;
        }
        else
            q = q->link;
    }
    r->link = q->link;
    q->link = r;
    r->num = n;
}

void head_insert(slist *p, int n)
{
    slist *q = malloc(sizeof(slist));
    q->link = p;
    q->num = n;
    p = q;
}
void tail_insert(slist *p, int n)
{
    slist *q, *r = malloc(sizeof(slist));
    q = p;
    while (q->link)
        q = q->link;
    q->link = r;
    r->num = n;
    r->link = NULL;
}