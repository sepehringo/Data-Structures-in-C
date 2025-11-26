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

## 🚀 Usage

### Compiling Individual Examples

```bash
# Simple compilation
gcc -o program file.c

# With warnings
gcc -Wall -Wextra -o program file.c

# Multi-file programs
gcc -o program main.c implementation.c -I.