// #include "ring_que.h"
#include "structure.h"

typedef struct ring_q
{
    int *array;
    int front;
    int rear;
    int size;
} ring_q;

ring_q* RQ_create(int size)
{
    ring_q *qu = malloc(sizeof(ring_q));
    qu->array = malloc(sizeof(int) * size);
    qu->front = 0;
    qu->rear = 0;
    qu->size = size;
    return qu;
}

int RQ_insert(ring_q *qu, int k)
{
    if (qu->front == (qu->rear + 1) % qu->size)
    {
        printf("Queue is full.\n");
        return 0;
    }
    else
    {
        qu->rear = (qu->rear + 1) % qu->size;
        qu->array[qu->rear] = k;
    }
    return 1;
}
int RQ_pop(ring_q *qu)
{
    if (qu->front == qu->rear)
    {
        printf("Queue is empty.\n");
        exit(1);
    }
    else
    {
        qu->front = (qu->front + 1) % qu->size;
        return qu->array[qu->front];
    }
}