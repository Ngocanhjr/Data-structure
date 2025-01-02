/*
Write a C++ program to to following tasks:

1. Define a structure Student to store basic informations of a student:
name: string
mark: integer
2. Create a list L to store students using list<Student> class
3. Insert 5 students into L in ordered of its occurrence
4. Print student List in format
Name 1: mark 1
Name 2: mark 2
...
---END---
5. Insert a new student (Ginny Weasley, 6) at the 2nd position (1-based)
6. Print the student list
7. Delete the 3rd element
8. Print the student list
9. Read a string s from stdin, print the mark of the student whose name is s to stdout.

Input
A single line containing the name of the student to be located.

Output
Output of task 3
Output of task 5
Output of task 7
Mark of student s

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
10
*/
#include <iostream>
#include <list>    //to use list class
#include <string>  //to use string class
using namespace std;

// 1. Define a structure Student to store basic informations of a student:
//   name: string
//   mark: integer
typedef struct {
    string name;
    int mark;
} Student;

void print(list<Student> L) {
    for (auto x : L) {
        cout << x.name << ": " << x.mark;
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

    // 2Create a list L to store students using list<Student> class
    list<Student> L;  // create an empty list to store Students

    // 3. Insert 5 students into L in ordered of its occurrence
    Student harry;
    harry.name = "Harry Potter";
    harry.mark = 10;
    L.push_back(harry);  // append {"Harry Potter", 10} to L

    Student hermione = {"Hermione Granger", 8};
    L.push_back(hermione);

    L.push_back({"Draco Malfoy", 7});
    L.push_back({"Luna Lovegood", 8});
    L.push_back({"Ron Weasley", 9});

    // 4. Print student List in format
    print(L);

    // 5. Insert a new student (Ginny Weasley, 6) at the 2nd position (1-based)
    auto iter = L.begin();
    iter++;
    L.insert(iter, {"Gini Weasley", 6});

    // 6. Print the student list
    print(L);

    /// 7. Delete the 3rd element
     iter = L.begin();
    iter++;
    iter++;
    L.erase(iter);

    // 8. Print the student list
    print(L);

    // 9. Read a string s from stdin, print the mark of the student whose name is s to stdout.
    string s;
    getline(cin, s);  // read a line and assign to string s
    list<Student>::iterator it;
    for (it = L.begin(); it != L.end(); it++)
        if (s == it->name)  // compare two strings
            cout << it->mark << endl;

    return 0;
}
