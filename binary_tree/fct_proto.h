
BTREE new_node();
BTREE init_node(DATA d1, BTREE p1, BTREE p2);
BTREE create_tree(DATA a[], int i, int size);
BTREE create_BST(DATA a[], int size, int (*cmp)(const void*, const void*));
void  inOrder(BTREE root, void (*prn_fct)());
void  preOrder(BTREE root, void (*prn_fct)());
void  postOrder(BTREE root, void (*prn_fct)());
int  count_Btree(BTREE root);
int  count_Btree_nodes_having(BTREE root, void* el, int (*cmp)(const void* e,const void *t));
void print_leaf(BTREE root, void (*prn_fct)());
void print_tree(BTREE root, void (*prn_fct)(), int level);
int inOrder_to_array(DATA key[], BTREE root, int i);
void inOrder_to_array_itr(BTREE root, DATA key[], int size);
BTREE replace_root_with_rightmost_leaf(BTREE root);
BTREE replace_root_with_rightmost_leaf_rec(BTREE root, int i);
void tree_to_min_heap(BTREE tree);

void heapify_max(BTREE t, int (*cmp)(const void*, const void*));
void heapify_min(BTREE t, int (*cmp)(const void*, const void*));
void heap_sort(BTREE t, DATA arr[], int size, int i, int (*cmp)());
void bfs_print(BTREE t, void (*prn)());
int tree_height(BTREE t);
void bfs_print_pretty(BTREE root, void (*prn)());


