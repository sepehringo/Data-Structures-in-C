#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char    name[10];
    int     age;
    int     weight;
} DATA;

typedef struct dllist {
    DATA            d;
    struct dllist* prev;
    struct dllist* next;
} ELEMENT;

typedef ELEMENT* DLLINK;
