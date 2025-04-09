#include <iostream>
#include <vector>

using namespace std;

int maxSubsequence(vector<int>& arr) {
    //Khoi Tao
    int n = arr.size();
    int max_sum = arr[0]; 
    int dp = arr[0];
    
    //Lap
    for (int i = 1; i < n; i++) {
        if (dp + arr[i] > arr[i]) {
            dp = dp + arr[i];  
        } else {
            dp = arr[i];  
        }

        if (dp > max_sum) {
            max_sum = dp;  
        }
    }

    return max_sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxSubsequence(arr) << '\n';
    return 0;
}
