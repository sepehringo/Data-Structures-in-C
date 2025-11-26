/* A linked list implementation of a queue */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY   0
#define FULL    10000

typedef     unsigned int       data;

struct elem{
    data        d;
    struct elem *next;
};
typedef     struct elem     elem;
struct queue {
    int     cnt;
    elem    *front;
    elem    *rear;
};

typedef     struct queue    queue;
void        initialize(queue    *q);
void        enqueue(data d, queue   *q);
data        dequeue(queue   *q);
data        front(const queue   *q);
bool        empty(const queue   *q);
bool        full(const  queue   *q);
