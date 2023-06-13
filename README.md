# AVL Tree Library in C++

This is a comprehensive AVL tree library written in C++ that provides efficient and balanced binary search tree functionality. AVL trees are self-balancing binary search trees that ensure efficient search, insert, and delete operations with a worst-case time complexity of O(log n).

## Features

- **Balanced Tree Structure:** The library implements the AVL tree data structure, which automatically maintains balance by performing tree rotations whenever necessary.
- **Efficient Operations:** The AVL tree provides efficient search, insertion, and deletion operations, guaranteeing a worst-case time complexity of O(log n).
- **Generic Implementation:** The library is designed to work with any type of data, allowing users to store and retrieve various types of elements in the AVL tree.
- **Iterator Support:** It includes iterator classes to traverse the tree in both ascending and descending orders, enabling easy iteration over the elements.
- **Customizable Comparators:** Users can define their own comparison functions to accommodate custom data types or sorting orders.
- **Error Handling:** The library incorporates error handling mechanisms to gracefully handle scenarios such as out-of-memory conditions or invalid operations.
- **Memory Management:** The AVL tree library takes care of memory management, ensuring proper allocation and deallocation of nodes.

## Getting Started

To start using the AVL tree library in your C++ project, follow these steps:

1. Clone the repository: `git clone https://github.com/CodeApprentice43/Avl-Tree`
2. Include the necessary files in your project.
3. Create an instance of the AVL tree and begin utilizing its operations.

```cpp
#include "avl_tree.h"

int main() {
    // Create an instance of the AVL tree
    AVLTree<int> avlTree;

    // Insert elements into the tree
    avlTree.insert(5);
    avlTree.insert(2);
    avlTree.insert(8);
    
    // Perform search operation
    if (avlTree.search(2)) {
        // Element found
    }

    // Delete an element from the tree
    avlTree.remove(5);
    
    return 0;
}
```

