/* A linked list implementation of a queue */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define EMPTY   0
#define FULL    10000


typedef struct {
    unsigned pid;
    unsigned priority;
    #define DATA_T
} data;

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
queue       data_to_queue(data d[], int n);
data*       queue_to_data(queue q);