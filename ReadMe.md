# C Data Structures Library

A comprehensive collection of fundamental data structures implemented in C, created while studying "C for Everyone" by Ira Pohl.

## 📚 Contents

### Linear Data Structures

#### 1. **Stack**
Multiple implementations demonstrating different approaches:
- `stack.h` / `stack.c` - Basic stack (LIFO)
- `stack_polish.c` - Stack for Polish notation calculator
- `stack_simple.c` - Minimal stack example
- `stack_alt.c` - Alternative implementation
- **Exercises**: Infix/postfix conversion, expression evaluation

#### 2. **Queue**
FIFO queue implementations:
- `queue.h` / `queue.c` - Standard queue
- `queue_book.h` / `queue_book.c` - Textbook version
- **Ring Queue** (Circular Queue):
  - `ring_queue/ring_queue.c` - Efficient circular buffer
  - `ring_queue/ring_que.h` - Header with interface

#### 3. **Deque** (Double-Ended Queue)
- `deque/ex28_deque.h` / `ex28_deque.c`
- Insert/remove from both ends

#### 4. **Linked List** (Singly Linked)
Multiple implementations with progressive features:
- `list.h` / `list.c` - Basic singly linked list
- `slist.h` - Simple list interface
- **Progressive Examples**:
  - `10.1_self_referential.c` - Self-referential structures intro
  - `10.2_Linear_linked_list.c` - Basic linear list
  - `10.3_list_operation_with_tail.c` - Tail pointer optimization
  - `10.3_list_operation_recursive.c` - Recursive operations
  - `10.4_count_list_recursive.c` - Recursive counting
- **Exercises**: Insert, delete, concatenate, copy, reverse

#### 5. **Doubly Linked List**
Bidirectional traversal:
- `dll.h` / `dll.c` - Full doubly linked list
- `DLL_alt.h` / `doubly_LL_alt.c` - Alternative implementations
- Operations: `DLL_prepend`, `DLL_append`, `DLL_add_at`

### Tree Data Structures

#### 6. **Binary Search Tree (BST)**
- `binary_tree/tree.h` / `functions.c`
- `type.h` / `fct_proto.h` - Type definitions
- **Features**:
  - Insert, delete, search
  - Traversals: inorder, preorder, postorder, BFS
  - Height calculation
  - Tree balancing utilities
- **Exercises**: Various tree manipulation problems

#### 7. **General Tree** (N-ary Tree)
- `general_tree/gtree.h` / `functions.c`
- Arbitrary number of children per node

### Specialized Structures

#### 8. **Sparse Matrix**
- `sparse_matrix/sparseTranspose.c`
- Efficient storage for matrices with many zeros
- Transpose operation

## 🚀 Usage Examples

### Example: Using Stack
```c
#include "stack.h"

int main() {
    STACK s;
    reset(&s);
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    
    while (!empty(&s))
        printf("%d ", pop(&s));  // Output: 30 20 10
    
    return 0;
}
```

### Example: Using Queue
```c
#include "queue.h"

int main() {
    QUEUE q;
    initialize(&q);
    
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    
    while (!is_empty(&q))
        printf("%d ", dequeue(&q));  // Output: 1 2 3
    
    return 0;
}
```

### Example: Using Doubly Linked List
```c
#include "structure.h"

int main() {
    doubly_LL *dll = DLL_create();
    
    DLL_append(dll, 3);
    DLL_prepend(dll, 1);
    DLL_add_at(dll, 2, 1);  // Insert at index 1
    
    DLL_print_headToTail(dll);  // Output: 1 2 3
    
    return 0;
}
```

### Example: Using Binary Search Tree
```c
#include "tree.h"

int main() {
    int arr[] = {8, 4, 15, 2, 6, 9, 17};
    int n = 7;
    
    BTREE tree = create_BST(arr, n, cmp_int);
    
    printf("Inorder traversal:\n");
    inOrder(tree, prn_int);  // Output: 2 4 6 8 9 15 17
    
    printf("\nTree height: %d\n", tree_height(tree));
    
    return 0;
}
```

### Example: Using Linked List
```c
#include "list.h"

int main() {
    LIST *head = NULL;
    
    head = insert_front(head, 3);
    head = insert_front(head, 2);
    head = insert_front(head, 1);
    
    print_list(head);  // Output: 1 -> 2 -> 3 -> NULL
    
    head = delete_node(head, 2);
    print_list(head);  // Output: 1 -> 3 -> NULL
    
    return 0;
}
```

## 📂 Directory Structure

```
data_structures/
├── README.md
├── structure.h              # Common structure definitions
├── stack/                   # Stack implementations
│   ├── stack.h
│   ├── stack.c
│   ├── polish.h
│   └── exercises/
├── queue/                   # Queue implementations
│   ├── queue.h
│   ├── queue.c
│   └── exercises/
├── ring_queue/              # Circular queue
│   ├── ring_queue.c
│   └── ring_que.h
├── deque/                   # Double-ended queue
│   ├── ex28_deque.h
│   └── ex28_deque.c
├── linked_list/             # Singly linked list
│   ├── list.h
│   ├── list.c
│   └── exercises/
├── doubly_linked_list/      # Doubly linked list
│   ├── dll.h
│   └── dll.c
├── binary_tree/             # Binary search tree
│   ├── tree.h
│   ├── functions.c
│   └── exercises/
├── general_tree/            # N-ary tree
│   ├── gtree.h
│   └── functions.c
└── sparse_matrix/           # Sparse matrix
    └── sparseTranspose.c
```

## 🎓 Learning Path

1. **Stack** - Simplest LIFO structure
2. **Queue** - FIFO operations
3. **Linked List** - Dynamic memory & pointers
4. **Doubly Linked List** - Bidirectional traversal
5. **Binary Tree** - Hierarchical structures & recursion
6. **Advanced** - Ring queue, sparse matrices

## 🔑 Key Concepts Covered

- Dynamic memory allocation (`malloc`, `calloc`, `free`)
- Pointers and pointer arithmetic
- Recursion (tree traversals, list operations)
- Time complexity (O(1), O(n), O(log n))
- Self-referential structures
- Generic programming with `void*`
- Function pointers for callbacks
- Memory management

## 📊 Complexity Analysis

| Data Structure | Insert | Delete | Search | Space |
|----------------|--------|--------|--------|-------|
| Stack | O(1) | O(1) | O(n) | O(n) |
| Queue | O(1) | O(1) | O(n) | O(n) |
| Linked List | O(1)* | O(n) | O(n) | O(n) |
| Doubly LL | O(1)* | O(1)** | O(n) | O(n) |
| BST (balanced) | O(log n) | O(log n) | O(log n) | O(n) |
| BST (worst) | O(n) | O(n) | O(n) | O(n) |

\* At front/back  
\*\* With pointer to node

## 🛠️ Building & Testing

### Compiling Individual Examples

```bash
# Simple compilation
gcc -o program file.c

# With warnings
gcc -Wall -Wextra -o program file.c

# Multi-file programs
gcc -o program main.c implementation.c -I.
```

### Navigate to Specific Data Structure

```bash
# Example: Binary tree exercises
cd binary_tree/exercises

# Compile test file
gcc -Wall -o test test.c ../functions.c -I..

# Run
./test

# With debugging symbols
gcc -g -Wall -o test test.c ../functions.c -I..

# Memory leak detection (if valgrind installed)
valgrind ./test
```

## 📝 Notes

- Multiple versions (`_alt`, `_v2`, `_v3`) show different approaches
- Exercise files demonstrate practical usage
- `DATA` typedef allows easy type changes
- Always `free()` allocated memory

## 📖 References

- **Book**: "C for Everyone" by Ira Pohl
- **Course**: UC Santa Cruz - C for Everyone Specialization
- **Chapters**: C6-C10 (Pointers, Arrays, Structs, Dynamic Memory, ADTs)

## 🤝 Contributing

Contributions welcome:
- Add implementations
- Optimize code
- Add test cases
- Improve documentation

## 📄 License

Educational purposes - Free to use and modify

---

**Author**: Sepehr  
**Year**: 2024-2025  
**Context**: Data Structures study from "C for Everyone"
