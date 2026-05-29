#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int value;

    // Con trỏ tới node cha
    Node* parent;
};

int main() {

    // =====================================================
    // Stack lưu OBJECT Node
    // =====================================================
    // Mỗi lần push:
    // -> toàn bộ object sẽ bị COPY vào stack
    // =====================================================
    stack<Node> st;

    // =====================================================
    // Tạo root node
    // =====================================================
    Node root;

    root.value = 1;
    root.parent = NULL;

    cout << "Dia chi root goc: "
         << &root << endl;

    // Push root vào stack
    // Stack sẽ tạo 1 BẢN SAO của root
    st.push(root);

    // =====================================================
    // Tạo child node
    // =====================================================
    Node child;

    child.value = 2;

    // Parent đang trỏ tới root GỐC
    // KHÔNG PHẢI bản copy trong stack
    child.parent = &root;

    st.push(child);

    // =====================================================
    // Lấy node trên cùng
    // =====================================================
    Node topNode = st.top();

    cout << "\n===== TOP NODE =====" << endl;

    cout << "Top value: "
         << topNode.value << endl;

    cout << "Dia chi topNode: "
         << &topNode << endl;

    // =====================================================
    // In parent
    // =====================================================
    if(topNode.parent != NULL){

        cout << "Parent value: "
             << topNode.parent->value << endl;

        cout << "Dia chi parent: "
             << topNode.parent << endl;
    }

    // =====================================================
    // NHẬN XÉT
    // =====================================================
    // stack<Node> sẽ COPY object.
    // Điều này có thể gây:
    // + tốn bộ nhớ
    // + parent pointer không đồng nhất
    // + dễ lỗi dangling pointer
    // + khó quản lý cây DFS/BFS lớn
    // =====================================================

    return 0;
}