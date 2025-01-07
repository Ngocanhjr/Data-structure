#include <math.h>

#include <iostream>
#define MAX 1000001  // 0 => 10^6
using namespace std;

// Sàng số nguyên tố tối ưu hơn hàm isPrime
// n <= 10^7
/// O(NloglogN),
bool prime[MAX];
/// @brief
/// @param a
/// @return
// 0(N*can(N))
bool isPrime(int a)
{
    if (a < 2) return false;
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0) return false;
    }
    return true;
}
/// @brief Sàng Eratosthenes: O(NloglogN),

/// @param n
void sang(int n)
{
    for (int i = 0; i <= n; i++)
    {
        prime[i] = true;
    }

    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
}
/// @brief tim ước NT nhỏ I của một số

/// @param n

int p[MAX];

int n = 100;

void sang2()
{
    for (int i = 0; i <= n; i++)
    {
        p[i] = i;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (p[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (p[j] == j)
                {
                    p[j] = i;
                }
            }
        }
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        if (isPrime(i)) cout << i << " ";
    }
    cout << "\n================================\n";
   
   #if 0
    sang(size);
    for (int i = 2; i <= size; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
    #endif
    sang2();
    for (int i = 0; i <= 100; i++)
    {
        cout << i << " " << p[i] << endl;
    }
    return 0;
}