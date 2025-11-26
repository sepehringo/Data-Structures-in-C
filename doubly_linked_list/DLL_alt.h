#include "structure.h"
// Structures Type Definitions
typedef struct doubly_LL doubly_LL;


//Doubly Linked-List Functions
doubly_LL* DLL_create();
void DLL_append(doubly_LL*, int);
void DLL_prepend(doubly_LL *p, int k);
void DLL_add_at(doubly_LL *p, int at, int k);
void DLL_print(doubly_LL*, int);
int DLL_get_count(doubly_LL *p);