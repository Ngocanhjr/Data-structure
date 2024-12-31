#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("../input.txt", "r", stdin);
//     freopen("../output.txt", "w", stdout);
// #endif

    int n;
    cin >> n;  // number of customer

#if 0
    vector<pair<int, int>> timeline;  // store time come and time out of customer
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        timeline.push_back({a, 1});  // time come
        timeline.push_back({b, -1}); // time out
    }

    for(auto p : timeline)
    {
        cout << p.first << " " << p.second << endl;

    }
#endif

#if 1
    multimap<int, int> timeline;  // store time come and time out of customer
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        timeline.insert({a, 1});   // time come
        timeline.insert({b, -1});  // time out
    }
    // for (auto p : timeline)
    // {
    //     cout << p.first << " " << p.second << endl;
    // }
#endif

    long long maxCustomer = 0;
    long long currentCustomer = 0;
    for (auto p : timeline)
    {
        currentCustomer += p.second;
       maxCustomer = currentCustomer > maxCustomer ? currentCustomer : maxCustomer;
    }
    cout << maxCustomer << endl;
}
/*
input:
3
5 8
2 4
3 9
output: 2, max of customer in shop at the same time

input:
4
1 10
2 4
3 5
7 9
output: 3

*/
#if 0
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    vector<pair<int, int>> events;

    // Nhập dữ liệu và tạo danh sách sự kiện
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 1});  // Thời điểm đến (+1)
        events.push_back({b, -1}); // Thời điểm rời đi (-1)
    }

    // Sắp xếp danh sách sự kiện
    // Sắp theo thời gian tăng dần, nếu thời gian bằng nhau thì ưu tiên sự kiện -1 trước +1
    sort(events.begin(), events.end(), [](const pair<int, int>& e1, const pair<int, int>& e2) {
        if (e1.first == e2.first)
            return e1.second < e2.second;
        return e1.first < e2.first;
    });

    // Tính số khách hàng tối đa tại cửa hàng
    int current_customers = 0; // Số khách hàng tại thời điểm hiện tại
    int max_customers = 0;     // Số khách hàng tối đa

    for (const auto& event : events) {
        current_customers += event.second;       // Cập nhật số khách hàng
        max_customers = max(max_customers, current_customers); // Cập nhật giá trị lớn nhất
    }

    // In kết quả
    cout << max_customers << endl;

    return 0;
}
#endif