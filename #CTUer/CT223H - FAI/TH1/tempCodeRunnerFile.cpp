#include "B2303861.cpp"

int main() {
// Exercise 1
#if 1
    cout << "Enter current state of X và Y: ";
    int cur_x, cur_y;
    cin >> cur_x >> cur_y;
    State cur_state = {cur_x, cur_y}, result;
    make_null_state(&result);

    cout << "Initial state: \n";
    print_state(cur_state);