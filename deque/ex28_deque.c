#include "ex28_deque.h"

struct deque_struct {
    int size;
    int el_size;
    int front;
    int rear;
    int count;
    void* data;
};

bool is_empty(deque dq) {
    return dq->count == 0;
}

bool is_full(deque dq) {
    return dq->count >= dq->size;
}

int get_size(deque dq) {
    return dq->count;
}
deque create_deque(int size, int el_size)
{
    deque dq = malloc(sizeof(struct deque_struct));
    dq->count = 0;
    dq->el_size = el_size;
    dq->size = size;
    dq->data = malloc(size * el_size);
    dq->front = 0;
    dq->rear = 0;
    return dq;
}

void destroy_deque(deque dq)
{
    if (dq)
    {
        free(dq->data);
        free(dq);
    }
}

void add_to_front(deque dq, void* element)
{
    if (is_full(dq)) {
        printf("Deque is full!\n");
        return;
    }
    dq->front = (dq->front - 1 + dq->size) % dq->size;
    memcpy((char*)dq->data + dq->front * dq->el_size, element, dq->el_size);
    dq->count++;
}

void take_from_front(deque dq, void* element)
{
    if (is_empty(dq))
    {
        printf("Deque: is empty!\n");
        return;
    }
    memcpy(element, (char*)dq->data + dq->front * dq->el_size, dq->el_size);
    dq->front = (dq->front + 1) % dq->size;
    dq->count--;
}

void add_to_rear(deque dq, void* element)
{
    if (is_full(dq)) {
        printf("Deque is full!\n");
        return;
    }
    memcpy((char*)dq->data + dq->rear * dq->el_size, element, dq->el_size);
    dq->rear = (dq->rear + 1) % dq->size;
    dq->count++;
}

void take_from_rear(deque dq, void* element)
{
    if (is_empty(dq)) {
        printf("Deque: is empty!\n");
        return;
    }
    dq->rear = (dq->rear - 1 + dq->size) % dq->size;
    memcpy(element, (char*)dq->data + dq->rear * dq->el_size, dq->el_size);
    dq->count--;
}