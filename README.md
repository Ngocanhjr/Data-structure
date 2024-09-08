# ⭐️ Course Contents ⭐️
**Arrays vs Linked Lists**
- [x] ⌨ Linked List - Implementation in C/C++
- [x] ⌨ Linked List in C/C++ - Inserting a node at beginning
- [x] ⌨ Linked List in C/C++ - Insert a node at nth position
- [x] ⌨ Linked List in C/C++ - Delete a node at beginning
- [ ] ⌨ Update Delete a node at beginning using nead and tail
- [x] ⌨ Linked List in C/C++ - Delete a node at nth position
- [x] ⌨ Reverse a linked list - Iterative method
- [x] ⌨ Print elements of a linked list in forward and reverse order using recursion
- [ ] ⌨ Reverse a linked list using recursion (Update)

**Doubly Linked List**
- [ ] ⌨ Doubly Linked List - Implementation in C/C++

**Stack**
- [ ] ⌨ Array implementation of stacks
- [ ] ⌨ Linked List implementation of stacks
- [ ] ⌨ Reverse a string or linked list using stack.
- [ ] ⌨ Check for balanced parentheses using stack
- [ ] ⌨ Infix, Prefix and Postfix
- [ ] ⌨ Evaluation of Prefix and Postfix expressions using stack
- [ ] ⌨ Infix to Postfix using stack

**Queues**
- [ ] ⌨ Array implementation of Queue
- [ ] ⌨ Linked List implementation of Queue

**Trees**
- [ ] ⌨ Binary Tree
- [ ] ⌨ Binary Search Tree
- [ ] ⌨ Binary search tree - Implementation in C/C++
- [ ] ⌨ BST implementation - memory allocation in stack and heap
- [ ] ⌨ Find min and max element in a binary search tree
- [ ] ⌨ Find height of a binary tree
- [ ] ⌨ Binary tree traversal - breadth-first and depth-first strategies
- [ ] ⌨ Binary tree: Level Order Traversal
- [ ] ⌨ Binary tree traversal: Preorder, Inorder, Postorder
- [ ] ⌨ Check if a binary tree is binary search tree or not
- [ ] ⌨ Delete a node from Binary Search Tree
- [ ] ⌨ Inorder Successor in a binary search tree

**Graphs**
- [ ] ⌨ Properties of Graphs
- [ ] ⌨ Graph Representation part 01 - Edge List
- [ ] ⌨ Graph Representation part 02 - Adjacency Matrix
- [ ] ⌨ Graph Representation part 03 - Adjacency List

[FreeCodeCamp - Data Structures - Full Course Using C and C++](https://www.youtube.com/watch?v=B31LgI4Y4DQ)

# sort
Với kích thước dữ liệu đầu vào nhỏ(3000) nhìn chung tốc độ chênh lệch của các thuật toán là không rõ để nhận thấy.

Với mảng đã được sắp xếp, thì Bubble Sort và Shaker Sort cho tốc độ nhanh nhất do chi phí để biết được đây là mảng có thứ tự của 2 thuật toán trên là O(n).

Với mảng gần như đã được sắp xếp thì Insertion Sort và Binary Insertion Sort là những sự lựa chọn tốt nhất do số phép hoán đổi phải thực hiện ít.

Selection Sort cho tốc độ khá chậm trong đa số trường hợp do độ phức tạp luôn là O(n2), do đó Selection Sort chỉ nên dùng cho các trường hợp số lượng phần tử cần sắp xếp không quá nhiều.

Với mảng gần như đã được sắp xếp thì Shaker Sort cho tốc độ nhanh hơn đáng kể so với Bubble Sort, do thu hẹp được khoảng phải duyệt tiếp theo sau khi duyệt.

Shell Sort, Heap Sort, Merge Sort và Quick Sort có tốc độ ổn định xuyên suốt cả 4 loại dữ liệu đầu vào.

Flash Sort(được phát minh bởi Karl-Dietrich Neubert vào năm 1998) là một thuật toán cho tốc độ nhanh(thậm chí nhanh hơn cả Quick Sort) và tiêu tốn rất ít bộ nhớ, tuy nhiên cách thức xây dựng thuật toán trên khá phức tạp mà nếu có dịp mình sẽ có một bài viết riêng để nói về thuật toán này.

Counting Sort và Radix Sort là những thuật toán cho tốc độ nhanh, tuy nhiên cần đánh đổi bằng cách sử dụng thêm bộ nhớ.
