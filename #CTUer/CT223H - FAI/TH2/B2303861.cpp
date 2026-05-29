#include <algorithm>
#include <iostream>
#include <vector>

#define ROWS 3
#define COLS 3
#define EMPTY 0
#define MAX_OPERATOR 4
#define MAX_LENGTH 500

using namespace std;

/*
eightPuzzel[ROWS][COLS]: các ô trong trạng thái của 8 ô số, với ROWS là số
lượng hàng, COLS là số lượng cột.
emptyRow: vị trí hàng của ô trống
emptyCol: vị trí cột của ô trống
*/
// Declare state of 8 puzzle
struct State {
    int puzzle[ROWS][COLS];
    int empty_row;
    int empty_col;
};

// Declare node to store tree search
struct Node {
    State state;          // Current state of 8 puzzle
    Node* parent;         // Pointer to parent node
    int heuristic_value;  // Heuristic value of the node
    int no_function;
};

// static string - mảng tỉnh
const string action[] = {"First state", "Move cell EMPTY to UP", "Move cell EMPTY to DOWN",
                         "Move cell EMPTY to LEFT", "Move cell EMPTY to RIGHT"};

//-----Method for State-----
bool compare_states(State a, State b);

// Is current state matches state goal?
bool goal_check(State state, State goal);

bool up_operator(State state, State* result);

bool down_operator(State state, State* result);

bool left_operator(State state, State* result);

bool right_operator(State state, State* result);

bool call_operators(State state, State* result, int opt);

// Retrieve current state of 8 puzzle
void print_state(State state);

// Count number box diff to goal
int heuristic1(State state, State goal);

// Cout number step push incorrect box to correct goal
int heuristic2(State state, State goal);

//------Method for Node-------

// Is state in open, close stack?
// Store position search to valuable *position
Node* find_state(State state, vector<Node*>& v, vector<Node*>::iterator* position);

// Sort nodes based on heuristic weight
// Comparator used by vector sorting
// Vector elements are passed to Node* a and Node* b for comparison
bool compare_heuristic(Node* a, Node* b);

// f = h
Node* best_first_search(State state, State goal);

void print_way_to_get_goal(Node* node);

int main() {
    State state, result;
    cout << "Enter initial state (use 0 for empty cell, only one empty cell):\n";
    int has_empty_cell = 0;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            cin >> state.puzzle[row][col];
            if (state.puzzle[row][col] == EMPTY) {
                state.empty_row = row;
                state.empty_col = col;
                has_empty_cell++;
            }
        }
    }
    if (has_empty_cell == 0 || has_empty_cell > 1) {
        cout << "Error: Initial state must contain exactly one empty cell (0)." << endl;
        return 1;  // Exit with error code
    }

    cout << "\n----Initial state of 8 puzzle-----\n";
    print_state(state);

#if 0
    cout << "\n-----Call operation-----";
    for (int opt = 1; opt <= MAX_OPERATOR; opt++) {
        if (call_operators(state, &result, opt)) {
            if (!compare_states(state, result)) {
                cout << "\nSuccessful action " << action[opt] << ":\n";
                print_state(result);
            }
        } else {
            cout << "\nError Action " << action[opt] << ":\n";
        }
    }

    cout << "\n---- Finish call operation--------\n";
    print_state(state);
#endif
#if 1  // Best first search
    State goal;
    has_empty_cell = 0;
    cout << "Enter goal state (use 0 for empty cell, only one empty cell):\n";
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            cin >> goal.puzzle[row][col];
            if (goal.puzzle[row][col] == EMPTY) {
                goal.empty_row = row;
                goal.empty_col = col;
                has_empty_cell++;
            }
        }
    }
    if (has_empty_cell == 0 || has_empty_cell > 1) {
        cout << "Error: Goal state must contain exactly one empty cell (0)." << endl;
        return 1;  // Exit with error code
    }

    cout << "\n----Goal state of 8 puzzle-----\n";
    print_state(goal);

    Node* result_node = best_first_search(state, goal);
    if (result_node != NULL) {
        cout << "\nPath to reach goal state:\n";
        print_way_to_get_goal(result_node);
    } else {
        cout << "No solution found." << endl;
    }

#endif
    return 0;
}

//------Method for State of 8 puzzle-------
bool compare_states(State a, State b) {
    // Check empty cell
    if (a.empty_row != b.empty_row || a.empty_col != b.empty_col) {
        return false;
    }
    // Check value of cell
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (a.puzzle[row][col] != b.puzzle[row][col]) {
                return false;
            }
        }
    }
    return true;
}

bool goal_check(State state, State goal) {
    return compare_states(state, goal);
}

bool up_operator(State state, State* result) {
    // Copy current state to result
    *result = state;
    int empty_row_current = state.empty_row, empty_col_current = state.empty_col;

    if (empty_row_current > 0) {  // Check if empty cell can move up (not in the first row)
        /*
        Example:
        Current state: p[2][2] empty cell
        */
        // Update the position of the empty cell
        result->empty_row = empty_row_current - 1;  // move empty cell up: r = 2 -> 1
        result->empty_col = empty_col_current;      // unchanged
        // Update value of new state after move
        result->puzzle[empty_row_current][empty_col_current] =
            state.puzzle[empty_row_current - 1]
                        [empty_col_current];  // Move value above to empty cell: p[2][2] = p[1][2]
        result->puzzle[empty_row_current - 1][empty_col_current] = EMPTY;  // P[1][2] = 0
        return true;
    }
    return 0;
}

bool down_operator(State state, State* result) {
    *result = state;
    int empty_row_current = state.empty_row, empty_col_current = state.empty_col;

    if (empty_row_current < ROWS - 1) {  // Check if empty cell can move down (not in the last row)
        /*
        Example:
        Current state: p[0][2] empty cell
        */
        result->empty_row = empty_row_current + 1;  // move empty cell down: r = 0 -> 1
        result->empty_col = empty_col_current;

        result->puzzle[empty_row_current][empty_col_current] =
            state.puzzle[empty_row_current + 1]
                        [empty_col_current];  // Move value below to empty cell: p[0][2] = p[1][2]
        result->puzzle[empty_row_current + 1][empty_col_current] = EMPTY;  // P[1][2] = 0
        return true;
    }
    return 0;
}

bool left_operator(State state, State* result) {
    *result = state;
    int empty_row_current = state.empty_row, empty_col_current = state.empty_col;

    if (empty_col_current > 0) {  // not in the first column
        // Ex: Current state p[2][2] empty cell

        result->empty_row = empty_row_current;
        result->empty_col = empty_col_current - 1;  // move empty cell left: c = 2 -> 1

        result->puzzle[empty_row_current][empty_col_current] =
            state.puzzle[empty_row_current][empty_col_current -
                                            1];  // Move value left to empty cell: p[2][2] = p[2][1]
        result->puzzle[empty_row_current][empty_col_current - 1] = EMPTY;  // P[2][1] = 0
        return true;
    }
    return 0;
}

bool right_operator(State state, State* result) {
    *result = state;
    int empty_row_current = state.empty_row, empty_col_current = state.empty_col;

    if (empty_col_current < COLS - 1) {  // not in the last column
        result->empty_row = empty_row_current;
        result->empty_col = empty_col_current + 1;

        result->puzzle[empty_row_current][empty_col_current] =
            state.puzzle[empty_row_current][empty_col_current + 1];
        result->puzzle[empty_row_current][empty_col_current + 1] = EMPTY;
        return true;
    }
    return 0;
}

bool call_operators(State state, State* result, int opt) {
    switch (opt) {
        case 1:
            return up_operator(state, result);
        case 2:
            return down_operator(state, result);
        case 3:
            return left_operator(state, result);
        case 4:
            return right_operator(state, result);
        default:
            return false;
    }
}

// Dem so o sai khac so voi goal
int heuristic1(State state, State goal) {
    int count = 0;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (state.puzzle[row][col] != goal.puzzle[row][col]) {
                count++;
            }
        }
    }
    return count;
}

// Dem so buoc chuyen o sai ve dung vi tri goal
int heuristic2(State state, State goal) {
    int count = 0;
    int row, col, goal_row, goal_col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            int current_value = state.puzzle[row][col];
            if (current_value != EMPTY) {  // Not empty cell
                // Find position of current cell in goal state
                for (goal_row = 0; goal_row < ROWS; goal_row++) {
                    for (goal_col = 0; goal_col < COLS; goal_col++) {
                        if (goal.puzzle[goal_row][goal_col] == current_value) {
                            count += abs(row - goal_row) +
                                     abs(col - goal_col);  // Calculate Manhattan distancec
                            goal_row = ROWS;               // Break loop goal_row
                            goal_col = COLS;               // Break loop goal_col
                        }
                    }
                }
            }
        }
    }
    return count;
}

void print_state(State state) {
    int row, col;
    cout << "\n-------------\n";
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            cout << "| " << state.puzzle[row][col] << " ";
        }
        cout << "|" << endl;
    }
    cout << "-------------" << endl;
}
//------Method for Node-------

// vector<Node*> v, vector<Node*>::iterator* position - v: vector of Node* to search, position:
// iterator to store position of found state in vector
Node* find_state(State state, vector<Node*>& v, vector<Node*>::iterator* position) {
    vector<Node*>::iterator it = v.begin();  //
    if (v.size() == 0) {
        return NULL;
    }
    while (it != v.end()) {
        if (compare_states(state, (*it)->state)) {
            *position = it;  // Store position of found state in vector
            return *it;      // Return pointer to Node with found state
        }
        it++;
    }
    return NULL;  // State not found in vector
}  // Cần xem xét lại cách truyền tham chiếu

// Sort by weight of heuristic value
bool compare_heuristic(Node* a, Node* b) {
    return a->heuristic_value >
           b->heuristic_value;  // Sort in descending order (higher heuristic value first)
}

// f = h
Node* best_first_search(State state, State goal) {
    vector<Node*> open_BFS(MAX_LENGTH);
    open_BFS.clear();
    vector<Node*> close_BFS(MAX_LENGTH);
    close_BFS.clear();

    Node* root = new Node;
    root->state = state;
    root->parent = NULL;                              // Root node has no parent
    root->heuristic_value = heuristic1(state, goal);  // Tim nut sai vi tri it nhat
    root->no_function = 0;                            // No action for root node

    open_BFS.push_back(root);

    while (!open_BFS.empty()) {
        Node* node =
            open_BFS
                .back();  // Lấy phần tử ở cuối cùng của vector, nên sort từ cao đến thấp. (O(1))
        open_BFS.pop_back();
        close_BFS.push_back(node);
        if (goal_check(node->state, goal)) {
            cout << "Goal" << endl;
            return node;  // Return node containing goal state
        }

        for (int opt = 1; opt <= MAX_OPERATOR; opt++) {
            State new_state;
            if (call_operators(node->state, &new_state, opt)) {
                Node* new_node = new Node{new_state, node, heuristic1(new_state, goal), opt};

                // Check if new_node is in open/closed list
                vector<Node*>::iterator pos_open, pos_close;
                Node* found_in_open = find_state(new_state, open_BFS, &pos_open);
                Node* found_in_close = find_state(new_state, close_BFS, &pos_close);
                if (found_in_open == NULL && found_in_close == NULL) {
                    open_BFS.push_back(new_node);  // Add new node to open list
                } else if (found_in_open != NULL &&
                           new_node->heuristic_value < found_in_open->heuristic_value) {
                    open_BFS.erase(pos_open);      // Remove old node with higher heuristic value
                    open_BFS.push_back(new_node);  // Add new node with lower heuristic value
                } else if (found_in_close != NULL &&
                           new_node->heuristic_value < found_in_close->heuristic_value) {
                    close_BFS.erase(pos_close);  // Remove old node with higher heuristic value
                    open_BFS.push_back(
                        new_node);  // Add new node with lower heuristic value to open list
                }
            }
        }
        // Sort open list based on heuristic value (so that node with lowest heuristic value is at
        // the end of the vector)
        sort(open_BFS.begin(), open_BFS.end(), compare_heuristic);
    }
    return NULL;  // No solution found
}

void print_way_to_get_goal(Node* node) {
    vector<Node*> path;

    // Trace back to parent
    while (node != NULL) {
        path.push_back(node);
        node = node->parent;
    }

    // Error
    //  path.push_back(node);

    int no_action = 0;
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << "Action " << no_action << ": " << action[path.at(i)->no_function] << endl;
        print_state(path.at(i)->state);
        no_action++;
    }
}
