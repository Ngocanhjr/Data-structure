# Pointer

`Node` : Object thực tế

`Node*`: Pointer (Lưu trữ địa chỉ của object Node)

`Node root`

-> Object Node thật

`Node* root = new Node;` : Tạo Object Node trong heal memory, root lưu địa chỉ của object đó

Lấy giá trị -> `*root` : giải them chiếu (dereference), lấy object Node thật mà địa chỉ trỏ tới

```cpp
root->value

//tương đương

(*root).value

```
