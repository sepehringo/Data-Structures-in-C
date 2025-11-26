#include "structure.h"
#define N 10
typedef struct ring_queue
{
    int array[N];
    int front;
    int rear;
} ring_queue;

ring_queue* create_rQ(int size)
{
    ring_queue *qu = malloc(sizeof(ring_queue));
    qu->front = 0;
    qu->rear = 0;
    return qu;
}

void add_ring_Q(ring_queue *qu, int k)
{
    if (qu->front == (qu->rear + 1) % N)
    {
        printf("Queue is full.\n");
        return;
    }
    else
    {
        qu->rear = (qu->rear + 1) % N;
        qu->array[qu->rear] = k;
    }
}
int del_ring_Q(ring_queue *qu)
{
    if (qu->front == qu->rear)
    {
        printf("Queue is empty.\n");
        exit(1);
    }
    else
    {
        qu->front = (qu->front + 1) % N;
        return qu->array[qu->front];
    }
}