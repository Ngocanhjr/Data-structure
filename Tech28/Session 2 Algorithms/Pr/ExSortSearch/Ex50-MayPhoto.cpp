#include <bits/stdc++.h>
// #include <algorithm>
// #include <iostream>

using namespace std;

bool check(int n, int x, int y, int time)
{
    int m = min(x, y);
    int totalTime = time - m;
    n -= 1;
    return (totalTime/x + totalTime/y) >=n;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, x, y;
    cin >> n >> x >> y;           // number of customer, production time of machine 1,2
    int minTime = n * min(x, y);  // Minimum time needed
    int l = 0, r = minTime;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(n, x, y, mid))
        {
            minTime = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << minTime;
}

/*

input:
5 1 2

4

*/
