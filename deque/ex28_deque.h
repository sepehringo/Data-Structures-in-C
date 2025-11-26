#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdbool.h>
typedef struct deque_struct* deque;

// Updated function prototypes to match implementation
deque create_deque(int size, int el_size);
void destroy_deque(deque dq);
void add_to_front(deque dq, void* element);
void add_to_rear(deque dq, void* element);
void take_from_front(deque dq, void*);
void take_from_rear(deque dq, void*);

// Additional functions you might want to implement
bool is_empty(deque dq);
bool is_full(deque dq);
int get_size(deque dq);

#endif

