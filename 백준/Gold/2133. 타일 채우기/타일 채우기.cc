#include <iostream>
using namespace std;

int main() {
    int n;
    int dp[31] = {0,};
    
    cin >> n;

    dp[2] = 3;

    for (int i = 3; i <= n; i++) {
        if (i % 2 != 0) continue;

        for (int j = i - 2; j > 0; j -= 2) {
            if (j == i - 2) dp[i] += (dp[j] * 3);
            else dp[i] += (dp[j] * 2);
        }

        dp[i] += 2;
    }

    cout << dp[n] << "\n";

    return 0;
}