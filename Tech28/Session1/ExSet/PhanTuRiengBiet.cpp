#include <iostream>
#include <set>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int size;
    cin >> size;
    int a[size];
    set<int> s;
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];     
        if(s.find(a[i]) == s.end()){
            cout << a[i] << " ";
        }
        s.insert(a[i]);
    }
}