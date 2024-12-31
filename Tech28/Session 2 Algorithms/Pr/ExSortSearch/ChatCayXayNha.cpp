#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> trees, int totalLength, int mid)
{
    // cout << "mid: " << mid << endl;
    // for(auto x: trees){
    //     cout << x << " ";
    // }
    long long total = 0;
    int size = trees.size();
    for (int i = 0; i < size; i++)
    {
        if (mid <= trees[i])
        {
            total += trees[i] - mid;
        }
    }
    if (total >= totalLength)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, L;
    // The total length of the logs can be >= L
    cin >> n >> L;  // number of trees and total length of the logs needed

    vector<int> a(n);  // store the height of the trees

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());      // sort the trees in ascending order
    int l = 0, r = (*a.rbegin());  // l is the minimum height of the tree and r is the maximum height of the tree
    int maxHeight = 0;             // Max height of the tree that can be cut
    while (l <= r)
    {
        int mid = (l + r) / 2;  // binary search on answer
        if (check(a, L, mid))
        {
            maxHeight = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << maxHeight;
}

/*
 input:
 3 6
 1 2 3

 0

 input:
 4 10
 10 15 12 13

 10

 input:
 4 1
 5 5 5 5

 4

 */