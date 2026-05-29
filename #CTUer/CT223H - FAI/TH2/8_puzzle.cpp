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
bool heuristic1(State state, State goal);

// Cout number step push incorrect box to correct goal
bool heuristic2(State state, State goal);

//------Method for Node-------

// Is state in open, close stack?
// Store position search to valuable *position
Node* find_state(State state, vector<Node*> v, vector<Node*>::iterator* position);

// Sort nodes based on heuristic weight
// Comparator used by vector sorting
// Vector elements are passed to Node* a and Node* b for comparison
bool compare_heuristic(Node* a, Node* b);

// f = h
Node* best_first_search(State state, State goal);

void print_way_to_get_goal(Node* node);

int main() {
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

bool heuristic1(State state, State goal) {
}

bool heuristic2(State state, State goal);

void print_state(State state) {
    int row, col;
    cout << "\n--------\n";
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            cout << "| " << state.puzzle[row][col] << " ";
        }
        cout << endl;
    }
}
//------Method for Node-------

Node* find_state(State state, vector<Node*> v, vector<Node*>::iterator* position);

bool compare_heuristic(Node* a, Node* b);

// f = h
Node* best_first_search(State state, State goal);

void print_way_to_get_goal(Node* node);
