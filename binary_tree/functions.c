#include "tree.h"
void inOrder(BTREE root, void (*prn_fct)())
{
    if (root != NULL) {
        inOrder(root->left, prn_fct);
        prn_fct(root->d);
        inOrder(root->right, prn_fct);
    }
}

void preOrder(BTREE root, void (*prn_fct)())
{
    if (root != NULL) {
        prn_fct(root->d);
        preOrder(root->left, prn_fct);
        preOrder(root->right, prn_fct);
    }
}

void postOrder(BTREE root, void (*prn_fct)())
{
    if (root != NULL) {
        postOrder(root->left, prn_fct);
        postOrder(root->right, prn_fct);
        prn_fct(root->d);
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
    if (i >= size)
        return NULL;
    else
    {
        return (init_node(a[i], create_tree(a, 2 * i + 1, size), create_tree(a, 2 * i + 2, size)));
    }
}

BTREE insert_BST(BTREE root, DATA value, int (*cmp)(const void*, const void*)) {
    if (root == NULL)
        return init_node(value, NULL, NULL);

    if (cmp(&value, &root->d) < 0)
        root->left = insert_BST(root->left, value, cmp);
    else
        root->right = insert_BST(root->right, value, cmp);

    return root;
}
BTREE create_BST(DATA a[], int size, int (*cmp)(const void*, const void*))
{
    BTREE root = NULL;
    for (int i = 0; i < size; i++)
        root = insert_BST(root, a[i], cmp);
    return root;
}

// Ex29 1- count the number of nodes
int count_Btree(BTREE root)
{
    if (root == NULL)
        return 0;
    return count_Btree(root->left) + count_Btree(root->right) + 1;
}

int count_Btree_nodes_having(BTREE root, void* el, int (*cmp)(const void* e, const void* t))
{
    if (root == NULL)
        return 0;
    return count_Btree_nodes_having(root->left, el, cmp) + count_Btree_nodes_having(root->right, el, cmp) + !cmp(el, &root->d); /* !cmp: since cmp return 1 or -1 if not equal, then !cmp makes them 0, aka false*/
}

void print_leaf(BTREE root, void (*prn_fct)())
{
    if (root == NULL)
        return;
    print_leaf(root->left, prn_fct);
    print_leaf(root->right, prn_fct);
    if (!root->left && !root->right)
        prn_fct(root->d);
}


// Print binary tree with visual structure
void print_tree(BTREE root, void (*prn_fct)(), int level)
{
    if (root == NULL)
        return;

    // Increase spacing for children
    level += 4;

    // Print right subtree first (will appear at top)
    print_tree(root->right, prn_fct, level);

    // Print current node with indentation
    printf("\n");
    for (int i = 0; i < level; i++)
        printf(" ");

    prn_fct(root->d);

    // Print left subtree (will appear at bottom)
    print_tree(root->left, prn_fct, level);
}

// Wrapper function to start printing
void print_tree_structure(BTREE root, void (*prn_fct)())
{
    print_tree(root, prn_fct, 0);
    printf("\n");
}

int inOrder_to_array(DATA key[], BTREE root, int i)
{
    if (root != NULL) {
        i = inOrder_to_array(key, root->left, i);
        key[i++] = root->d;
        i = inOrder_to_array(key, root->right, i);
        return i;
    }
    return i;
}

void inOrder_to_array_itr(BTREE root, DATA key[], int size)
{
    BTREE stack[size];
    int top = -1;
    int i = 0;
    BTREE cur = root;
    while ((cur || top >= 0) && i < size) {
        while (cur)
        {
            stack[++top] = cur;
            cur = cur->left;
        }
        cur = stack[top--];
        key[i++] = cur->d;
        cur = cur->right;
    }
}

BTREE replace_root_with_rightmost_leaf(BTREE root)
{
    BTREE t = root;
    // Must preserve parent in order to delete leaf
    BTREE parent;
    // always go right, else left, untill a leaf is reached
    while (t->right || t->left)/* Leaf condition : !(t->right == NULL && t->left == NULL)*/
    {
        parent = t;
        if (t->right)
        {
            t = t->right;
        }
        else {
            t = t->left;
        }
    }
    // replace 
    root->d = t->d;
    if (parent->right == t)
        parent->right = NULL;
    else
        parent->left = NULL;
    free(t);
    return root;
}

// BTREE replace_root_with_rightmost_leaf_rec(BTREE root, int i)
// {
//     if (root->right || root->left)
//     {
//         replace_root_with_rightmost_leaf_rec(root->right, i + 1);
//         replace_root_with_rightmost_leaf_rec(root->left, i + 1);
//     }
//     printf("ROOT: %d ", root->d);
//     return root;
// }

// void swap_data(BTREE* a, BTREE* b)
// {
//     DATA tmp = (*a)->d;
//     (*a)->d = (*b)->d;
//     (*b)->d = tmp;
// }

// void sort_tree(BTREE tree, int (*cmp)())
// {
//     if (!tree)
//         return;
//     if (tree->right && cmp(tree->d, tree->right->d) < 0)
//         swap_data(&tree->d, &tree->right->d);
//     if (tree->left && cmp(tree->d, tree->left->d) < 0)
//         swap_data(&tree->d, &tree->left->d);
//     sort_tree(tree->right, cmp);
//     sort_tree(tree->left, cmp);
// }

// void heap_sort(BTREE tree, DATA out[], int i, int (*cmp)())
// {
//     if (tree)
//     {
//         out[i] = tree->d;
//         replace_root_with_rightmost_leaf(tree);
//     }
//     if (cmp(tree->d, tree->right->d) < 0)
//         swap_data(&tree->d, &tree->right->d);
//     if (cmp(tree->d, tree->left->d) < 0)
//         swap_data(&tree->d, &tree->left->d);


// }


static void swap_data_vals(DATA* a, DATA* b)
{
    DATA tmp = *a;
    *a = *b;
    *b = tmp;
}
void heapify_max(BTREE t, int (*cmp)(const void*, const void*))
{
    if (!t) return;
    /* Heapify children first (post-order) */
    heapify_max(t->left, cmp);
    heapify_max(t->right, cmp);

    /* Select largest among t, left, right */


}

void heapify_min(BTREE t, int (*cmp)(const void*, const void*))
{
    if (!t) return;

    heapify_min(t->left, cmp);
    heapify_min(t->right, cmp);

    if (t->left && cmp(&t->left->d, &t->d) < 0)
    {
        swap_data_vals(&t->d, &t->left->d);;
        heapify_min(t, cmp);
    }
    if (t->right && cmp(&t->right->d, &t->d) < 0)
    {
        swap_data_vals(&t->d, &t->right->d);
        heapify_min(t, cmp);
    }
}


void heap_sort(BTREE t, DATA arr[], int size, int i, int (*cmp)())
{
    if (i >= size)
    {
        if (!t)
            free(t);
        return;
    }

    arr[i] = t->d;
    replace_root_with_rightmost_leaf(t);
    heapify_min(t, cmp);
    heap_sort(t, arr, size, i + 1, cmp);
}

int tree_height(BTREE t)
{
    if (!t) return 0;
    int lh = tree_height(t->left);
    int rh = tree_height(t->right);
    return (lh > rh ? lh : rh) + 1;
}

void bfs_print(BTREE t, void (*prn)())
{
    if (!t)
        return;
    int n = count_Btree(t);
    int lvl_count = 0;
    BTREE q[n];
    int front = 0, rear = 0;
    // initial state
    q[rear++] = t;
    while (front < rear) {
        lvl_count = rear - front;
        int space = n;
        // leading spaces
        while(--space)
            printf(" ");
        n /=2;
        while (lvl_count--) {
            BTREE node = q[front++];
            prn(node->d);
            if (node->left)
            q[rear++] = node->left;
            if (node->right)
            q[rear++] = node->right;
    
        }
        printf("\n");
    }
}