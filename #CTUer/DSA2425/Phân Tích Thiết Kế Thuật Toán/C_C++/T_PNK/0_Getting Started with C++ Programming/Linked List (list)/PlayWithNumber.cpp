/*
Write a C++ program to do following tasks:

1. Create an empty list L to store integer using list<int> class.
2. Read n integer from stdin and append them to L
3. Print elements of L in format: a1, a2, a3
4. Insert 20 at the 4th position on L
5. Print elements of L
6. Delete the 1st element
7. Print elements of L
8. Print the position of x (x is read from stdin)

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
#include <list>  //to use list class
using namespace std;

void print(list<int> L) {
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

    // 1. Create an empty list L to store integer using list<int> class.
    list<int> L;  // create an empty list

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
    auto it = L.begin();
    advance(it, 3);
    L.insert(it, 20);

    // 5. Print elements of L
    print(L);

    // 6. Delete the 1st element
    L.erase(L.begin());

    // 7. Print elements of L
    print(L);

    // 8.Print the position of x (x is read from stdin)

    int x;
    cin >> x;
    int pos = L.size() + 1;
    for (auto it = L.begin(); it != L.end(); it++) {
        if (*it == x) {
            // flag = true;
            pos = distance(L.begin(), it) + 1;
            break;
        }
    }

    cout << pos;
    // if (flag) {
    //     cout << pos;
    // } else {
    //     cout << L.size() + 1;
    // }
    return 0;
}