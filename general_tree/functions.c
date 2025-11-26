#include "gtree.h"

/* Create a new node. */

GTREE new_gnode()
{
    return malloc(sizeof(NODE));
}

GTREE init_gnode(DATA d1, int num, GTREE sibs)
{
    GTREE       tmp;
    tmp->d = d1;
    tmp->child_no = num;
    tmp->sib = sibs;
    return tmp;
}

/* Preoder traversal of general trees. */

void preorder_g(GTREE t, int ind)
{
    GTREE   tmp;              /* tmp traverses the sibiling list */

    tmp = &t[ind];           /* t[ind] is the root node */
    while(tmp != NULL) {
        printf("%c %d\n", tmp->d, tmp->child_no);
        preorder_g(t, tmp->child_no);
        tmp = tmp->sib;
    }
}