#include <algorithm>
#include <iostream>
using namespace std;

/// @brief tìm kiếm nhị phân, sort trước khi tìm kiếm
/// @param a input array
/// @param n size of array
/// @param x key need find
/// @return
bool binarySearch(int a[], int n, int x)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == x)
        {
            return true;
        }
        else if (a[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}

// O(logN)
int firstpPos(int a[], int n, int x)
{
    int res = -1;
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == x)
        {
            res = mid;        // update res
            right = mid - 1;  // Find more on the left
        }
        else if (a[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return res;
}

int lastPos(int a[], int n, int x)
{
    int res = -1;
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == x)
        {
            res = mid;
            left = mid + 1;
        }
        else if (a[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return res;
}

/// @brief Find element >= x
/// @param a input array
/// @param n input size of array
/// @param x input key want to find
/// @return Position of element >= x
int lowerBound(int a[], int n, int x)
{
    int res = -1;
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] >= x)
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return res;
}

/// @brief Find element <= x
/// @param a
/// @param n
/// @param x
/// @return
int upperBound(int a[], int n, int x)
{
    int res = -1;
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] <= x)
        {
            res = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int a[] = {1, 3, 6, 78, 9, 66, 45, 9, 9, 9, 9, 9};
    int n = sizeof(a) / sizeof(int);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int x : a)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Size of array: " << n << endl;
    cout << "Enter key u wanna find: ";
    int key;
    cin >> key;
    if (binarySearch(a, n, key))
    {
        cout << "Founded!\n";
    }
    else
    {
        cout << "Not founded!\n";
    }
    // cout << "############################################\n";
    int firstP = firstpPos(a, n, key);
    if (firstP >= 0)
    {
        cout << "First pos of " << key << " : " << firstP << endl;
    }
    else
    {
        cout << "!> Not found first position of " << key << endl;
    }
    int lastP = lastPos(a, n, key);
    if (lastP >= 0)
    {
        cout << "Last pos of " << key << " : " << lastP << endl;
    }
    else
    {
        cout << "!> Not found last position of " << key << endl;
    }

    int lb = lowerBound(a, n, key);
    if (lb >= 0)
    {
        cout << "Lower bound of " << key << " : " << lb << endl;
        cout << "Value of lower bound: " << a[lb] << endl;  // a[lb] >= key
    }
    else
    {
        cout << "!> Not found lower bound of " << key << endl;
    }
}