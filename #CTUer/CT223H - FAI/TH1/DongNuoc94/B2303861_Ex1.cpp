// Exercise 1 Update: 22-05-2026
#include "B2303861_Functions.cpp"

int main() {
    cout << "Enter initial state of X và Y: ";
    int cur_x, cur_y;
    cin >> cur_x >> cur_y;
    if (cur_x > TANK_CAPACITY_X || cur_y > TANK_CAPACITY_Y){
        cout << "Water must be under tank capacity!";
        return 0;
    }

    State cur_state = {cur_x, cur_y}, result;
    make_null_state(&result);

    cout << "Initial state: \n";
    print_state(cur_state);

    // Check if curent state is goal state
    if (goal_check(cur_state)) {
        cout << "Goal!" << endl;
        return 0;
    }

    // Call operations
    for (int opt = 1; opt <= NUM_ACTIONS; opt++) {
        int isSuccess = call_operations(cur_state, &result, opt);
        if (isSuccess == 1) {
            cout << "Success action: " << action[opt] << endl;
            print_state(result);
        } else {
            cout << "<Error action: " << action[opt] << "!>"<< endl;
        }
    }
}