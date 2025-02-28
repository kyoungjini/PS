#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> v;

    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        v.push_back(p);
    }

    // 내림차순 정렬
    sort(v.rbegin(), v.rend());

    int res_price = 0;
    int res_profit = 0;

    for (int i = 0; i < v.size(); i++) {
        if (i + 1 > n) break;

        int tmp_profit = v[i] * (i + 1);

        if (tmp_profit > res_profit) {
            res_profit = tmp_profit;
            res_price = v[i];
        }
    }

    cout << res_price << " " << res_profit << "\n";

    return 0;
}