#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int value;

    // Liên kết tới node cha
    Node* parent;
};

int main() {

    // =====================================================
    // Stack lưu POINTER tới Node
    // =====================================================
    // Mỗi lần push:
    // -> chỉ copy địa chỉ bộ nhớ
    // -> KHÔNG copy toàn bộ object
    // =====================================================
    stack<Node*> st;

    // =====================================================
    // Tạo root node động
    // =====================================================
    Node* root = new Node;

    root->value = 1;
    root->parent = NULL;

    cout << "Dia chi root: "
         << root << endl;

    // Push địa chỉ root vào stack
    st.push(root);

    // =====================================================
    // Tạo child node: Cấp phát động
    // =====================================================
    Node* child = new Node;

    child->value = 2;

    // Parent trỏ trực tiếp tới root thật
    child->parent = root;

    st.push(child);

    // =====================================================
    // Lấy node trên cùng
    // =====================================================
    Node* topNode = st.top();

    cout << "\n===== TOP NODE =====" << endl;

    cout << "Top value: "
         << topNode->value << endl;

    cout << "Dia chi topNode: "
         << topNode << endl;

    // =====================================================
    // In parent
    // =====================================================
    if(topNode->parent != NULL){

        cout << "Parent value: "
             << topNode->parent->value << endl;

        cout << "Dia chi parent: "
             << topNode->parent << endl;
    }

    // =====================================================
    // Truy vết đường đi bằng parent
    // =====================================================
    cout << "\n===== TRUY VET =====" << endl;

    Node* current = topNode;

    while(current != NULL){

        cout << current->value << endl;

        current = current->parent;
    }

    // =====================================================
    // Giải phóng bộ nhớ
    // =====================================================
    delete root;
    delete child;

    // =====================================================
    // NHẬN XÉT
    // =====================================================
    // stack<Node*>:
    // + không copy object
    // + parent pointer ổn định
    // + phù hợp DFS/BFS/tree/graph
    // + truy vết lời giải dễ dàng
    // + hiệu năng tốt hơn
    // =====================================================

    return 0;
}

