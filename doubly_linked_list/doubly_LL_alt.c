#include "structure.h"
typedef struct node_DLL
{
    struct node_DLL *left;
    int data;
    struct node_DLL *right;
} node_DLL;

typedef struct doubly_LL
{
    node_DLL *head;
    node_DLL *tail;
    int count;
} doubly_LL;

doubly_LL *DLL_create()
{
    // Create and allocate a DLL type
    doubly_LL *p;
    p = malloc(sizeof(doubly_LL));
        if (p == NULL)
     {printf("ERROR: Could not allocate a new node\n"); exit(1);}
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
    return p;
}

node_DLL *create_node(int k)
{
    // Create a node and assign its value and pointers
    node_DLL *n = malloc(sizeof(node_DLL));
    if (n == NULL)
     {printf("ERROR: Could not allocate a new node\n"); exit(1);}
    n->data = k;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void DLL_append(doubly_LL *p, int k)
{
    // if creating DLL is forgotten
    // if (p  NULL)
    //     DLL_create();
    
    // Creates a node, must check if there is already a node in the list
    node_DLL *n = create_node(k);
    if (p->count == 0) /* in case the Count was to be removed */
    {
        p->head = n;
        p->tail = p->head;
    }
    // if there exists a node
    else
    {
        p->tail->right = n;
        n->left = p->tail;
        p->tail = n;
    }
    // increment the count
    p->count++;
}
void DLL_prepend(doubly_LL *p, int k)
{
    node_DLL *n = create_node(k);
    // if the list is empty
    if (p->count == 0)
    {
        p->head = n;
        p->tail = n; /* same as p->tail = p->head (written in append function)*/
    }
    else
    {
        n->right = p->head;
        p->head->left = n;
        p->head = n;
    }
    // increment the count
    p->count++;
}
void DLL_add_at(doubly_LL *p, int at, int k)
{
    // if at was bigger than the Count
    if (at >= p->count)
    {
        printf("List size is: %d, Can not add at %d\n", p->count, at);
        return;
    }
    
    // if the node was to be added at 0 indexing, or the list happened to be empty
    if (at == 0)
        {DLL_prepend(p, k);return;}
    if (at == p->count) /* This is the reason for creating the Count property */
        {DLL_append(p, k);return;}
    // iterate to get to 'at''th node
    node_DLL *n = create_node(k);
    node_DLL *q = p->head;
    while(at-- > 0)
        q = q->right;
    // Now that we are at the "'at'th" node, time to insert the node
    // node_DLL* left_q = q->left;
    // node_DLL* right_q = q;
    // n->right = right_q;
    // n->left = left_q;
    // left_q->right = n;
    // right_q->left = n;
    n->left = q->left;
    q->left->right = n;
    n->right = q;
    q->left = n;
    p->count++;
    
}
void DLL_print_headToTail(doubly_LL *p)
{
    node_DLL *q = p->head;
    // iterates all nodes from head to tail
    while (q != NULL)
    {
        printf("%d\t", q->data);
        q = q->right;
    }
    printf("\n");
}

int DLL_get_count(doubly_LL *p){
    return p->count;
}