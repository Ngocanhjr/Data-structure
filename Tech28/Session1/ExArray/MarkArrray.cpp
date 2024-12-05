#include <iostream>

using namespace std;

#define MAX 1000001

int cnt[MAX];  /// 0 => 10^6

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
    {
        cin >> x;
    }

    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
    }

    int countNumber = 0;
    cout << "Number and frequency: " << endl;
    for (int i = 0; i < MAX; i++)
    {
        if (cnt[i]!=0)
        {
            cout << i << ' ' << cnt[i] << endl;
            ++countNumber;
        }
    }
    cout << "Number of different number: " << countNumber;
}