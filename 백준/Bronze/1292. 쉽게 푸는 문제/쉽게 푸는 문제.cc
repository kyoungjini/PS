#include <iostream>
using namespace std;

int dp[1001];

int main() {
    int a, b;
    cin >> a >> b;

    int idx = 1;
    int cnt = 1;

    while (cnt <= b) {
        for (int i = 0; i < idx; i++) {
            dp[cnt] = dp[cnt - 1] + idx;
            cnt++;
        }
        idx++;
    }

    cout << dp[b] - dp[a - 1] << "\n";

    return 0;
}