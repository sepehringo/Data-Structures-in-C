#ifndef TREE_H
#define TREE_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

struct node {
    DATA d;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;
typedef NODE *BTREE;

#include "fct_proto.h"
#endif // TREE_H