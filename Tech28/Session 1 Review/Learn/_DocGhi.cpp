#include <iostream>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
// tăng tốc độ đọc ghi: đồng bộ với printf và scanf trong c 
//vì printf và scanf tốc độ đọc ghi nhanh hơn cin, cout
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}