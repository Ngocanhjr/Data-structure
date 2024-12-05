#include <iostream>
#include <vector>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> v;     // empty
    // vector<int> v(n);  // co n phan tu
    // vector<int> v = {1,2,3,4,5};
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    // vector<int>::iterator it = v.begin();
    auto it = v.begin();
    cout << *it << endl;//dereference : giai tham chieu

    //duyet su dung iterator

    for(it = v.begin(); it !=v.end(); it++){
        cout << *it << " ";
    }
}