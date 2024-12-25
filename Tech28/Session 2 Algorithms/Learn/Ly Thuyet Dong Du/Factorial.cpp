#include <iostream>

using namespace std;

#define MAX 1000000007
using ll = long long;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    ll factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
        cout << factorial << endl;
    }
    cout << factorial % 1000000007 << endl;

    factorial = 1;
    cout << factorial << endl;
    for (int i = 1; i <= n; i++)
    {
        factorial = ((factorial % MAX) * (i % MAX)) % MAX;
    }
    cout << factorial << endl;

    // Tính (a^b)%c  1<= a,b <=10^6
    cout << "Tính (a^b)%c  1<= a,b <=10^6\n";
    int a, b, c;
    cin >> a >> b >> c;
    ll kq = 1;
    for (int i = 1; i <= b; i++)
    {
        kq *= a;
        kq %= c;
    }
    cout << kq;

/*  input : 100
    2 1000000 10
*/
}