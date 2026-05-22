#include <stack>

#include "B2303861_Functions.cpp"

struct Node {
    State state;
    struct Node* Parent;
    int no_function;  // Store number of operation
};

// stack<Node> open_stack;
// stack<Node> close_stack;

bool compare_states(State a, State b) {
    return a.x == b.x && a.y == b.y;
}

// Check state in stack
int find_state(State state, stack<Node*> open_stack);
void print_ways_to_get_goal(Node* node);
Node* DFS_Algorithm(State state);

int main() {
    State cur_state = {0, 0};
    Node* result = DFS_Algorithm(cur_state);
    print_ways_to_get_goal(result);
    return 0;
}

void print_ways_to_get_goal(Node* node) {
    stack<Node*> stack_print;
    while (node->Parent != NULL) {
        stack_print.push(node);
        node = node->Parent;
    }

    stack_print.push(node);

    int no_action = 0;

    while (!stack_print.empty()) {
        cout << ("Action " + to_string(no_action) + ": " + action[stack_print.top()->no_function])
             << endl;
        print_state(stack_print.top()->state);
        stack_print.pop();
        no_action++;
    }
}

int find_state(State state, stack<Node*> open_stack) {
    while (!open_stack.empty()) {
        if (compare_states(open_stack.top()->state, state)) return 1;
        open_stack.pop();
    }
    return 0;
}

Node* DFS_Algorithm(State state) {
    stack<Node*> open_stack;
    stack<Node*> close_stack;

    Node* root = new Node;
    root->state = state;
    root->Parent = NULL;
    root->no_function = 0;

    open_stack.push(root);

    while (!open_stack.empty()) {
        Node* node = open_stack.top();
        open_stack.pop();

        if (goal_check(node->state)) {
            return node;
        }

        close_stack.push(node);

        for (int opt = 1; opt <= NUM_ACTIONS; opt++) {
            State result;
            int isSuccess = call_operations(node->state, &result, opt);
            if (isSuccess == 1) {
                if (find_state(result, open_stack) || find_state(result, close_stack)) continue;

                Node* new_node = new Node;
                new_node->state = result;
                new_node->Parent = node;
                new_node->no_function = opt;

                open_stack.push(new_node);
            }
        }
    }
    return NULL;
}