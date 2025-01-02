/*
We see that an element of the list is a struct with two members (name: string and mark: integer).
So, we can use a pair<string, int> to store them.

Write a C++ program to to following tasks:

Create a list L to store students using list< pair<string, int> > class
Insert 5 students into L in ordered of its occurrence
Print student List in format
Name 1: mark 1
Name 2: mark 2
...
---END---
Insert a new student (Ginny Weasley, 6) at the 2nd position (1-based)
Print the student list
Delete the 3rd element
Print the student list
Read a string s from stdin, print the mark of the student whose name is s to stdout.

Input
Harry Potter

Result
Harry Potter: 10
Hermione Granger: 8
Draco Malfoy: 7
Luna Lovegood: 8
Ron Weasley: 9
---END---
Harry Potter: 10
Gini Weasley: 6
Hermione Granger: 8
Draco Malfoy: 7
Luna Lovegood: 8
Ron Weasley: 9
---END---
Harry Potter: 10
Gini Weasley: 6
Draco Malfoy: 7
Luna Lovegood: 8
Ron Weasley: 9
---END---
*/

#include <iostream>
#include <list>    //to use list class
#include <string>  //to use string class
using namespace std;

typedef struct {
    string name;
    int mark;
} Student;

void print(list<pair<string, int>> L) {
    for (auto x : L) {
        cout << x.first << ": " << x.second;
        cout << endl;
    }
    cout << "---END---\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1. Create a list L to store students using class list< pair<string, int> >
    list<pair<string, int>> L;  // create an empty list to store Students

    // 2. Insert 5 students into L in ordered of its occurrence
    L.push_back(make_pair("Harry Potter", 10));  // append {"Harry Potter", 10} to L
    L.push_back(make_pair("Hermione Granger", 8));
    L.push_back(make_pair("Draco Malfoy", 7));
    L.push_back(make_pair("Luna Lovegood", 8));
    L.push_back(make_pair("Ron Weasley", 9));

    // 3. Print student List
    print(L);

    // 4. Insert a new student (Ginny Weasley, 6) at the 2nd position (1-based)
    auto iter = L.begin();
    iter++;
    L.insert(iter, {"Gini Weasley", 6});
    // 5. Print the student list
    print(L);

    /// 6. Delete the 3rd element
    iter = L.begin();
    iter++;
    iter++;

    L.erase(iter);

    // 7. Print the student list
    print(L);

    // 8. Read a string s from stdin, print the mark of the student whose name is s to stdout.
    string s;
    getline(cin, s);  // read a line and assign to string s
    list<pair<string, int>>::iterator it;
    for (it = L.begin(); it != L.end(); it++)
        if (s == it->first)  // compare two strings
            cout << it->second << endl;

    return 0;
}