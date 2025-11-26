#include "structure.h"

ring_queue* RQ_create(int size);
int RQ_add(ring_queue *qu, int k);
int RQ_pop(ring_queue *qu);