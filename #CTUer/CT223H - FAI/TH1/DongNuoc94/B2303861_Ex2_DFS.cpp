//Draw the graph using DFS algorithm
#include "B2303861_Functions.cpp"
#include <stack>

int main(){
    cout << "Enter initial state of X và Y: ";
    int cur_x, cur_y;
    cin >> cur_x >> cur_y;
    if (cur_x > TANK_CAPACITY_X || cur_y > TANK_CAPACITY_Y){
        cout << "Water must be under tank capacity!";
        return 0;
    }
}