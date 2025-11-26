#include <stdio.h>
#include <stdlib.h>

typedef struct slist slist;

// function definitions
void append(slist *p, int n);
void add_at(slist *p, int n);
void print_list(slist *p);