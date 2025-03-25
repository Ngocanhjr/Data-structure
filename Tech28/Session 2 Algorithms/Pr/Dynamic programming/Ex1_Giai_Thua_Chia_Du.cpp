/*
    Hãy tính N! chia dư cho (10^9 + 7)
*/

#include <iostream>
#include <vector>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

ll f[1000001];// Để trong hàm main là bị tràn bộ nhớ stack


int main()
{
    int T;  // Sô bộ test T

    cin >> T;

    f[0] = 1;
    for (int i = 1; i <= 1000001; i++)
    {
        f[i] = f[i - 1] * i;
        f[i] %= MOD;
    }

    while (T--)
    {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }

#if 0
    while(T--){
        int n; cin >> n;
        
        ll giaiThua = 1;
        for(int i = 1; i <=n; i++){
            giaiThua*=i;
            giaiThua%=MOD;
        }

        cout << giaiThua%MOD << endl;
    }
#endif


}