#include <iostream>
using namespace std;

int dp[16];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int t, p;
        cin >> t >> p;

        // 이전까지 중 최댓값 파악하기
        int max_val = 0;
        for (int j = 1; j < i + 1; j++) {
            max_val = max(max_val, dp[j]);
        }
      
        if (i + t > n && i == n - 1) {
            dp[n] = max(dp[n], max_val);
        }
        else if (i + t > n) {
            continue;
        }
        else {
            dp[i + t] = max(dp[i + t], max_val + p);
        }
    }
    
    cout << dp[n] << "\n";

    return 0;
}