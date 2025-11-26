#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"
/* Here DATA is generic in a way that type.h must include an arbitrary type DATA */
struct node {
    DATA d;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;
typedef NODE *BTREE;

#include "fct_proto.h"