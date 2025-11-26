#include "tree.h"
void inOrder(BTREE root)
{
    if(root != NULL) {
        inOrder(root->left);
        printf("%c ", root->d);
        inOrder(root->right);
    }
}

void preOrder(BTREE root)
{
        if(root != NULL) {
            printf("%c ", root->d);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(BTREE root)
{
        if(root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ", root->d);
    }
}

// Creating Tree

/* Creating a binary tree. */

BTREE new_node()
{
    return malloc(sizeof(NODE));
}

BTREE init_node(DATA d1, BTREE p1, BTREE p2)
{
    BTREE   t;
    t = new_node();
    t->d = d1;
    t->left = p1;
    t->right = p2;
    return t;
}

/* Create a linked binary tree from an array. */

BTREE create_tree(DATA a[], int i, int size)
{
    if(i >= size)
        return NULL;
    else
        return (init_node(a[i],
            create_tree(a, 2 * i + 1, size), create_tree(a, 2 * i + 2, size)));
}