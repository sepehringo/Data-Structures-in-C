#include <stdio.h>
#include <stdlib.h>
// #include "ring_que.h"

// Structures Type Definitions
typedef struct doubly_LL doubly_LL;
typedef struct ring_q ring_q;

//Doubly Linked-List Function Signatures
doubly_LL* DLL_create();
void DLL_append(doubly_LL*, int);
void DLL_prepend(doubly_LL *p, int k);
void DLL_add_at(doubly_LL *p, int at, int k);
void DLL_print(doubly_LL*, int);
int DLL_get_count(doubly_LL *p);
int DLL_remove_node(doubly_LL *p, int index);
void DLL_delete_list(doubly_LL* p);

// Ring Queue Function Signatures
ring_q* RQ_create(int size);
int RQ_insert(ring_q *qu, int k);
int RQ_pop(ring_q *qu);