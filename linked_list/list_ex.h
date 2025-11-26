#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// Ex2
typedef struct{
    char    name[10];
    int     age;
    int     weight;
} DATA;                 

struct linked_list {
    DATA                 d;
    struct linked_list* next;
};

typedef struct linked_list ELEMENT;
typedef ELEMENT *LINK;

// ex2
LINK create_l_rec(DATA arr[], int size);
// ex2
int count_l_rec(LINK head);
// ex3
void sort_age(LINK head);
// ex4
void sort_l(LINK head, int (*cmp)());
// ex5 
void concatenate_5(LINK a, LINK b);
// ex6
int iscycle(LINK head);
// ex7
void print_l(LINK head);
// ex8
LINK concatenate(LINK a, LINK b);
// ex9
LINK copy_cat(LINK a, LINK b);
// ex10
LINK concatenate_rec(LINK,LINK);
// ex11
void prepend(LINK*, DATA);
// ex12
void append(LINK*, DATA);
// ex13
void insert_where(LINK *head, DATA el, DATA where);
// ex14
void insert_at(LINK *head, DATA el, int at);

