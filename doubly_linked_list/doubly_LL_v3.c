#include "DLL.h"
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
/* Creates an empty Doubly Linked List 
Head is NULL
Tail is NULL
Count is 0
Example: doubly_LL *p = DLL_create(); */
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
/*Creates a node, Parameter given is the data to be stored in the node
Sets Left pointer and Right pointer to NULL
Example: node_DLL *n = create_node(2);*/
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
/* Connects a given Node as the second parameter to its given Left and Right Nodes as First and Third Parameter

Example(1): chain_nodes(NULL, ptr_to node, ptr_to doubly linked list head);*/
void chain_nodes(node_DLL *left_node, node_DLL * node, node_DLL *right_node)
{
    node->left = left_node;
    node->right = right_node;
    left_node->right = node;
    right_node->left = node;
}
/* Appends a new node to the end of the list
First parameter should be the doubly linked list
Second parameter should be the data in the node
Example: DLL_append(_ptr_to_dll p, 2);*/
void DLL_append(doubly_LL *p, int k)
{
    // if creating DLL is forgotten

    
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
/* Prepends a new node to the first of the list
First parameter should be the doubly linked list
Second parameter should be the data in the node
Example: DLL_prepend(_ptr_to_dll p, 2)*/
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
/* Inserts a new node to the given index of the list
First parameter should be the doubly linked list
Second parameter where in the list should be added
Third parameter should be the data in the node
Example: DLL_add_at(_ptr_to_dll, int at, 2);*/
void DLL_add_at(doubly_LL *p, int at, int k)
{
    // if at was bigger than the Count
    if (at-1 > p->count)
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
    chain_nodes(q->left, n, q);
    // n->left = q->left;
    // q->left->right = n;
    // n->right = q;
    // q->left = n;
    p->count++;
    
}
/* Takes Double Link List as the first parameter
Second parameter: 1 to print the list in normal order
-1 to print the list in reverse order
Example: DLL_print(_ptr_to_dll p, -1);*/
void DLL_print(doubly_LL *p, int dir)
{
    node_DLL *q;
    if (dir == 1)
        q = p->head;
    if (dir == -1)
        q = p->tail;

    // iterates all nodes from head to tail
    while (q != NULL)
    {
        printf("%d\t", q->data);
        if (dir == 1)
            q = q->right;
        if (dir == -1)
            q = q->left;
    }
    printf("\n");
}
/* to get the nodes count in the list */
int DLL_get_count(doubly_LL *p){
    return p->count;
}