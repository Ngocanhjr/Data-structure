#include <algorithm>
#include <iostream>

using namespace std;

bool check(int a[], int n, int t, long long time){
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += time/a[i]; //Number of products in time
    }
    if(ans >= t){ //check number of products produced with provided products
        return true;
    } else {
        return false;
    }
}

// Binary search on answer
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, t;
    cin >> n >> t;  /// Number of machines and products

    int a[n];  // Store time of machines

    for (int &x : a)
    {
        cin >> x;
    }

    int res = -1;
    long long l = 0, r = (*min_element(a, a + n)) * t; //min and max time to produce t products
    while(l <= r){
        long long mid = (l + r)/2; //mid is the time
        if(check(a, n, t, mid)){
            res = mid;
            r = mid - 1;
        } else{
            l = mid + 1;
        }
    }
    cout << res << endl;
    // output: 8, min time to produce t products
}