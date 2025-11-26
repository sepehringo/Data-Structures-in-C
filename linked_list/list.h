#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef char DATA;                  /* will use char in examples */

struct linked_list {
    DATA                    d;
    struct linked_list* next;
};

typedef struct linked_list ELEMENT;
typedef ELEMENT* LINK;


// Function Prototypes

LINK string_to_list(char s[]);

int count_rec(LINK head);
int count_it(LINK head);

void print_list_rec(LINK head);
void print_list(LINK head);

void concatenate(LINK a, LINK b);