/* The basic queue routines. */
#include "queue.h"

void initialize(queue* q)
{
    q->cnt = 0;
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(data d, queue* q)
{
    elem* p;
    p = malloc(sizeof(elem));
    p->d = d;
    p->next = NULL;
    if (!empty(q)) {
        elem* current = q->front; /* Dummy pointer */
        // if was to insert at first
        if (p->d.priority > q->front->d.priority)
        {
            p->next = q->front;
            q->front = p;
        }
        else {
            // Traverse to find insertion point
            while (current->next && p->d.priority <= current->next->d.priority)
                current = current->next;
            // insert 
            p->next = current->next;
            current->next = p;
        }
        // Update rear if inserting at the end
        if (p->next == NULL) {
            q->rear = p;
        }
    }
    else
        q->front = q->rear = p;
    q->cnt++;
}

void enqueue1(data d, queue* q)
{
    elem* p;

    p = malloc(sizeof(elem));
    p->d = d;
    p->next = NULL;
    if (!empty(q)) {
        q->rear->next = p;
        q->rear = p;
    }
    else
        q->front = q->rear = p;
    q->cnt++;
}

data dequeue(queue* q)
{
    data    d;
    elem* p;

    d = q->front->d;
    p = q->front;
    q->front = q->front->next;
    q->cnt--;
    free(p);
    return d;
}


data front(const queue* q)
{
    return (q->front->d);
}

bool empty(const queue* q)
{
    return (bool)(q->cnt == EMPTY);
}

bool full(const queue* q)
{
    return (bool)(q->cnt == FULL);
}

queue data_to_queue(data d[], int n)
{
    queue q;
    initialize(&q);
    for (int i = 0; i < n; i++)
        enqueue(d[i], &q);
    return q;
}

data* queue_to_data(queue q)
{
    data* arr = malloc(sizeof(data) * q.cnt);
    int n = q.cnt;
    for (int i = 0; i < n; i++)
    {
        arr[i] = dequeue(&q);
    }
    return arr;
}