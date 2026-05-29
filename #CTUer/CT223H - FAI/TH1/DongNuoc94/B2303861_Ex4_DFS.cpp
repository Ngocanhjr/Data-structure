// Draw the graph using DFS algorithm
#include <stack>

#include "B2303861_Functions.cpp"

struct Node {
    State state;
    Node* parent;
    int no_operation;  // number action operated
};

// Stack lưu các node chưa duyệt.
// Sử dụng Node* để:
// + tránh copy toàn bộ node
// + giữ liên kết giữa node con và node cha- > giữ cấu trúc cây
// + hỗ trợ truy vết lời giải
int find_state(State state, stack<Node*> open_stack);  // Stack store address of Node

int compareStates(State a, State b);

Node* DFS_algorithm(State state);

void print_ways_to_get_goal(Node* node);

int main() {
    cout << "Enter initial state of X và Y: ";
    int cur_x, cur_y;
    cin >> cur_x >> cur_y;
    if (cur_x > TANK_CAPACITY_X || cur_y > TANK_CAPACITY_Y) {
        cout << "Water must be under tank capacity!";
        return 0;
    } else {
        cout << "Initialization successful" << endl;
    }

    State cur_state = {cur_x, cur_y};

    Node* result = DFS_algorithm(cur_state);

    if (result == NULL) {
        cout << "No solution found!";
    } else {
        print_ways_to_get_goal(result);
    }
}

int compareStates(State a, State b) {
    return a.x == b.x && b.y == a.y;
}

// Find state in stack?
int find_state(State state, stack<Node*> open_stack) {
    while (!open_stack.empty()) {
        if (compareStates(open_stack.top()->state, state)) return 1;
        open_stack.pop();
    }

    return 0;
}

void print_ways_to_get_goal(Node* node) {
    stack<Node*> st_print;
    // Truy vet nguoc tu ngon ve goc
    while (node->parent != NULL) {
        st_print.push(node);
        node = node->parent;
    }

    // in ra tu goc
    int no_action = 0;
    while (!st_print.empty()) {
        // In ra hành động
        cout << "\nAction " << no_action << ": " << action[st_print.top()->no_operation] << endl;
        print_state(st_print.top()->state);  // trạng thái hiện tại
        st_print.pop();
        no_action++;
    }
}

// Tim ket qua cuoi cung
Node* DFS_algorithm(State state) {
    stack<Node*> open_DFS;
    stack<Node*> close_DFS;

    Node* root = new Node;
    root->state = state;
    root->parent = NULL;
    root->no_operation = 0;

    open_DFS.push(root);

    while (!open_DFS.empty()) {
        Node* X = open_DFS.top();
        open_DFS.pop();
        close_DFS.push(X);
        if (goal_check(X->state)) {
            return X;
        }

        // Goi cac trang thai cua X
        for (int opt = 1; opt <= NUM_ACTIONS; opt++) {
            State new_state;
            make_null_state(&new_state);

            // Goi hanh dong cua X va kiem tra ton tai chua
            if (call_operations(X->state, &new_state, opt)) {
                // neu trang moi da ton tai thi tiep tuc
                if (find_state(new_state, close_DFS) || find_state(new_state, open_DFS)) {
                    continue;
                }

                // Dua node moi vao duyet
                Node* new_node = new Node;
                new_node->state = new_state;
                new_node->parent = X;
                new_node->no_operation = opt;  // Luu hanh dong thuc hien
                open_DFS.push(new_node);
            }
        }
    }
    return NULL;
}
