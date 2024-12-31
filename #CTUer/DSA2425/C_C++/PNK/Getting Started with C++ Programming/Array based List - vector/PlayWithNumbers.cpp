/*
Write a C++ program to do following tasks:

Create an empty list L to store integer using vector<int> class.
Read n integer from stdin and append them to L
Print elements of L in format: a1, a2, a3
Insert 20 at the 4th position on L
Print elements of L
Delete the 1st element
Print elements of L
Print the position of x (x is read from stdin)

Input
The first line contains an integer n - number of elements
The second line contains n integers - elements to be read and appended to the list
The third line contains an integer x - value to be located

Output
Output of task 3
Output of task 5
Output of task 7
Output of task 8

Input
5
2 4 7 8 3
4

Result
2, 4, 7, 8, 3
2, 4, 7, 20, 8, 3
4, 7, 20, 8, 3
1
*/

#include <iostream>
#include <vector>  //to use vector class
using namespace std;

void print(vector<int> L) {
    for (auto it = L.begin(); it != L.end(); it++) {
        if (it != L.begin()) {
            cout << ", ";
        }
        cout << *it;
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1. Create an empty list L to store integer using vector<int> class.
    vector<int> L;  // create an empty list

    // 2. Read n integer from stdin and append them to L
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        // read an integer and append it to L using push_back() function
        int temp;
        cin >> temp;
        L.push_back(temp);
    }

    // 3. Print elements of L in format: a1, a2, a3
    print(L);

    // 4. Insert 20 at the 4th position on L
    L.insert(L.begin() + 3, 20);

    // 5. Print elements of L
    print(L);

    // 6. Delete the 1st element
    L.erase(L.begin());

    // 7. Print elements of L
    print(L);

    int x;
    cin >> x;
    bool flag = false;
    for (int i = 0; i < L.size(); i++) {
        if (L[i] == x) {
            flag = true;
            x = i;
            break;
        }
    }

    if (flag) {
        cout << x + 1;
    } else{
        cout << L.size() + 1;
    }
    return 0;
}