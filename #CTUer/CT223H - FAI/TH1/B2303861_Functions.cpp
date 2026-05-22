#include <iostream>
// Implement using DFS
#include <stack>

#define TANK_CAPACITY_X 9
#define TANK_CAPACITY_Y 4
#define EMPTY 0
#define GOAL 6
#define NUM_ACTIONS 6

using namespace std;

struct State {
    int x;  // current amount of water in tank X
    int y;  // current amount of water in tank Y
};

const string action[] = {"First state",        "Pour water full X",  "Pour water full Y",
                         "Pour water empty X", "Pour water empty Y", "Pour water X to Y",
                         "Pour water Y to X"};

// Initial state: both tanks are empty
void make_null_state(State* state) {
    state->x = 0;
    state->y = 0;
}

void print_state(State state) {
    cout << "X: " << state.x << "  ------ Y: " << state.y << endl;
}

// Check if the current state is the goal state
int goal_check(State state) {
    return (state.x == GOAL || state.y == GOAL);
}

int pour_water_full_x(State cur_state, State* result) {
    if (cur_state.x < TANK_CAPACITY_X) {
        // Can fill water -> fill Full
        result->x = TANK_CAPACITY_X;  // Fill tank X to its capacity
        result->y = cur_state.y;      // Tank Y remains unchanged
        return 1;
    }
    return 0;
}

int pour_water_full_y(State cur_state, State* result) {
    if (cur_state.y < TANK_CAPACITY_Y) {
        result->y = TANK_CAPACITY_Y;  // Fill tank Y to its capacity
        result->x = cur_state.x;      // Tank X remains unchanged
        return 1;
    }
    return 0;
}

int pour_water_empty_x(State cur_state, State* result) {
    // Have water -> empty
    if (cur_state.x > EMPTY) {
        result->x = EMPTY;        // Empty tank X
        result->y = cur_state.y;  // Tank Y remains unchanged
        return 1;
    }
    return 0;
}

int pour_water_empty_y(State cur_state, State* result) {
    if (cur_state.y > EMPTY) {
        result->y = EMPTY;        // Empty tank Y
        result->x = cur_state.x;  // Tank X remains unchanged
        return 1;
    }
    return 0;
}

int pour_water_x_to_y(State cur_state, State* result) {
    // X -> Y
    // X: has water ; y can fill water
    if (cur_state.x > EMPTY && cur_state.y < TANK_CAPACITY_Y) {
        result->x = max(cur_state.x - (TANK_CAPACITY_Y - cur_state.y), EMPTY);
        result->y = min(cur_state.x + cur_state.y, TANK_CAPACITY_Y);
        return 1;
    }

    return 0;
}

int pour_water_y_to_x(State cur_state, State* result) {
    // Y -> X
    // X: can fill water ; y has water
    if (cur_state.y > EMPTY && cur_state.x < TANK_CAPACITY_X) {
        // TANK_CAPACITY_X - cur_state.x: số lượng nước có thể đổ thêm
        result->y = max(cur_state.y - (TANK_CAPACITY_X - cur_state.x),
                        EMPTY);  // Tính bình y đổ đi bao nhiêu, -> còn lại trong bình Y bao nhiêu
        result->x =
            min(cur_state.x + cur_state.y, TANK_CAPACITY_X);  // Tính bình x đựng được bao nhiêu
        return 1;
    }

    return 0;
}

// call operations based on state
int call_operations(State cur_state, State* result, int option) {
    switch (option) {
        case 1:
            return pour_water_full_x(cur_state, result);
        case 2:
            return pour_water_full_y(cur_state, result);
        case 3:
            return pour_water_empty_x(cur_state, result);
        case 4:
            return pour_water_empty_y(cur_state, result);
        case 5:
            return pour_water_x_to_y(cur_state, result);
        case 6:
            return pour_water_y_to_x(cur_state, result);
        default:
            cout << "Error calls operators";
            return 0;
    }
}